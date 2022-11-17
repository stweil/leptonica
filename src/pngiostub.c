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
 * \file pngiostub.c
 * <pre>
 *
 *     Stubs for pngio.c functions
 * </pre>
 */

#ifdef HAVE_CONFIG_H
#include <config_auto.h>
#endif  /* HAVE_CONFIG_H */

#include "allheaders.h"

/* --------------------------------------------*/
#if  !HAVE_LIBPNG   /* defined in environ.h */
/* --------------------------------------------*/

PIX * pixReadStreamPng(FILE *fp)
{
    return (PIX * )ERROR_PTR("function not present", __func__, NULL);
}

/* ----------------------------------------------------------------------*/

l_ok readHeaderPng(const char *filename, int32_t *pwidth, int32_t *pheight,
                   int32_t *pbps, int32_t *pspp, int32_t *piscmap)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok freadHeaderPng(FILE *fp, int32_t *pwidth, int32_t *pheight,
                    int32_t *pbps, int32_t *pspp, int32_t *piscmap)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok readHeaderMemPng(const uint8_t *data, size_t size, int32_t *pwidth,
                      int32_t *pheight, int32_t *pbps, int32_t *pspp,
                      int32_t *piscmap)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

int32_t fgetPngResolution(FILE *fp, int32_t *pxres, int32_t *pyres)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok isPngInterlaced(const char *filename, int32_t *pinterlaced)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok fgetPngColormapInfo(FILE *fp, PIXCMAP **pcmap, int32_t *ptransparency)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok pixWritePng(const char *filename, PIX *pix, l_float32 gamma)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok pixWriteStreamPng(FILE *fp, PIX *pix, l_float32 gamma)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

l_ok pixSetZlibCompression(PIX *pix, int32_t compval)

{
    return ERROR_INT("function not present", __func__, 1);
}

/* ----------------------------------------------------------------------*/

void l_pngSetReadStrip16To8(int32_t flag)
{
    L_ERROR("function not present\n", __func__);
    return;
}

/* ----------------------------------------------------------------------*/

PIX * pixReadMemPng(const uint8_t *filedata, size_t filesize)
{
    return (PIX * )ERROR_PTR("function not present", __func__, NULL);
}

/* ----------------------------------------------------------------------*/

l_ok pixWriteMemPng(uint8_t **pfiledata, size_t *pfilesize, PIX *pix,
                    l_float32 gamma)
{
    return ERROR_INT("function not present", __func__, 1);
}

/* --------------------------------------------*/
#endif  /* !HAVE_LIBPNG */
/* --------------------------------------------*/
