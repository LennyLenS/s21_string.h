#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <limits.h>
typedef struct {
  char spec;
  int minus_flag;
  int plus_flag;
  int space_flag;
  int zero_flag;
  int sharp_flag;
  int width_number;  // Ширина (число), *
  int width_star;
  int prec_number;
  int prec_star;
  char length;      // Длина
} Prototype;
#define SPACES " \t\n\v"
int s21_sscanf(const char *str, const char *format, ...);
int s21_switch_scan_spec(Prototype *prot, const char *format, const char *str, int *j, va_list args);
int scanf_spec_c(Prototype *prot, const char *str,  char *buff_str, va_list args, int *j);

int main(void){
    char str[10] = "ab/ c d";
    char format[10] = "%c";
    // char ss[10] = {'\0'};
    // char cc;
    char cc[10] = {'\0'};
    s21_sscanf(str, format, &cc);
    printf("cc=%s\n", cc);
    for(int i = 0; i < 6; i++){
      printf("cc %d %c\n", i, cc[i]);
    };
  return 0;
}

int s21_sscanf(const char *str, const char *format, ...){
  char c;
  int records = 0;
  va_list args;
  va_start(args, format);
  int i = 0;
  int j = 0;

  while((c = format[i]) != '\0'){
    if(c != '%'){
      if(strchr(SPACES, c) != NULL) { 
          while (strchr(SPACES, str[j]) != NULL) {
            j++;
          }
      } else if(str[j] == format[i]){
        j++;
      } else {
          break;
      };
      i++;
      continue;
    };
    Prototype prot = {'c', 0, 0, 0, 0, 0, 4, 0, -1, -1, '\0'};
    records += s21_switch_scan_spec(&prot, format, str, &j, args);
    i++;
  };
  va_end(args);
  return records;
}

int s21_switch_scan_spec(Prototype *prot, const char *format, const char *str, int *j, va_list args){
//   int width_counter = 0;
  int write_count = 0;
  char buff_str[20] = {'\0'};

  switch (prot -> spec) {
  case 'c':
    write_count += scanf_spec_c(prot, str, buff_str, args, j);
    *j += strlen(buff_str);
    printf("spec - %c, width_number - %d, str - %s, format - %s\n", prot -> spec, prot -> width_number, str, format);
    break;
  };
  return write_count;
}

int scanf_spec_c(Prototype *prot, const char *str,  char *buff_str, va_list args, int *j){
  char *p_args = NULL;
  int k = 0;
  p_args = va_arg(args, char*);
  if(prot -> width_number <= 1){
    *p_args = str[*j];
  } else {
    while(k < prot -> width_number){
      // buff_str[k] = str[*j + k];
      *(p_args + k) = str[*j + k];
      printf("p %c\n", *(p_args + k));
      k++;
    };
    printf("buf %s\n", buff_str);
    // strcpy(p_args, buff_str);
    printf("buf2 %s\n", p_args);

  };
  return 1;
}
