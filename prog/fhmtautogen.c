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
 * fhmtautogen.c
 *
 *    This program is used to generate the two files.
 *    If filename is not given, the files are:
 *         fhmtgen.<n>.c
 *         fhmtgenlow.<n>.c
 *    where <n> is the input index.  Otherwise they are:
 *         <filename>.<n>.c
 *         <filename>low.<n>.c
 *    These two files, when compiled, implement hit-miss dwa
 *    operations for all sels generated by selaAddHitMiss().
 *
 *    The library files fhmtgen.1.c and fhmtgenlow.1.c
 *    were made using index = 1.
 */

#ifdef HAVE_CONFIG_H
#include <config_auto.h>
#endif  /* HAVE_CONFIG_H */

#include "allheaders.h"

int main(int    argc,
         char **argv)
{
char    *filename;
int32_t  index;
SELA    *sela;

    if (argc != 2 && argc != 3)
        return ERROR_INT(" Syntax:  fhmtautogen index <filename>", __func__, 1);

    setLeptDebugOK(1);
    index = atoi(argv[1]);
    filename = NULL;
    if (argc == 3)
        filename = argv[2];

    sela = selaAddHitMiss(NULL);
    if (fhmtautogen(sela, index, filename))
        return 1;

    selaDestroy(&sela);
    return 0;
}

