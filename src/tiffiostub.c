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
 * \file tiffiostub.c
 * <pre>
 *
 *     Stubs for tiffio.c functions
 * </pre>
 */

#ifdef HAVE_CONFIG_H
#include <config_auto.h>
#endif  /* HAVE_CONFIG_H */

#include "allheaders.h"

/* --------------------------------------------*/
#if  !HAVE_LIBTIFF   /* defined in environ.h */
/* --------------------------------------------*/

PIX * pixReadTiff(const char *filename, int32_t n)
{
    return (PIX *)ERROR_PTR("function not present", __func__, NULL);
}

/* ----------------------------------------------------------------------*/

PIX * pixReadStreamTiff(FILE *fp, int32_t n)
{
    return (PIX *)ERROR_PTR("function not present", __func__, NULL);
}

/* ----------------------------------------------------------------------*/

l_ok pixWriteTiff(const char *filename, PIX *pix, int32_t comptype,
                  const char *modestring)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok pixWriteTiffCustom(const char *filename, PIX *pix, int32_t comptype,
                        const char *modestring, NUMA *natags,
                        SARRAY *savals, SARRAY *satypes, NUMA *nasizes)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok pixWriteStreamTiff(FILE *fp, PIX *pix, int32_t comptype)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok pixWriteStreamTiffWA(FILE *fp, PIX *pix, int32_t comptype,
                          const char *modestr)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

PIX * pixReadFromMultipageTiff(const char *filename, size_t *poffset)
{
    return (PIX *)ERROR_PTR("function not present", __func__, NULL);
}

/* ----------------------------------------------------------------------*/

PIXA * pixaReadMultipageTiff(const char *filename)
{
    return (PIXA *)ERROR_PTR("function not present", __func__, NULL);
}

/* ----------------------------------------------------------------------*/

l_ok pixaWriteMultipageTiff(const char *filename, PIXA *pixa)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok writeMultipageTiff(const char *dirin, const char *substr,
                        const char *fileout)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok writeMultipageTiffSA(SARRAY *sa, const char *fileout)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok fprintTiffInfo(FILE *fpout, const char *tiffile)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok tiffGetCount(FILE *fp, int32_t *pn)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok getTiffResolution(FILE *fp, int32_t *pxres, int32_t *pyres)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok readHeaderTiff(const char *filename, int32_t n, int32_t *pwidth,
                    int32_t *pheight, int32_t *pbps, int32_t *pspp,
                    int32_t *pres, int32_t *pcmap, int32_t *pformat)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok freadHeaderTiff(FILE *fp, int32_t n, int32_t *pwidth,
                     int32_t *pheight, int32_t *pbps, int32_t *pspp,
                     int32_t *pres, int32_t *pcmap, int32_t *pformat)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok readHeaderMemTiff(const uint8_t *cdata, size_t size, int32_t n,
                       int32_t *pwidth, int32_t *pheight, int32_t *pbps,
                       int32_t *pspp, int32_t *pres, int32_t *pcmap,
                       int32_t *pformat)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok findTiffCompression(FILE *fp, int32_t *pcomptype)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok extractG4DataFromFile(const char *filein, uint8_t **pdata,
                           size_t *pnbytes, int32_t *pw,
                           int32_t *ph, int32_t *pminisblack)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

PIX * pixReadMemTiff(const uint8_t *cdata, size_t size, int32_t n)
{
    return (PIX *)ERROR_PTR("function not present", __func__, NULL);
}

/* ----------------------------------------------------------------------*/

PIX * pixReadMemFromMultipageTiff(const uint8_t *cdata, size_t size,
                                  size_t *poffset)
{
    return (PIX *)ERROR_PTR("function not present", __func__, NULL);
}

/* ----------------------------------------------------------------------*/

PIXA * pixaReadMemMultipageTiff(const uint8_t *data, size_t size)
{
    return (PIXA *)ERROR_PTR("function not present", __func__, NULL);
}

/* ----------------------------------------------------------------------*/

l_ok pixaWriteMemMultipageTiff(uint8_t **pdata, size_t *psize, PIXA *pixa)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok pixWriteMemTiff(uint8_t **pdata, size_t *psize, PIX *pix,
                        int32_t comptype)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok pixWriteMemTiffCustom(uint8_t **pdata, size_t *psize, PIX *pix,
                           int32_t comptype, NUMA *natags, SARRAY *savals,
                           SARRAY *satypes, NUMA *nasizes)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* --------------------------------------------*/
#endif  /* !HAVE_LIBTIFF */
/* --------------------------------------------*/
