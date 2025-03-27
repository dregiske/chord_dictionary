#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#include "vmlib.h"
#include "vm.h"

int main()
{
    vminit(1024);

    int *ptr[5];

    ptr[0] = vmalloc(2);
    ptr[1] = vmalloc(6);
    ptr[2] = vmalloc(900);
    ptr[3] = vmalloc(80);
    ptr[4] = vmalloc(12);

    for (int i = 0; i < 5; i++) {
        assert(ptr[i] != NULL);
        assert(((uint64_t)ptr[i]) % BLKALIGN == 0);
    }

    vmdestroy();
    return 0;
}
