#include <stdio.h>

char *find_char(char const *source, char const *chars) {
    // Check for NULL pointers or empty strings
    if (source == NULL || chars == NULL || *source == '\0' || *chars == '\0') {
        return NULL;
    }
    while (*source != '\0') {
        char const *temp_chars = chars; // Reset temp_chars for each character in source
        while (*temp_chars != '\0') {
            if (*source == *temp_chars) {
                return (char *)source;
            }
            temp_chars++;
        }
        source++;
    }

    return NULL;
}