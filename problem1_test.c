#include <stdio.h>
#include <assert.h>
#include"problem1.c"
int main() {
    const char *source1 = "Hello, World!";
    const char *chars1 = "o";
    char *result1 = find_char(source1, chars1);
    assert(result1 != NULL);
    assert(*result1 == 'o');

    // Test case 2: Test with characters not in source
    const char *source2 = "This is a test";
    const char *chars2 = "xyz";
    char *result2 = find_char(source2, chars2);
    assert(result2 == NULL);

    // Test case 3: Test with NULL pointers
    const char *source3 = NULL;
    const char *chars3 = "a";
    char *result3 = find_char(source3, chars3);
    assert(result3 == NULL);

    // Test case 4: Test with empty source string
    const char *source4 = "";
    const char *chars4 = "a";
    char *result4 = find_char(source4, chars4);
    assert(result4 == NULL);
    
    printf("All test cases passed!\n");
    return 0;
}
