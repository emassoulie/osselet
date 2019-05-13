#include <string.h>

char *strrev(char* str) {
    for(int i = 0, j = strlen(str) - 1 ; i < j ; ++i, --j) {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    };
    return str;
}
