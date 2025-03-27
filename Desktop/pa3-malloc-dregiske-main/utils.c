#include <stdio.h>
#include "vm.h"
#include "vmlib.h"
#define BLKOFF(b) ((char *)b - (char *)heapstart + sizeof(struct block_header))

// This helper function is important for debugging your code. It will print out a list of busy and free blocks, showing their offsets, size, and if the previous block is busy or free.
// This function is also useful for learning about how you should be iterating through each block.
void vminfo()
{
    static const char *blkstats[] = {"FREE", "BUSY"};

    struct block_header *block = heapstart;
    int blockid = 0;   
    int nfree = 0, nbusy = 0;

    int busy, prev_busy; 
    size_t blocksz;      
    size_t totalsz = 0;

    printf("---------------------------------------\n");
    printf(" %-6s %-7s %-8s %-8s %-7s\n", "#", "stat", "offset", "size", "prev");
    printf("---------------------------------------\n");

    // Loop to iterate through the blocks
    while (block->size_status != VM_ENDMARK) {
        // BLKSZ calculates the size of the block, definition located in vm.h. 
        // It extracts the size from block->size_status, and sets the last two bits to 0 (last two bits are used for free / busy information).
        blocksz = BLKSZ(block);

        // Determines if the current block is busy (allocated).
        busy = block->size_status & VM_BUSY ? 1 : 0;

        // Determines the status of the previous block (busy or free).
        prev_busy = block->size_status & VM_PREVBUSY ? 1 : 0;

        //Prints block data: blockid, status, offset, size, and previous block status
        printf(" %-6d %-7s %-8zu %-8zu %-7s\n", blockid++, blkstats[busy],
               BLKOFF(block), blocksz, blkstats[prev_busy]);

        if (busy) {
            nbusy++;
        } else {
            nfree++;
        }

        // Add the size of the current block to the total size.
        totalsz += blocksz;

        //Increment to next block by adding the size of the current block.
        block = (struct block_header *)((char *)block + blocksz);
    }

    printf(" %-6s %-7s %-8zu %-8s %-7s\n", "END", "N/A", BLKOFF(block), "N/A", "N/A");
    printf("---------------------------------------\n");

    // Print a summary that includes:
    // - Total bytes in the heap
    // - Number of free blocks
    // - Number of busy (allocated) blocks
    // - Total number of blocks
    printf("Total: %zu bytes, Free: %d, Busy: %d, Total: %d\n", totalsz, nfree,
           nbusy, nfree + nbusy);
}