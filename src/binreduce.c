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

/*
 *  binreduce.c
 *
 *      Subsampled 2x reduction
 *           PIX      *pixReduceBinary2()
 *
 *      Rank filtered 2x reductions
 *           PIX      *pixReduceRankBinaryCascade()
 *           PIX      *pixReduceRankBinary2()
 *
 *      Permutation table for 2x rank binary reduction
 *           l_uint8  *makeSubsampleTab2x(void)
 */

#include <string.h>
#include "allheaders.h"


/*------------------------------------------------------------------*
 *                       Subsampled reduction                       *
 *------------------------------------------------------------------*/
/*!
 *  pixReduceBinary2()
 *
 *      Input:  pixs
 *              tab (<optional>; if null, a table is made here
 *                   and destroyed before exit)
 *      Return: pixd (2x subsampled), or null on error
 *
 *  Notes:
 *      (1) After folding, the data is in bytes 0 and 2 of the word,
 *          and the bits in each byte are in the following order
 *          (with 0 being the leftmost originating pair and 7 being
 *          the rightmost originating pair):
 *               0 4 1 5 2 6 3 7
 *          These need to be permuted to
 *               0 1 2 3 4 5 6 7
 *          which is done with an 8-bit table generated by makeSubsampleTab2x().
 */
PIX *
pixReduceBinary2(PIX      *pixs,
                 l_uint8  *intab)
{
l_uint8    byte0, byte1;
l_uint8   *tab;
l_uint16   shortd;
l_int32    i, id, j, ws, hs, wpls, wpld, wplsi;
l_uint32   word;
l_uint32  *datas, *datad, *lines, *lined;
PIX       *pixd;

    PROCNAME("pixReduceBinary2");

    if (!pixs)
        return (PIX *)ERROR_PTR("pixs not defined", procName, NULL);

    if (pixGetDepth(pixs) != 1)
        return (PIX *)ERROR_PTR("pixs not binary", procName, NULL);

    if (intab) {  /* use input table */
        tab = intab;
    } else {
        if ((tab = makeSubsampleTab2x()) == NULL)
            return (PIX *)ERROR_PTR("tab not made", procName, NULL);
    }

    ws = pixGetWidth(pixs);
    hs = pixGetHeight(pixs);
    if (hs <= 1)
        return (PIX *)ERROR_PTR("hs must be at least 2", procName, NULL);
    wpls = pixGetWpl(pixs);
    datas = pixGetData(pixs);

    if ((pixd = pixCreate(ws / 2, hs / 2, 1)) == NULL)
        return (PIX *)ERROR_PTR("pixd not made", procName, NULL);
    pixCopyResolution(pixd, pixs);
    pixScaleResolution(pixd, 0.5, 0.5);
    wpld = pixGetWpl(pixd);
    datad = pixGetData(pixd);

        /* e.g., if ws = 65: wd = 32, wpls = 3, wpld = 1 --> trouble */
    wplsi = L_MIN(wpls, 2 * wpld);  /* iterate over this number of words */

    for (i = 0, id = 0; i < hs - 1; i += 2, id++) {
        lines = datas + i * wpls;
        lined = datad + id * wpld;
        for (j = 0; j < wplsi; j++) {
            word = *(lines + j);
            word = word & 0xaaaaaaaa;  /* mask */
            word = word | (word << 7);  /* fold; data in bytes 0 & 2 */
            byte0 = word >> 24;
            byte1 = (word >> 8) & 0xff;
            shortd = (tab[byte0] << 8) | tab[byte1];
            SET_DATA_TWO_BYTES(lined, j, shortd);
        }
    }

    if (intab == NULL)
        LEPT_FREE(tab);
    return pixd;
}


/*------------------------------------------------------------------*
 *                   Rank filtered binary reductions                *
 *------------------------------------------------------------------*/
/*!
 *  pixReduceRankBinaryCascade()
 *
 *      Input:  pixs (1 bpp)
 *              level1, ... level 4 (thresholds, in the set {0, 1, 2, 3, 4})
 *      Return: pixd, or null on error
 *
 *  Notes:
 *      (1) This performs up to four cascaded 2x rank reductions.
 *      (2) Use level = 0 to truncate the cascade.
 */
