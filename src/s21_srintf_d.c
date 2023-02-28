
int s21_spec_p(va_list args, Prototype *prot, char *charbuf){
    void *num = va_arg(args, void*);
    char buff[512] = {'\0'};
    long long int num2 = (long long int)num;
    UDecInNumSys(buff, num2, 16, 0);
    s21_strcpy(charbuf, "0x");
    s21_strcpy(charbuf, buff);
    return s21_strlen(charbuf);
}


void s21_spec_n(va_list args, int j){
    int *var = va_arg(args, int*);
    *var = j;
}


// уточнить нужно ли возвращать длину строки
int s21_spec_id(va_list args, Prototype *prot, char *charbuf, int j) {
    int len = 0;
    int i = 0;
    long int num = 0;
    if(prot->length == 'h'){
        num = (short)va_arg(args, int);
    } else if(prot->length == 'l'){
        num = va_arg(args, long int);
    } else {
        num = va_arg(args, int);
    };
    
    int num_i = 0;
    while (num > 0){
        int tmp_dig;
        tmp_dig = num%10;
        num = num / 10;
        charbuf[num_i] = tmp_dig + '0';
        num_i++;
    }
    s21_reverse(charbuf);
    return num_i;
}

int s21_spec_s(char *str, va_list args, Prototype *prot, int j) {
    int i = 0;
    int len = 0;
    int sp_qnt = 0;
    char *strng_arg = va_arg(args, char*);

    if(prot->precision == -1) {
        len = (int)s21_strlen(strng_arg);
    } else {
        len = prot->precision;
    };
    
    if(prot->width_number < len) prot->width_number = len;

    sp_qnt = prot->width_number - len;

    if(prot->minus_flag == '-'){
        i += prep_string(str, strng_arg, len, j);
        i += print_spaces(str, sp_qnt, j + i);
    } else {
        i += print_spaces(str, sp_qnt, j);
        i += prep_string(str, strng_arg, len, j + i);
    };
    return i;
}

int s21_spec_c(char *str, va_list args, Prototype *prot, int j) {
    char c = va_arg(args, int);
    int sp_qnt = 0;
    int i = 0;
    if(prot->width_number > 0){
        sp_qnt = prot->width_number -1;
    };
    if(prot->minus_flag == '-'){
        str[j] = c;
        i++;
        i += print_spaces(str, sp_qnt, j + i);
    } else {
        i += print_spaces(str, sp_qnt, j);
        str[j + i] = c;
        i++;
    };
    return i;
}


int print_spaces(char *str, int n, int j) {
    for(int i = 0; i < n; i++)
        str[j + i] = ' ';
    return n;
}

int prep_string(char *str, char *strng_arg, int n, int j) {
    for(int i = 0; i < n; i++){
        str[j + i] = strng_arg[i];
    };
    return n;
}

void *s21_reverse (char *str) {   // str должен быть массивом или сделан через malloc, а не указателем char * на область памяти в стеке
    if(str == S21_NULL) return S21_NULL;
    int bgn = 0;
    int end = s21_trlen(str) - 1;
    char temp;
    while(bgn < end) {
        temp = str[bgn];
        *(str + bgn) = *(str + end);
        *(str + end) = temp;
        bgn++;
        end--;
    }
    return str;
}