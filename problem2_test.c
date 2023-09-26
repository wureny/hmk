#include <stdio.h>
#include <string.h>
#include <assert.h>
#include"problem2.c"
int main() {
    // Test case 1: Test with valid input
    char str1[] = "Hello, World!";
    const char *substr1 = "o";
    int result1 = del_substr(str1, substr1);
    assert(result1 == 1);
    assert(strcmp(str1, "Hell, Wrld!") == 0);

    // Test case 1: Test with NULL pointers
    char *str3 = NULL;
    const char *substr3 = "a";
    int result3 = del_substr(str3, substr3);
    assert(result3 == 0);

    // Test case 2: Test with empty substr
    char str4[] = "Testing";
    const char *substr4 = "";
    int result4 = del_substr(str4, substr4);
    assert(result4 == 0);
    assert(strcmp(str4, "Testing") == 0);

    // Test case 3: Test with multiple occurrences of substr
    char str6[] = "abracadabra";
    const char *substr6 = "bra";
    int result6 = del_substr(str6, substr6);
    assert(result6 == 1);
    assert(strcmp(str6, "acada") == 0);

    printf("All test cases passed!\n");
    return 0;
}