PIX *
pixReduceRankBinaryCascade(PIX     *pixs,
                           l_int32  level1,
                           l_int32  level2,
                           l_int32  level3,
                           l_int32  level4)
{
PIX      *pix1, *pix2, *pix3, *pix4;
l_uint8  *tab;

    PROCNAME("pixReduceRankBinaryCascade");

    if (!pixs)
        return (PIX *)ERROR_PTR("pixs not defined", procName, NULL);
    if (pixGetDepth(pixs) != 1)
        return (PIX *)ERROR_PTR("pixs must be binary", procName, NULL);
    if (level1 > 4 || level2 > 4 || level3 > 4 || level4 > 4)
        return (PIX *)ERROR_PTR("levels must not exceed 4", procName, NULL);

    if (level1 <= 0) {
        L_WARNING("no reduction because level1 not > 0\n", procName);
        return pixCopy(NULL, pixs);
    }

    if ((tab = makeSubsampleTab2x()) == NULL)
        return (PIX *)ERROR_PTR("tab not made", procName, NULL);

    pix1 = pixReduceRankBinary2(pixs, level1, tab);
    if (level2 <= 0) {
        LEPT_FREE(tab);
        return pix1;
    }

    pix2 = pixReduceRankBinary2(pix1, level2, tab);
    pixDestroy(&pix1);
    if (level3 <= 0) {
        LEPT_FREE(tab);
        return pix2;
    }

    pix3 = pixReduceRankBinary2(pix2, level3, tab);
    pixDestroy(&pix2);
    if (level4 <= 0) {
        LEPT_FREE(tab);
        return pix3;
    }

    pix4 = pixReduceRankBinary2(pix3, level4, tab);
    pixDestroy(&pix3);
    LEPT_FREE(tab);
    return pix4;
}


/*!
 *  pixReduceRankBinary2()
 *
 *      Input:  pixs (1 bpp)
 *              level (rank threshold: 1, 2, 3, 4)
 *              intab (<optional>; if null, a table is made here
 *                     and destroyed before exit)
 *      Return: pixd (1 bpp, 2x rank threshold reduced), or null on error
 *
 *  Notes:
 *      (1) pixd is downscaled by 2x from pixs.
 *      (2) The rank threshold specifies the minimum number of ON
 *          pixels in each 2x2 region of pixs that are required to
 *          set the corresponding pixel ON in pixd.
 *      (3) Rank filtering is done to the UL corner of each 2x2 pixel block,
 *          using only logical operations.  Then these pixels are chosen
 *          in the 2x subsampling process, subsampled, as described
 *          above in pixReduceBinary2().
 */
