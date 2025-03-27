#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#include "vmlib.h"
#include "vm.h"

/*
 * Simple vmalloc test.
 * Makes TWO consecutive small allocations and confirms that
 * - both vmalloc() calls returned valid pointers,
 * - allocations happened at the right locations,
 * - allocations created the appropriate headers.
 */
int main()
{
    vminit(1024);

    /* first allocation */
    void *ptr = vmalloc(16);
    struct block_header *hdr = (struct block_header *)
                               ((char *)ptr - sizeof(struct block_header));
    // check that vmalloc succeeded.
    assert(ptr != NULL);
    // check pointer is aligned.
    assert((uint64_t)ptr % 16 == 0);
    // check position of vmalloc'd block.
    assert((char *)ptr - (char *)heapstart == sizeof(struct block_header));
    // check block header has the correct contents.
    assert(hdr->size_status == 35);

    /* second allocation */
    void *ptr2 = vmalloc(4);
    hdr = (struct block_header *)((char *)ptr2 - sizeof(struct block_header));

    // check that vmalloc succeeded.
    assert(ptr2 != NULL);
    // check pointer is aligned.
    assert((uint64_t)ptr2 % 16 == 0);
    // check position of vmalloc'd block
    assert((char *)ptr2 - (char *)ptr == 32);
    // check block header has correct contents.
    assert(hdr->size_status == 19);

    vmdestroy();
    return 0;
}
