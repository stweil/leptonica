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
 * \file jpegiostub.c
 * <pre>
 *
 *     Stubs for jpegio.c functions
 * </pre>
 */

#ifdef HAVE_CONFIG_H
#include <config_auto.h>
#endif  /* HAVE_CONFIG_H */

#include "allheaders.h"

/* --------------------------------------------*/
#if  !HAVE_LIBJPEG   /* defined in environ.h */
/* --------------------------------------------*/

/* ----------------------------------------------------------------------*/

PIX * pixReadJpeg(const char *filename, int32_t cmflag, int32_t reduction,
                  int32_t *pnwarn, int32_t hint)
{
    return (PIX * )ERROR_PTR("function not present", __func__, NULL);
}

/* ----------------------------------------------------------------------*/

PIX * pixReadStreamJpeg(FILE *fp, int32_t cmflag, int32_t reduction,
                        int32_t *pnwarn, int32_t hint)
{
    return (PIX * )ERROR_PTR("function not present", __func__, NULL);
}

/* ----------------------------------------------------------------------*/

l_ok readHeaderJpeg(const char *filename, int32_t *pw, int32_t *ph,
                    int32_t *pspp, int32_t *pycck, int32_t *pcmyk)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok freadHeaderJpeg(FILE *fp, int32_t *pw, int32_t *ph,
                     int32_t *pspp, int32_t *pycck, int32_t *pcmyk)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

int32_t fgetJpegResolution(FILE *fp, int32_t *pxres, int32_t *pyres)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

int32_t fgetJpegComment(FILE *fp, uint8_t **pcomment)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok pixWriteJpeg(const char *filename, PIX *pix, int32_t quality,
                  int32_t progressive)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok pixWriteStreamJpeg(FILE *fp, PIX *pix, int32_t quality,
                        int32_t progressive)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

PIX * pixReadMemJpeg(const uint8_t *cdata, size_t size, int32_t cmflag,
                     int32_t reduction, int32_t *pnwarn, int32_t hint)
{
    return (PIX * )ERROR_PTR("function not present", __func__, NULL);
}

/* ----------------------------------------------------------------------*/

l_ok readHeaderMemJpeg(const uint8_t *cdata, size_t size,
                       int32_t *pw, int32_t *ph, int32_t *pspp,
                       int32_t *pycck, int32_t *pcmyk)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok readResolutionMemJpeg(const uint8_t *data, size_t size,
                           int32_t *pxres, int32_t *pyres)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok pixWriteMemJpeg(uint8_t **pdata, size_t *psize, PIX *pix,
                     int32_t quality, int32_t progressive)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok pixSetChromaSampling(PIX *pix, int32_t sampling)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

/* --------------------------------------------*/
#endif  /* !HAVE_LIBJPEG */
/* --------------------------------------------*/
