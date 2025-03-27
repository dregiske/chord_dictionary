#include <stdio.h>

#include "vmlib.h"

int main()
{
    vminit(2000); // comment this out if using vmload()

    /* alternatively, load a heap image */
    // vmload("tests/img/many_free.img");

    void *ptr = vmalloc(16);

    vminfo(); // print out how the heap looks like at this point in time for
              // easy visualization

    vmdestroy(); // frees all memory allocated by vminit() or vmload()
    return 0;
}
