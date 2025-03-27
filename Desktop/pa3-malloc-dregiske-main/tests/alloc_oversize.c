#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#include "vmlib.h"
#include "vm.h"

int main()
{
    vminit(1024);

    assert(vmalloc(4) != NULL);
    assert(vmalloc(13413) == NULL);
    assert(vmalloc(16) != NULL);
    assert(vmalloc(13413) == NULL);
    assert(vmalloc(32) != NULL);
    assert(vmalloc(13413) == NULL);
    assert(vmalloc(64) != NULL);

    vmdestroy();
    return 0;
}
