/**
 * CSE 29: Systems Programming and Software Tools
 * Winter Quarter 2025
 * Programming Assignment 3
 *
 * vm.h
 * This header file defines the *private* interface for our memory allocation
 * system. E.g. internal data structures and constants. Helper functions.
 *
 * This file should only be included in the library source files. User programs
 * implemented using our custom memory allocation system do NOT include this
 * file.
 */

#ifndef VM_H
#define VM_H

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

/* Undefine memory allocation functions in stdlib.h */
#define malloc(x) NULL
#define calloc(x) NULL
#define realloc(x) NULL
#define reallocarray(x) NULL

/* The size_status value of the end mark block */
#define VM_ENDMARK 0x1

#define VM_BLKSZMASK 0xFFFFFFFFFFFFFFFC
#define VM_BUSY 0x1
#define VM_PREVBUSY 0x2

#define BLKSZ(b) ((b)->size_status & VM_BLKSZMASK)
#define ROUND_UP(N, S) ((((N) + (S)-1) / (S)) * (S))
#define BLKALIGN 16

/**
 * This structure serves as the block header for each heap block.
 * It is always 8 bytes long.
 */
struct block_header {
    /**
     * The size of a block is always a multiple of 16. This means that
     * the last four bits are always zero. We use the last two bits of
     * this variable to store other information.
     *
     * LSB: Least Significant Bit (Last Bit)
     * SLB: Second to Last Bit
     *
     * LSB = 0 <=> This block is free
     * LSB = 1 <=> This block is allocated
     * SLB = 0 <=> Previous block is free
     * SLB = 1 <=> Previous block is allocated
     *
     * When used as End Mark:
     *   size_status should be 1 (i.e. zero sized busy block). see VM_ENDMARK
     * macro.
     *
     * When we want to read the size, we should ignore the last two bits.
     */
    size_t size_status;
};

struct block_footer {
    size_t size;
};

/**
 * Global pointer to the first block in the heap.
 */
extern struct block_header *heapstart;

#endif /* VM_H */
