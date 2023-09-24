#include <stdio.h>
#include <string.h>

int del_substr(char *str, char const *substr) {
    if (str==NULL) return 0;
    if (substr==NULL) return 0;
    if (*substr=='\0') return 0; 
    size_t sn = strlen(str);
    size_t substrlen = strlen(substr);
    if (substrlen > sn) {
        return 0; 
    }
    char *match = strstr(str, substr);
    if (match == NULL) {
        return 0;
    }
    size_t movelen = sn - (match - str) - substrlen + 1;
    memmove(match, match + substrlen, movelen);
    return 1;
}

