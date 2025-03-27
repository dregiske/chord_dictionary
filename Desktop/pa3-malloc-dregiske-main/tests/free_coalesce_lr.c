#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#include "vmlib.h"
#include "vm.h"

int main()
{
    vminit(4096);

    void *ptr1 = vmalloc(64);
    void *ptr2 = vmalloc(64);
    void *ptr3 = vmalloc(64);
    vmalloc(1000);

    /* create a free block at ptr3*/
    vmfree(ptr3);

    /* create a free block at ptr1*/
    vmfree(ptr1);

    /* freeing ptr2 should coalesce both left and right blocks*/
    vmfree(ptr2);

    /* this allocation should utilize the coalesced free block */
    void *ptr4 = vmalloc(224);
    assert(ptr1 == ptr4);

    vmdestroy();
    return 0;
}