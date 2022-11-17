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
 * \file psio1stub.c
 * <pre>
 *
 *     Stubs for psio1.c functions
 * </pre>
 */

#ifdef HAVE_CONFIG_H
#include <config_auto.h>
#endif  /* HAVE_CONFIG_H */

#include "allheaders.h"

/* --------------------------------------------*/
#if  !USE_PSIO   /* defined in environ.h */
/* --------------------------------------------*/

l_ok convertFilesToPS(const char *dirin, const char *substr,
                      int32_t res, const char *fileout)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok sarrayConvertFilesToPS(SARRAY *sa, int32_t res, const char *fileout)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok convertFilesFittedToPS(const char *dirin, const char *substr,
                            l_float32 xpts, l_float32 ypts,
                            const char *fileout)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok sarrayConvertFilesFittedToPS(SARRAY *sa, l_float32 xpts,
                                  l_float32 ypts, const char *fileout)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok writeImageCompressedToPSFile(const char *filein, const char *fileout,
                                  int32_t res, int32_t *pindex)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok convertSegmentedPagesToPS(const char *pagedir, const char *pagestr,
                               int32_t page_numpre, const char *maskdir,
                               const char *maskstr, int32_t mask_numpre,
                               int32_t numpost, int32_t maxnum,
                               l_float32 textscale, l_float32 imagescale,
                               int32_t threshold, const char *fileout)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok pixWriteSegmentedPageToPS(PIX *pixs, PIX *pixm, l_float32 textscale,
                               l_float32 imagescale, int32_t threshold,
                               int32_t pageno, const char *fileout)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok pixWriteMixedToPS(PIX *pixb, PIX *pixc, l_float32 scale,
                       int32_t pageno, const char *fileout)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok convertToPSEmbed(const char *filein, const char *fileout, int32_t level)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok pixaWriteCompressedToPS(PIXA *pixa, const char *fileout,
                             int32_t res, int32_t level)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok pixWriteCompressedToPS(PIX *pix, const char *fileout, int32_t res,
                            int32_t level, int32_t *pindex)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* --------------------------------------------*/
#endif  /* !USE_PSIO */
/* --------------------------------------------*/
