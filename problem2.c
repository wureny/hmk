#include <stdio.h>
int del_substr(char *str, const char *substr) {
    if (str == NULL || substr == NULL || *substr == '\0') {
        return 0;
    }
    size_t str_len = strlen(str);
    size_t substr_len = strlen(substr);
    if (substr_len == 0) {
        return 0; 
    }
    char *source = str; 
    char *destination = str; 
    char *match;

    while ((match = strstr(source, substr)) != NULL) {
        size_t prefix_len = match - source; 
        for (size_t i = 0; i < prefix_len; i++) {
            *destination++ = *source++;
        }

        source += substr_len; // Move the source pointer past the match
    }
    while ((*destination++ = *source++) != '\0');
    return 1;
}


