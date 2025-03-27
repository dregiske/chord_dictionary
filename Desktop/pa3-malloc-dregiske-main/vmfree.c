#include "vm.h"
#include "vmlib.h"

/**
 * The vmfree() function frees the memory space pointed to by ptr,
 * which must have been returned by a previous call to vmmalloc().
 * Otherwise, or if free(ptr) has already been called before,
 * undefined behavior occurs.
 * If ptr is NULL, no operation is performed.
 */
void vmfree(void *ptr)
{
    if(ptr == NULL) return; // return if ptr is null

    struct block_header *block = (struct block_header *)((char *)ptr - sizeof(struct block_header));

    if((block->size_status & VM_BUSY) == 0){ // return if block is free
        return;
    }

    block->size_status &= ~VM_BUSY; // set block to free

    struct block_footer *footer = (struct block_footer *)((char *)block + BLKSZ(block) - sizeof(struct block_footer));
    footer->size = BLKSZ(block); // create footer

    struct block_header *next_block = (struct block_header *)((char *)block + BLKSZ(block));
    if ((next_block->size_status & VM_BUSY) == 0) { // coalesce with next block if free
        block->size_status += BLKSZ(next_block);
    }

    if ((block->size_status & VM_PREVBUSY) == 0) { // coalesce with prev block if free
        struct block_footer *prev_footer = (struct block_footer *)((char *)block - sizeof(struct block_footer));
        struct block_header *prev_block = (struct block_header *)((char *)block - prev_footer->size);
        prev_block->size_status += BLKSZ(block);
    }
}
