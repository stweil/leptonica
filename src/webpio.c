/*====================================================================*
 -  Copyright (C) 2001 Leptonica.  All rights reserved.
 -
 -  Redistribution and use in source and binary forms, with or without
 -  modification, are permitted provided that the following conditions
 -  are met:
 -  1. Redistributions of source code must retain the above copyright
 -     notice, this list of conditions and the following disclaimer.
 -  2. Redistributions in binary form must reproduce the above
 -     copyright notice, this list of conditions and the following
 -     disclaimer in the documentation and/or other materials
 -     provided with the distribution.
 -
 -  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 -  ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 -  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 -  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL ANY
 -  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 -  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 -  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 -  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 -  OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 -  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 -  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *====================================================================*/

/*!
 * \file webpio.c
 * <pre>
 *
 *    Reading WebP
 *          PIX             *pixReadStreamWebP()
 *          PIX             *pixReadMemWebP()
 *
 *    Reading WebP header
 *          int32_t          readHeaderWebP()
 *          int32_t          readHeaderMemWebP()
 *
 *    Writing WebP
 *          int32_t          pixWriteWebP()  [ special top level ]
 *          int32_t          pixWriteStreamWebP()
 *          int32_t          pixWriteMemWebP()
 * </pre>
 */

#ifdef HAVE_CONFIG_H
#include <config_auto.h>
#endif  /* HAVE_CONFIG_H */

#include "allheaders.h"

/* --------------------------------------------*/
#if  HAVE_LIBWEBP   /* defined in environ.h */
/* --------------------------------------------*/
#include "webp/decode.h"
#include "webp/encode.h"

/*---------------------------------------------------------------------*
 *                             Reading WebP                            *
 *---------------------------------------------------------------------*/
/*!
 * \brief   pixReadStreamWebP()
 *
 * \param[in]    fp    file stream corresponding to WebP image
 * \return  pix 32 bpp, or NULL on error
 */
PIX *
pixReadStreamWebP(FILE  *fp)
{
uint8_t  *filedata;
size_t    filesize;
PIX      *pix;

    if (!fp)
        return (PIX *)ERROR_PTR("fp not defined", __func__, NULL);

        /* Read data from file and decode into Y,U,V arrays */
    rewind(fp);
    if ((filedata = l_binaryReadStream(fp, &filesize)) == NULL)
        return (PIX *)ERROR_PTR("filedata not read", __func__, NULL);

    pix = pixReadMemWebP(filedata, filesize);
    LEPT_FREE(filedata);
    return pix;
}


/*!
 * \brief   pixReadMemWebP()
 *
 * \param[in]  filedata    webp compressed data in memory
 * \param[in]  filesize    number of bytes in data
 * \return  pix 32 bpp, or NULL on error
 *
 * <pre>
 * Notes:
 *      (1) When the encoded data only has 3 channels (no alpha),
 *          WebPDecodeRGBAInto() generates a raster of 32-bit pixels, with
 *          the alpha channel set to opaque (255).
 *      (2) We don't need to use the gnu runtime functions like fmemopen()
 *          for redirecting data from a stream to memory, because
 *          the webp library has been written with memory-to-memory
 *          functions at the lowest level (which is good!).  And, in
 *          any event, fmemopen() doesn't work with l_binaryReadStream().
 * </pre>
 */
PIX *
pixReadMemWebP(const uint8_t  *filedata,
               size_t          filesize)
{
uint8_t   *out = NULL;
int32_t    w, h, has_alpha, wpl, stride;
uint32_t  *data;
size_t     size;
PIX       *pix;
WebPBitstreamFeatures  features;

    if (!filedata)
        return (PIX *)ERROR_PTR("filedata not defined", __func__, NULL);

    if (WebPGetFeatures(filedata, filesize, &features))
        return (PIX *)ERROR_PTR("Invalid WebP file", __func__, NULL);
    w = features.width;
    h = features.height;
    has_alpha = features.has_alpha;

        /* Write from compressed Y,U,V arrays to pix raster data */
    pix = pixCreate(w, h, 32);
    pixSetInputFormat(pix, IFF_WEBP);
    if (has_alpha) pixSetSpp(pix, 4);
    data = pixGetData(pix);
    wpl = pixGetWpl(pix);
    stride = wpl * 4;
    size = (size_t)stride * h;
    out = WebPDecodeRGBAInto(filedata, filesize, (uint8_t *)data, size,
                             stride);
    if (out == NULL) {  /* error: out should also point to data */
        pixDestroy(&pix);
        return (PIX *)ERROR_PTR("WebP decode failed", __func__, NULL);
    }

        /* The WebP API expects data in RGBA order.  The pix stores
         * in host-dependent order with R as the MSB and A as the LSB.
         * On little-endian machines, the bytes in the word must
         * be swapped; e.g., R goes from byte 0 (LSB) to byte 3 (MSB).
         * No swapping is necessary for big-endians. */
    pixEndianByteSwap(pix);
    return pix;
}


