#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#include "vmlib.h"
#include "vm.h"

/*
 * Simplest vmalloc test.
 * Makes one allocation and confirms that it returns a valid pointer,
 * and the allocation takes place at the beginning of the heap.
 */
int main()
{
    vminit(1024);

    void *ptr = vmalloc(8);
    struct block_header *hdr = (struct block_header *)
                               ((char *)ptr - sizeof(struct block_header));

    // check that vmalloc succeeded.
    assert(ptr != NULL);
    // check pointer is aligned.
    assert((uint64_t)ptr % 16 == 0);
    // check position of malloc'd block.
    assert((char *)ptr - (char *)heapstart == sizeof(struct block_header));
    // check block header has the correct contents.
    assert(hdr->size_status == 19);

    vmdestroy();
    return 0;
}
