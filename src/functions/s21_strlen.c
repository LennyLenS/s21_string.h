#include "../s21_string.h"

size_t s21_strlen(const char *str){
    size_t size = 0;
    if(str != NULL) {
        const char *p = str;
        while(*p != '\0') {
            size++;
            p++;
        }
    }
    return size;
}
