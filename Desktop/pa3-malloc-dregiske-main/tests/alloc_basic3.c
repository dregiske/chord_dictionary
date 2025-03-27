#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#include "vmlib.h"
#include "vm.h"

/*
 * Best-fit vmalloc test.
 *
 * Makes one allocation and confirms that it returns a valid pointer,
 * and the allocation takes place at the beginning of the heap.
 * 
 * This time, the most optimal block is not the first free block but
 * rather the second one. Your allocator should be able to find this
 * target block.
 */
int main()
{
    vmload("img/many_free.img");

    // vminfo(); /* uncomment this to see the contents of the image. */

    void *ptr = vmalloc(16);  /* this should look for a 48-byte block. */
    struct block_header *hdr = (struct block_header *)
                               ((char *)ptr - sizeof(struct block_header));
    
    assert(ptr != NULL);
    assert((uint64_t)ptr % 16 == 0);
    assert((char *)ptr - (char *)heapstart == 184);
    assert(hdr->size_status == 35);

    vmdestroy();
    return 0;
}
