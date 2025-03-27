#include "vm.h"
#include "vmlib.h"

void *vmalloc(size_t size)
{
    struct block_header *ptr = heapstart; // set ptr to heaps start
    struct block_header *best_fit = NULL; // initialize another ptr for best fit

    if(size <= 0 || ptr == NULL) return NULL; // check if size is less than 0,
                                              // or if ptr couldn't reach heap start

    size = ROUND_UP(size + sizeof(struct block_header), BLKALIGN);

    while (ptr->size_status != VM_ENDMARK){ // while current ptr hasn't hit endmark

        if((ptr->size_status & VM_BUSY) == 0){ // check if ptr is empty
            if(BLKSZ(ptr) >= size){ // if size fits
                if(best_fit == NULL || best_fit->size_status > BLKSZ(ptr)){
                    best_fit = ptr; // update best fit if conditions meet

                    if(BLKSZ(ptr) == size) break; // exact fit
                }
            }
        }
        ptr = (struct block_header *)((char *)ptr + BLKSZ(ptr)); // traverse to next block
    }

    if(best_fit != NULL){
        best_fit->size_status |= VM_BUSY; // set as busy
        return (void *)((char *)best_fit + sizeof(struct block_header));
    }
    return NULL; // didn't find a block
}