PIX *
pixReduceRankBinary2(PIX      *pixs,
                     l_int32   level,
                     l_uint8  *intab)
{
l_uint8    byte0, byte1;
l_uint8   *tab;
l_uint16   shortd;
l_int32    i, id, j, ws, hs, wpls, wpld, wplsi;
l_uint32   word1, word2, word3, word4;
l_uint32  *datas, *datad, *lines, *lined;
PIX       *pixd;

    PROCNAME("pixReduceRankBinary2");

    if (!pixs)
        return (PIX *)ERROR_PTR("pixs not defined", procName, NULL);

    if (pixGetDepth(pixs) != 1)
        return (PIX *)ERROR_PTR("pixs not binary", procName, NULL);
    if (level < 1 || level > 4)
        return (PIX *)ERROR_PTR("level must be in set {1,2,3,4}",
            procName, NULL);

    if (intab) {  /* use input table */
        tab = intab;
    } else {
        if ((tab = makeSubsampleTab2x()) == NULL)
            return (PIX *)ERROR_PTR("tab not made", procName, NULL);
    }

    ws = pixGetWidth(pixs);
    hs = pixGetHeight(pixs);
    if (hs <= 1)
        return (PIX *)ERROR_PTR("hs must be at least 2", procName, NULL);
    wpls = pixGetWpl(pixs);
    datas = pixGetData(pixs);

    if ((pixd = pixCreate(ws / 2, hs / 2, 1)) == NULL)
        return (PIX *)ERROR_PTR("pixd not made", procName, NULL);
    pixCopyResolution(pixd, pixs);
    pixScaleResolution(pixd, 0.5, 0.5);
    wpld = pixGetWpl(pixd);
    datad = pixGetData(pixd);

        /* e.g., if ws = 65: wd = 32, wpls = 3, wpld = 1 --> trouble */
    wplsi = L_MIN(wpls, 2 * wpld);  /* iterate over this number of words */

    switch (level)
    {

    case 1:
        for (i = 0, id = 0; i < hs - 1; i += 2, id++) {
            lines = datas + i * wpls;
            lined = datad + id * wpld;
            for (j = 0; j < wplsi; j++) {
                word1 = *(lines + j);
                word2 = *(lines + wpls + j);

                    /* OR/OR */
                word2 = word1 | word2;
                word2 = word2 | (word2 << 1);

                word2 = word2 & 0xaaaaaaaa;  /* mask */
                word1 = word2 | (word2 << 7);  /* fold; data in bytes 0 & 2 */
                byte0 = word1 >> 24;
                byte1 = (word1 >> 8) & 0xff;
                shortd = (tab[byte0] << 8) | tab[byte1];
                SET_DATA_TWO_BYTES(lined, j, shortd);
            }
        }
        break;

    case 2:
        for (i = 0, id = 0; i < hs - 1; i += 2, id++) {
            lines = datas + i * wpls;
            lined = datad + id * wpld;
            for (j = 0; j < wplsi; j++) {
                word1 = *(lines + j);
                word2 = *(lines + wpls + j);

                    /* (AND/OR) OR (OR/AND) */
                word3 = word1 & word2;
                word3 = word3 | (word3 << 1);
                word4 = word1 | word2;
                word4 = word4 & (word4 << 1);
                word2 = word3 | word4;

                word2 = word2 & 0xaaaaaaaa;  /* mask */
                word1 = word2 | (word2 << 7);  /* fold; data in bytes 0 & 2 */
                byte0 = word1 >> 24;
                byte1 = (word1 >> 8) & 0xff;
                shortd = (tab[byte0] << 8) | tab[byte1];
                SET_DATA_TWO_BYTES(lined, j, shortd);
            }
        }
        break;

    case 3:
        for (i = 0, id = 0; i < hs - 1; i += 2, id++) {
            lines = datas + i * wpls;
            lined = datad + id * wpld;
            for (j = 0; j < wplsi; j++) {
                word1 = *(lines + j);
                word2 = *(lines + wpls + j);

                    /* (AND/OR) AND (OR/AND) */
                word3 = word1 & word2;
                word3 = word3 | (word3 << 1);
                word4 = word1 | word2;
                word4 = word4 & (word4 << 1);
                word2 = word3 & word4;

                word2 = word2 & 0xaaaaaaaa;  /* mask */
                word1 = word2 | (word2 << 7);  /* fold; data in bytes 0 & 2 */
                byte0 = word1 >> 24;
                byte1 = (word1 >> 8) & 0xff;
                shortd = (tab[byte0] << 8) | tab[byte1];
                SET_DATA_TWO_BYTES(lined, j, shortd);
            }
        }
        break;

    case 4:
        for (i = 0, id = 0; i < hs - 1; i += 2, id++) {
            lines = datas + i * wpls;
            lined = datad + id * wpld;
            for (j = 0; j < wplsi; j++) {
                word1 = *(lines + j);
                word2 = *(lines + wpls + j);

                    /* AND/AND */
                word2 = word1 & word2;
                word2 = word2 & (word2 << 1);

                word2 = word2 & 0xaaaaaaaa;  /* mask */
                word1 = word2 | (word2 << 7);  /* fold; data in bytes 0 & 2 */
                byte0 = word1 >> 24;
                byte1 = (word1 >> 8) & 0xff;
                shortd = (tab[byte0] << 8) | tab[byte1];
                SET_DATA_TWO_BYTES(lined, j, shortd);
            }
        }
        break;
    }

    if (!intab)
        LEPT_FREE(tab);
    return pixd;
}


/*!
 *  makeSubsampleTab2x()
 *
 *  This table permutes the bits in a byte, from
 *      0 4 1 5 2 6 3 7
 *  to
 *      0 1 2 3 4 5 6 7
 */
l_uint8 *
makeSubsampleTab2x(void)
{
l_uint8  *tab;
l_int32   i;

    PROCNAME("makeSubsampleTab2x");

    if ((tab = (l_uint8 *) LEPT_CALLOC(256, sizeof(l_uint8))) == NULL)
        return (l_uint8 *)ERROR_PTR("tab not made", procName, NULL);

    for (i = 0; i < 256; i++)
        tab[i] = ((i & 0x01)     ) |    /* 7 */
                 ((i & 0x04) >> 1) |    /* 6 */
                 ((i & 0x10) >> 2) |    /* 5 */
                 ((i & 0x40) >> 3) |    /* 4 */
                 ((i & 0x02) << 3) |    /* 3 */
                 ((i & 0x08) << 2) |    /* 2 */
                 ((i & 0x20) << 1) |    /* 1 */
                 ((i & 0x80)     );     /* 0 */

    return tab;
}
