#include "leptfuzz.h"

extern "C" int
LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    leptSetStdNullHandler();

    uint32_t     *data2;
    PIX          *pixs;

    pixs = pixReadMemSpix(data, size);
    if(pixs==NULL) return 0;

    data2 = pixExtractData(pixs);
    
    lept_free(data2);
    pixDestroy(&pixs);
    return 0;
}
