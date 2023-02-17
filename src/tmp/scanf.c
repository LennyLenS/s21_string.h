#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

// %[флаги][ширина][.точность][длина]спецификатор
typedef struct {
  char spec;         // спецификаторы
  int minus_flag;    // флаг -
  int plus_flag;     // флаг +
  int space_flag;    // флаг ' '
  int zero_flag;     // флаг 0
  int sharp_flag;    // флаг #
  int width_number;  // Ширина (число), *
  int width_star;
  int prec_number;  // Точность если .число
  int prec_star;    // Точность если .*
  char length;      // Длина
} Prototype;


int atoi(char *str);
int s21_sscanf(const char *str, const char *format, ...);
int s21_switch_scan_spec(Prototype *prot, const char *format, char *str, int i, va_list args);

int s21_read_format(Prototype *prot, const char *format, int i, va_list args);
int s21_check_prec(const char *format, int i, int *this_is_prec, Prototype *prot, va_list args);
void s21_check_width(const char *format, int i, int *this_is_width, Prototype *prot, va_list args);
void s21_check_flags(const char *format, int i, Prototype *prot, int *this_is_prec, int *this_is_width);
bool s21_check_number(const char *format, int i);
int s21_write_number(const char *format, int *i);


int main(void){
    int q, w=8, d=5;
    int s = sscanf("123 g45 2 3", "%2dg %d%d", &q, &w, &d);    // этот вариант работает
    printf ("%d %d %d s=%d\n", q, w, d, s);
    
    char str1[50];
    int f;
    char ch;
    sscanf("% 88%Well done 12", "%c%d%%%s", &ch, &f, str1);   // и тут
    printf("You wrote: %s %d %c\n", str1, f, ch);

    char str2[80];
    int i;
    sscanf("hello 1 2 3 4 5", "%s%d", str2, &i);
    printf("%s %d\n", str2, i);

    int a = atoi("12345");
    printf("\nint+1 %d\n", (a+1));

    char str[50] = "123 abc d";
    char format[50] = "%d %10s %c";
    int dd;
    char ss[50] = {'\0'};
    char cc;
    int t = s21_sscanf(str, format, &dd, &ss, &cc);
    printf("t = %d\n", t);
  return 0;
}

int s21_sscanf(const char *str, const char *format, ...){
  char c;
  va_list args;
  va_start(args, format);
  int i = 0;



  while((c = format[i]) != '\0'){
    if(c != '%'){
      i++;
      continue;
    };
    Prototype prot = {'\0', 0, 0, 0, 0, 0, 0, 0, -1, -1, '\0'};
    // pass_spaces();
    i = s21_read_format(&prot, format, i, args);
    // void *p_args = va_arg(args, void*);

    s21_switch_scan_spec(&prot, format, str, i, args);



    i++;
    // printf("pointer - %p\n", p_args);
    // printf("spec - %c, width_number - %d, str - %s, format - %s\n", prot.spec, prot.width_number, str, format);
  };

  va_end(args);
  return i;
}


int atoi(char *str){
  int res = 0;
  for(int i = 0; str[i] != '\0'; i++) {
    res = res*10;
    res = res + str[i] - '0';
  };
  return res;
}

int s21_switch_scan_spec(Prototype *prot, const char *format, char *str, int i, va_list args){
  void *p_args;
  
  switch (prot -> spec)
  {
  case 'd':
  p_args = va_arg(args, void*);
printf("pointer - %p\n", p_args);
printf("spec - %c, width_number - %d, str - %s, format - %s\n", prot -> spec, prot -> width_number, str, format);
    break;
  case 'c':
  p_args = va_arg(args, void*);
printf("pointer - %p\n", p_args);
printf("spec - %c, width_number - %d, str - %s, format - %s\n", prot -> spec, prot -> width_number, str, format);
    break;
  case 's':
  p_args = va_arg(args, void*);
printf("pointer - %p\n", p_args);
printf("spec - %c, width_number - %d, str - %s, format - %s\n", prot -> spec, prot -> width_number, str, format);
    break;
  
  default:
    break;
  };
  return i;
}



int s21_read_format(Prototype *prot, const char *format, int i, va_list args) {
  int this_is_width = 0;
  int this_is_prec = 0;
  i++;
  while (format[i]) {
    // Check flags
    s21_check_flags(format, i, prot, &this_is_prec, &this_is_width);
    // Check width
    s21_check_width(format, i, &this_is_width, prot, args);
    // Check prec
    i = s21_check_prec(format, i, &this_is_prec, prot, args);
    // Check length
    if (format[i] == 'h') {
      prot->length = format[i];
    } else if (format[i] == 'l') {
      prot->length = format[i];
    } else if (format[i] == 'L') {
      prot->length = format[i];
    }
    // Check spec
    if (format[i] == 'c' || format[i] == 'd' || format[i] == 'i' ||
        format[i] == 'e' || format[i] == 'E' || format[i] == 'f' ||
        format[i] == 'g' || format[i] == 'G' || format[i] == 'o' ||
        format[i] == 's' || format[i] == 'u' || format[i] == 'x' ||
        format[i] == 'X' || format[i] == 'p' || format[i] == 'n' ||
        format[i] == '%')
      prot->spec = format[i];
    if (prot->spec == format[i])
      break;  // выходим нашелся спецификатор
    else
      i++;  // продолжаем дальше обрабатывать прототип спецификатора
  }
  return i;
}

int s21_check_prec(const char *format, int i, int *this_is_prec,
                   Prototype *prot, va_list args) {
  if (format[i] == '.') {
    i++;
    if (s21_check_number(format, i) == true && *this_is_prec == 0) {
      prot->prec_number = s21_write_number(format, &i);
      *this_is_prec = 1;
    } else if (format[i] == '*' && *this_is_prec == 0) {
      prot->prec_star = va_arg(args, int);
      *this_is_prec = 1;
    }
  }
  return i;
}

void s21_check_width(const char *format, int i, int *this_is_width,
                     Prototype *prot, va_list args) {
  if (s21_check_number(format, i) == true && *this_is_width == 0) {
    prot->width_number = s21_write_number(format, &i);
    *this_is_width = 1;
  } else if (prot->width_number == 0 && format[i] == '*' &&
             *this_is_width == 0) {
    prot->width_star = va_arg(args, int);
    *this_is_width = 1;
  }
}

void s21_check_flags(const char *format, int i, Prototype *prot,
                     int *this_is_prec, int *this_is_width) {
  if (format[i] == '+') {
    prot->plus_flag = 1;
  } else if (format[i] == '-') {
    prot->minus_flag = 1;
  } else if (format[i] == ' ') {
    prot->space_flag = 1;
  } else if (format[i] == '#') {
    prot->sharp_flag = 1;
  } else if (format[i] == '0' && *this_is_prec == 0 && *this_is_width == 0) {
    prot->zero_flag = 1;
  }
}

bool s21_check_number(const char *format, int i) {
  bool result = false;
  if (format[i] >= '0' && format[i] <= '9') result = true;
  return result;
}

int s21_write_number(const char *format, int *i) {
  int width = 0;
  width += format[*i] - '0';
  *i += 1;
  while (s21_check_number(format, *i) == true) {
    width *= 10;
    width += format[*i] - '0';
    *i += 1;
  }
  return width;
}