/*!
 * \brief   readHeaderWebP()
 *
 * \param[in]   filename
 * \param[out]  pw        width
 * \param[out]  ph        height
 * \param[out]  pspp      spp (3 or 4)
 * \return  0 if OK, 1 on error
 */
l_ok
readHeaderWebP(const char *filename,
               int32_t    *pw,
               int32_t    *ph,
               int32_t    *pspp)
{
uint8_t  data[100];  /* expect size info within the first 50 bytes or so */
int32_t  nbytes, bytesread;
size_t   filesize;
FILE    *fp;

    if (!pw || !ph || !pspp)
        return ERROR_INT("input ptr(s) not defined", __func__, 1);
    *pw = *ph = *pspp = 0;
    if (!filename)
        return ERROR_INT("filename not defined", __func__, 1);

        /* Read no more than 100 bytes from the file */
    if ((filesize = nbytesInFile(filename)) == 0)
        return ERROR_INT("no file size found", __func__, 1);
    if (filesize < 100)
        L_WARNING("very small webp file\n", __func__);
    nbytes = L_MIN(filesize, 100);
    if ((fp = fopenReadStream(filename)) == NULL)
        return ERROR_INT("image file not found", __func__, 1);
    bytesread = fread(data, 1, nbytes, fp);
    fclose(fp);
    if (bytesread != nbytes)
        return ERROR_INT("failed to read requested data", __func__, 1);

    return readHeaderMemWebP(data, nbytes, pw, ph, pspp);
}


/*!
 * \brief   readHeaderMemWebP()
 *
 * \param[in]    data
 * \param[in]    size    100 bytes is sufficient
 * \param[out]   pw      width
 * \param[out]   ph      height
 * \param[out]   pspp    spp (3 or 4)
 * \return  0 if OK, 1 on error
 */
l_ok
readHeaderMemWebP(const uint8_t  *data,
                  size_t          size,
                  int32_t        *pw,
                  int32_t        *ph,
                  int32_t        *pspp)
{
WebPBitstreamFeatures  features;

    if (pw) *pw = 0;
    if (ph) *ph = 0;
    if (pspp) *pspp = 0;
    if (!data)
        return ERROR_INT("data not defined", __func__, 1);
    if (!pw || !ph || !pspp)
        return ERROR_INT("input ptr(s) not defined", __func__, 1);

    if (WebPGetFeatures(data, (int32_t)size, &features))
        return ERROR_INT("invalid WebP file", __func__, 1);
    *pw = features.width;
    *ph = features.height;
    *pspp = (features.has_alpha) ? 4 : 3;
    return 0;
}


/*---------------------------------------------------------------------*
 *                            Writing WebP                             *
 *---------------------------------------------------------------------*/
/*!
 * \brief   pixWriteWebP()
 *
 * \param[in]   filename
 * \param[in]   pixs
 * \param[in]   quality    0 - 100; default ~80
 * \param[in]   lossless   use 1 for lossless; 0 for lossy
 * \return  0 if OK, 1 on error
 *
 * <pre>
 * Notes:
 *      (1) Special top-level function allowing specification of quality.
 * </pre>
 */
l_ok
pixWriteWebP(const char  *filename,
             PIX         *pixs,
             int32_t      quality,
             int32_t      lossless)
{
int32_t  ret;
FILE    *fp;

    if (!pixs)
        return ERROR_INT("pixs not defined", __func__, 1);
    if (!filename)
        return ERROR_INT("filename not defined", __func__, 1);

    if ((fp = fopenWriteStream(filename, "wb+")) == NULL)
        return ERROR_INT("stream not opened", __func__, 1);
    ret = pixWriteStreamWebP(fp, pixs, quality, lossless);
    fclose(fp);
    if (ret)
        return ERROR_INT("pixs not compressed to stream", __func__, 1);
    return 0;
}


/*!
 * \brief   pixWriteStreampWebP()
 *
 * \param[in]   fp file stream
 * \param[in]   pixs      all depths
 * \param[in]   quality   0 - 100; default ~80
 * \param[in]   lossless  use 1 for lossless; 0 for lossy
 * \return  0 if OK, 1 on error
 *
 * <pre>
 * Notes:
 *      (1) See pixWriteMemWebP() for details.
 *      (2) Use 'free', and not leptonica's 'LEPT_FREE', for all heap data
 *          that is returned from the WebP library.
 * </pre>
 */
