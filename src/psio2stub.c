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
 * \file psio2stub.c
 * <pre>
 *
 *     Stubs for psio2.c functions
 * </pre>
 */

#ifdef HAVE_CONFIG_H
#include <config_auto.h>
#endif  /* HAVE_CONFIG_H */

#include "allheaders.h"

/* --------------------------------------------*/
#if  !USE_PSIO   /* defined in environ.h */
/* --------------------------------------------*/

l_ok pixWritePSEmbed(const char *filein, const char *fileout)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok pixWriteStreamPS(FILE *fp, PIX *pix, BOX *box, int32_t res,
                         l_float32 scale)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

char * pixWriteStringPS(PIX *pixs, BOX *box, int32_t res, l_float32 scale)
{
    return (char *)ERROR_PTR("function not present", __func__, NULL);
}

/* ----------------------------------------------------------------------*/

char * generateUncompressedPS(char *hexdata, int32_t w, int32_t h, int32_t d,
                              int32_t psbpl, int32_t bps, l_float32 xpt,
                              l_float32 ypt, l_float32 wpt, l_float32 hpt,
                              int32_t boxflag)
{
    return (char *)ERROR_PTR("function not present", __func__, NULL);
}

/* ----------------------------------------------------------------------*/

l_ok convertJpegToPSEmbed(const char *filein, const char *fileout)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok convertJpegToPS(const char *filein, const char *fileout,
                     const char *operation, int32_t x, int32_t y,
                     int32_t res, l_float32 scale, int32_t pageno,
                     int32_t endpage)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok convertG4ToPSEmbed(const char *filein, const char *fileout)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok convertG4ToPS(const char *filein, const char *fileout,
                   const char *operation, int32_t x, int32_t y,
                   int32_t res, l_float32 scale, int32_t pageno,
                   int32_t maskflag, int32_t endpage)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok convertTiffMultipageToPS(const char *filein, const char *fileout,
                              l_float32 fillfract)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok convertFlateToPSEmbed(const char *filein, const char *fileout)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok convertFlateToPS(const char *filein, const char *fileout,
                      const char *operation, int32_t x, int32_t y,
                      int32_t res, l_float32 scale, int32_t pageno,
                      int32_t endpage)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok pixWriteMemPS(uint8_t **pdata, size_t *psize, PIX *pix, BOX *box,
                   int32_t res, l_float32 scale)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

int32_t getResLetterPage(int32_t w, int32_t h, l_float32 fillfract)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

void l_psWriteBoundingBox(int32_t flag)
{
    L_ERROR("function not present\n", __func__);
    return;
}

/* --------------------------------------------*/
#endif  /* !USE_PSIO */
/* --------------------------------------------*/
