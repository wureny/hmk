#include"lec4_ex3.15b.c"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int main() {
    struct List list;
    InitializeList(&list);

    // Test case 1: Delete an element from an empty list
    Delete(5, &list);

    // Test case 2: Delete an element that doesn't exist
    Insert(10, &list);
    Delete(7, &list);
    assert(list.head->data == 10); // The list should remain unchanged

    // Test case 3: Delete an element from a non-empty list
    Insert(5, &list);
    Insert(15, &list);
    Delete(10, &list);
    assert(list.head->data == 15); // 15 should be at the head
    assert(list.head->next->data == 5); // 5 should be the next element

    printf("Delete function test passed!\n");
    return 0;
}

