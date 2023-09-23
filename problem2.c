#include <stdio.h>
#include <string.h>

int del_substr(char *str, char const *substr) {
    // Check for NULL pointers or empty substrings
    if (str == NULL || substr == NULL || *substr == '\0') {
        return 0;
    }
    size_t str_len = strlen(str);
    size_t substr_len = strlen(substr);
    if (substr_len > str_len) {
        return 0; 
    }
    char *match = strstr(str, substr);
    if (match == NULL) {
        return 0;
    }
    size_t move_len = str_len - (match - str) - substr_len + 1;
    memmove(match, match + substr_len, move_len);
    return 1;
}

