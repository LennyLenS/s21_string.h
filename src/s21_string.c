#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
    s21_size_t size =0;
    const char *p = str;
    while(*p != '\0') {
        size++;
        p++;
    };
    return size;
}

char *s21_strtok(char *str, const char *delim) {
    int str_ind = 0;
    static int ret_ind;
    static int first_time;
    static char* str_cash;
    
    if(str != NULL) {
        ret_ind = 0;
        first_time = 0;
        str_cash = NULL;
    };
    if(first_time == 0){
        str_cash = str;
    };
    if(str == NULL) {
        str = str_cash;
    };
    if(first_time == 0){
        while(str[str_ind] != '\0'){
            int delim_ind = 0;
            int match_count = 0;
            while(delim[delim_ind] != '\0'){
                if(str[str_ind] == delim[delim_ind]){
                    match_count++;
                    break;
                };
                delim_ind++;
            };
            if(match_count == 0) break;
            str_ind++;
        };
        first_time = 1;
        if((int)s21_strlen(str) == str_ind) return NULL;    //  если строка пустая или полностью состоит из разделителей.
        ret_ind = str_ind;
    };
    
    if(first_time == 1){
        ret_ind = str_ind;
        int rep_dilim = 0;
        
        while(str[str_ind] != '\0'){
            int delim_ind = 0;
            int match = 0;
            while(delim[delim_ind] != '\0'){
                if(str[str_ind] == delim[delim_ind]){
                    if(str[str_ind - 1] == '\0' || rep_dilim == 1) {
                        ret_ind++;
                        rep_dilim = 1;
                        match++;
                        break;
                    };
                    str[str_ind] = '\0';
                    match++;
                    break;
                };
                delim_ind++;
            }
            if(match == 1 && rep_dilim == 0) break;
            if(match == 0) rep_dilim = 0;
            str_ind++;
        }
        str_ind++;
    }
    if(str[str_ind] == '\0') return NULL;
    str_cash = &str[str_ind];
    return &str[ret_ind];
}