l_ok
pixWriteStreamWebP(FILE    *fp,
                   PIX     *pixs,
                   int32_t  quality,
                   int32_t  lossless)
{
uint8_t  *filedata;
size_t    filebytes, nbytes;

    if (!fp)
        return ERROR_INT("stream not open", __func__, 1);
    if (!pixs)
        return ERROR_INT("pixs not defined", __func__, 1);

    pixSetPadBits(pixs, 0);
    pixWriteMemWebP(&filedata, &filebytes, pixs, quality, lossless);
    rewind(fp);
    nbytes = fwrite(filedata, 1, filebytes, fp);
    free(filedata);
    if (nbytes != filebytes)
        return ERROR_INT("Write error", __func__, 1);
    return 0;
}


/*!
 * \brief   pixWriteMemWebP()
 *
 * \param[out]   pencdata   webp encoded data of pixs
 * \param[out]   pencsize   size of webp encoded data
 * \param[in]    pixs       any depth, cmapped OK
 * \param[in]    quality    0 - 100; default ~80
 * \param[in]    lossless   use 1 for lossless; 0 for lossy
 * \return  0 if OK, 1 on error
 *
 * <pre>
 * Notes:
 *      (1) Lossless and lossy encoding are entirely different in webp.
 *          %quality applies to lossy, and is ignored for lossless.
 *      (2) The input image is converted to RGB if necessary.  If spp == 3,
 *          we set the alpha channel to fully opaque (255), and
 *          WebPEncodeRGBA() then removes the alpha chunk when encoding,
 *          setting the internal header field has_alpha to 0.
 * </pre>
 */
l_ok
pixWriteMemWebP(uint8_t  **pencdata,
                size_t    *pencsize,
                PIX       *pixs,
                int32_t    quality,
                int32_t    lossless)
{
int32_t    w, h, d, wpl, stride;
uint32_t  *data;
PIX       *pix1, *pix2;

    if (!pencdata)
        return ERROR_INT("&encdata not defined", __func__, 1);
    *pencdata = NULL;
    if (!pencsize)
        return ERROR_INT("&encsize not defined", __func__, 1);
    *pencsize = 0;
    if (!pixs)
        return ERROR_INT("&pixs not defined", __func__, 1);
    if (lossless == 0 && (quality < 0 || quality > 100))
        return ERROR_INT("quality not in [0 ... 100]", __func__, 1);

    if ((pix1 = pixRemoveColormap(pixs, REMOVE_CMAP_TO_FULL_COLOR)) == NULL)
        return ERROR_INT("failure to remove color map", __func__, 1);

        /* Convert to rgb if not 32 bpp; pix2 must not be a clone of pixs. */
    if (pixGetDepth(pix1) != 32)
        pix2 = pixConvertTo32(pix1);
    else
        pix2 = pixCopy(NULL, pix1);
    pixDestroy(&pix1);
    pixGetDimensions(pix2, &w, &h, &d);
    if (w <= 0 || h <= 0 || d != 32) {
        pixDestroy(&pix2);
        return ERROR_INT("pix2 not 32 bpp or of 0 size", __func__, 1);
    }

        /* If spp == 3, need to set alpha layer to opaque (all 1s). */
    if (pixGetSpp(pix2) == 3)
        pixSetComponentArbitrary(pix2, L_ALPHA_CHANNEL, 255);

        /* The WebP API expects data in RGBA order.  The pix stores
         * in host-dependent order with R as the MSB and A as the LSB.
         * On little-endian machines, the bytes in the word must
         * be swapped; e.g., R goes from byte 0 (LSB) to byte 3 (MSB).
         * No swapping is necessary for big-endians. */
    pixEndianByteSwap(pix2);
    wpl = pixGetWpl(pix2);
    data = pixGetData(pix2);
    stride = wpl * 4;
    if (lossless) {
        *pencsize = WebPEncodeLosslessRGBA((uint8_t *)data, w, h,
                                           stride, pencdata);
    } else {
        *pencsize = WebPEncodeRGBA((uint8_t *)data, w, h, stride,
                                   quality, pencdata);
    }
    pixDestroy(&pix2);

    if (*pencsize == 0) {
        free(*pencdata);
        *pencdata = NULL;
        return ERROR_INT("webp encoding failed", __func__, 1);
    }

    return 0;
}

/* --------------------------------------------*/
#endif  /* HAVE_LIBWEBP */
/* --------------------------------------------*/
