#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "vmlib.h"
#include "vm.h"

int main()
{
    vminit(65536);

    void *ptrs[5];
    ptrs[0] = vmalloc(2012);
    ptrs[1] = vmalloc(8087);
    ptrs[2] = vmalloc(18019);
    ptrs[3] = vmalloc(21030);
    ptrs[4] = vmalloc(16202);

    for (int i = 0; i < 5; i++) {
        assert(ptrs[i] != NULL);
        assert((uint64_t)ptrs[i] % BLKALIGN == 0);
    }

    vmdestroy();
    return 0;
}
