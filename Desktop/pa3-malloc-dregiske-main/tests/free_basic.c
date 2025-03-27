#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#include "vmlib.h"
#include "vm.h"

int main()
{
    vmload("img/no_free.img");

    // vminfo(); /* uncomment this to see the contents of the image. */

    void *ptr = heapstart + 1;
    vmfree(ptr);
    assert(heapstart->size_status == 82);

    ptr = vmalloc(64);
    assert(ptr != NULL);

    vmdestroy();
    return 0;
}