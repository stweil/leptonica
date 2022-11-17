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

#ifndef  LEPTONICA_BMP_H
#define  LEPTONICA_BMP_H

/*!
 * \file bmp.h
 *
 * <pre>
 * This file is here to describe the fields in the header of
 * the BMP file.  These fields are not used directly in Leptonica.
 * The only thing we use are the sizes of these two headers.
 * Furthermore, because of potential namespace conflicts with
 * the typedefs and defined sizes, we have changed the names
 * to protect anyone who may also need to use the original definitions.
 * Thanks to J. D. Bryan for pointing out the potential problems when
 * developing on Win32 compatible systems.
 * </pre>
 */

/*-------------------------------------------------------------*
 *                       BMP file header                       *
 *-------------------------------------------------------------*/

/*! BMP file header
 *
 * Notes:
 *  (1) The bfSize field is stored as a 32 bit integer and includes
 *      the size of the BMP_FileHeader, BMP_InfoHeader, the color
 *      table (if any), and the size of the DIB bits.
 *  (2) The bfOffBits field is also stored as a 32 bit integer and
 *      contains the absolute offset in bytes of the image data
 *      in this file. Some bmp files have additional data after the
 *      BMP_InfoHeader and before the color table (if it exists).
 *      However, enabling reading of these files makes the reader
 *      vulnerable to various malware attacks.  Therefore we do not
 *      read bmp files with extra data, and require that the size
 *      of the color table in bytes is
 *         offset - sizeof(BMP_FileHeader) - sizeof(BMP_InfoHeader)
 *  (3) Use arrays of uint8_t[] to make an endianness agnostic
 *      access to the BMP_FileHeader easier.
 */
struct BMP_FileHeader
{
    uint8_t        bfType[2];      /*!< file type; must be "BM"            */
    uint8_t        bfSize[4];      /*!< length of the file;
                                       sizeof(BMP_FileHeader) +
                                       sizeof(BMP_InfoHeader) +
                                       size of optional extra data +
                                       size of color table +
                                       size of DIB bits                    */
    uint8_t        bfReserved1[2]; /*!< don't care (set to 0)              */
    uint8_t        bfReserved2[2]; /*!< don't care (set to 0)              */
    uint8_t        bfOffBits[4];   /*!< offset from beginning of file      */
};
typedef struct BMP_FileHeader  BMP_FH;

/*! Number of bytes in a BMP file header */
#define BMP_FHBYTES  sizeof(BMP_FH)


/*-------------------------------------------------------------*
 *                       BMP info header                       *
 *-------------------------------------------------------------*/

/*! BMP info header */
struct BMP_InfoHeader
{
    int32_t        biSize;          /*!< size of the BMP_InfoHeader struct   */
    int32_t        biWidth;         /*!< bitmap width in pixels              */
    int32_t        biHeight;        /*!< bitmap height in pixels             */
    int16_t        biPlanes;        /*!< number of bitmap planes             */
    int16_t        biBitCount;      /*!< number of bits per pixel            */
    int32_t        biCompression;   /*!< compress format (0 == uncompressed) */
    int32_t        biSizeImage;     /*!< size of image in bytes              */
    int32_t        biXPelsPerMeter; /*!< pixels per meter in x direction     */
    int32_t        biYPelsPerMeter; /*!< pixels per meter in y direction     */
    int32_t        biClrUsed;       /*!< number of colors used               */
    int32_t        biClrImportant;  /*!< number of important colors used     */
};
typedef struct BMP_InfoHeader  BMP_IH;

/*! Number of bytes in a BMP info header */
#define BMP_IHBYTES  sizeof(BMP_IH)


/*-------------------------------------------------------------*
 *           Align BMP headers on 4 byte boundaries            *
 *-------------------------------------------------------------*/

/*! BMP_IH is misaligned, causing crashes on some big-endians.
 *  A packed struct forces alignment. */
#if defined(__GNUC__)
typedef struct __attribute__((__packed__)) {
  BMP_FH bmpfh;
  BMP_IH bmpih;
} BMP_HEADER;
#endif

#endif  /* LEPTONICA_BMP_H */
