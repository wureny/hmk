#include <stdio.h>
#include <assert.h>
#include"lec3_ex3.16b.c"
int main() {
    LIST list;
    list.last_position = -1; // Initialize the list with no elements

    // Test case 1: Delete an element from an empty list
    Delete(5, &list);
    assert(list.last_position == -1); // The list should remain empty

    // Test case 2: Delete an element that doesn't exist
    list.data[0] = 10;
    list.last_position = 0;
    Delete(7, &list);
    assert(list.last_position == 0); // The list should remain unchanged

    // Test case 3: Delete an element from a non-empty list
    list.data[1] = 5;
    list.data[2] = 10;
    list.data[3] = 15;
    list.last_position = 3;
    Delete(10, &list);
    assert(list.data[0] == 5);
    assert(list.data[1] == 15);


    printf("Delete function test passed!\n");
    return 0;
}
