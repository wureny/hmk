#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include"lec3_ex3.15a.c"
int main() {
    struct List list;
    Initialize(&list);

    // Test case 1: Delete an element
    Insert(5, &list);
    Insert(10, &list);
    Insert(15, &list);
    Delete(10, &list);
    assert(list.size == 2);

    // Test case 2: Delete an element that doesn't exist
    Delete(7, &list);
    assert(list.size == 2); // Size should remain unchanged

    printf("Delete function test passed!\n");
    return 0;
}
