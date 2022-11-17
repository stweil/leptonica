#include "leptfuzz.h"

extern "C" int
LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    if(size<3) return 0;
    int32_t  rotation;
    l_float32 upconf1, leftconf1;
    PIX *pix1, *pix2;

    leptSetStdNullHandler();

    pix1 = pixReadMemSpix(data,size);
    if(pix1==NULL) return 0;
    pix2 = pixOrientCorrect(pix1, 1.0, 1.0, &upconf1, &leftconf1, &rotation, 0);
    pixDestroy(&pix1);
    pixDestroy(&pix2);
    return 0;
}
