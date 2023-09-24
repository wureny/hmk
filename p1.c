#include <stdio.h>

char *find_char(char const *source, char const *chars) {
    if (source==NULL) return NULL;
    if (chars==NULL) return NULL;
    if (*source=='\0' || *chars=='\0') return NULL;
    while (*source != '\0') {
        char const *t = chars; 
        while (*t != '\0') {
            if (*source == *t) {
                return (char *)source;
            }
            t=t+1;
        }
        source++;
    }
    return NULL;
}