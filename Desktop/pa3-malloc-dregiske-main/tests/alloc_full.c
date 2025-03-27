#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#include "vmlib.h"
#include "vm.h"

int main()
{
    vminit(1024);

    void *ptr;
    int count = 0;
    while ((ptr = vmalloc(256)) != NULL) {
        count++;
        assert((uint64_t)ptr % BLKALIGN == 0);
    }

    assert(count == 15);

    vmdestroy();
    return 0;
}
