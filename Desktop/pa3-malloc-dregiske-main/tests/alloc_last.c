#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#include "vmlib.h"
#include "vm.h"

int main()
{
    vmload("img/last_free.img");

    // vminfo(); /* uncomment this to see the contents of the image. */

    void *ptr = vmalloc(100);
    assert(ptr != NULL);
    assert((uint64_t)ptr % BLKALIGN == 0);
    assert((char *)ptr - (char *)heapstart == 3480);

    void *ptr2 = vmalloc(480); // this should fill the last block
    assert(ptr2 != NULL);
    assert((uint64_t)ptr2 % BLKALIGN == 0);
    assert((char *)ptr2 - (char *)heapstart == 3592);

    // no more allocations should be possible
    assert(vmalloc(4) == NULL);

    vmdestroy();
    return 0;
}
