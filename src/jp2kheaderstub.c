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
 * \file jp2kheaderstub.c
 * <pre>
 *
 *     Stubs for jp2kheader.c functions
 * </pre>
 */

#ifdef HAVE_CONFIG_H
#include <config_auto.h>
#endif  /* HAVE_CONFIG_H */

#include "allheaders.h"

/* --------------------------------------------*/
#if  !USE_JP2KHEADER   /* defined in environ.h */
/* --------------------------------------------*/

l_ok readHeaderJp2k(const char *filename, int32_t *pw, int32_t *ph,
                    int32_t *pbps, int32_t *pspp, int32_t *pcodec)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok freadHeaderJp2k(FILE *fp, int32_t *pw, int32_t *ph,
                     int32_t *pbps, int32_t *pspp, int32_t *pcodec)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok readHeaderMemJp2k(const uint8_t *cdata, size_t size, int32_t *pw,
                       int32_t *ph, int32_t *pbps, int32_t *pspp,
                       int32_t *pcodec)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

int32_t fgetJp2kResolution(FILE *fp, int32_t *pxres, int32_t *pyres)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* --------------------------------------------*/
#endif  /* !USE_JP2KHEADER */
