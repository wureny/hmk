#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include"lec4_ex3.16b.c"

int main() {
    LIST list;
    list.head = NULL;

    // Test case 1: Delete from an empty list
    Delete(5, &list);

    // Test case 2: Delete a non-existent element
    insertFront(&list, 10);
    Delete(7, &list);
    assert(list.head->data == 10); // The list should remain unchanged

    // Test case 3: Delete an element from a non-empty list
    insertFront(&list, 5);
    insertFront(&list, 15);
    Delete(10, &list);
    assert(list.head->data == 15); // 15 should be at the head
    assert(list.head->next->data == 5); // 5 should be the next element


    // Free the list
    freeList(&list);

    printf("Delete function test passed!\n");
    return 0;
}
