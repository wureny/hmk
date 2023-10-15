#include <stdio.h>
#include <string.h>

int del_substr(char *str, const char *substr) {
    if (str == NULL || substr == NULL || *substr == '\0') {
        return 0;
    }
    size_t substr_len = strlen(substr);
    if (substr_len == 0) {
        return 0; 
    }
    char *source = str; 
    char *destination = str; 
    char *match;

    // 使用strstr查找substr在str中的第一个出现
    if ((match = strstr(source, substr)) != NULL) {
        size_t prefix_len = match - source; 
        for (size_t i = 0; i < prefix_len; i++) {
            *destination++ = *source++;
        }
        source += substr_len; // 移动source指针到匹配之后
    }

    // 复制剩下的字符
    while ((*destination++ = *source++) != '\0');

    return 1;
}



