#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#include "vmlib.h"
#include "vm.h"

/*
 * Another simple vmalloc test.
 *
 * Makes one allocation and confirms that it returns a valid pointer,
 * and the allocation takes place at the beginning of the heap.
 * 
 * The difference from alloc_basic is that this one loads a heap image
 * that has many allocated blocks. In this case, your allocator should
 * identify the first free block as the target.
 */
int main()
{
    vmload("img/many_free.img");

    // vminfo(); /* uncomment this to see the contents of the image. */

    void *ptr = vmalloc(35);  /* this should look for a 48-byte block. */
    struct block_header *hdr = (struct block_header *)
                               ((char *)ptr - sizeof(struct block_header));
    
    assert(ptr != NULL);
    assert((uint64_t)ptr % 16 == 0);
    assert((char *)ptr - (char *)heapstart == 104);
    assert(hdr->size_status == 51);

    vmdestroy();
    return 0;
}
