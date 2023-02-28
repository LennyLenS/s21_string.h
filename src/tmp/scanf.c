#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

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

  #define SPACES " \t\n\v"
  // #define S21_INFINITY 1.0 / 0.0

long long int atoi(char *str);
int isNumber(char c);
int s21_sscanf(const char *str, const char *format, ...);
int s21_switch_scan_spec(Prototype *prot, const char *format, const char *str, int *j, va_list args, int space_counter_for_n);
int scanf_spec_d(Prototype *prot, const char *str,  char *buff_str, va_list args, int width_counter, int *j);
int scanf_spec_c(Prototype *prot, const char *str,  char *buff_str, va_list args, int *j);
int scanf_spec_s(Prototype *prot, const char *str,  va_list args,  char *buff_str, int width_counter, int *j);
void scanf_spec_n(va_list args, int *j, int space_counter_for_n);

int s21_read_format(Prototype *prot, const char *format, int i, va_list args);
int s21_check_prec(const char *format, int i, int *this_is_prec, Prototype *prot, va_list args);
void s21_check_width(const char *format, int i, int *this_is_width, Prototype *prot);
void s21_check_flags(const char *format, int i, Prototype *prot, int *this_is_prec, int *this_is_width);
bool s21_check_number(const char *format, int i);
int s21_write_number(const char *format, int *i);

// в s21_check_width() явно прописал присвоение *, надо сделать флаг и if для версий сканф и принтф

// Сделать аварийные exit
// Сделать и проверить *

// + %n    return j

// #include <stdio.h>
// int main()
// {
//     char str[80];
//     int i;
//     int n;
//     /* пропуск целого между двумя строками */
//     sscanf ("qwe 45","%s%d%n", str, &i, &n);
    
//     printf("%s  %d  %d", str, i , n);

//     return 0;
// }


int main(void){
    int q, w=8, d=5;
    int s = sscanf("123 45 2 3", "%d%d%d", &q, &w, &d);    // этот вариант работает
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

    char str[50] = "       -1234 567h ag bfgh/ c d";
    char format[50] = "%d%d%*c%*s";
    int dd = 0; // переменные в тесте обязятельно инициилизировать 0
    int tt = 0;
    int nn = 0;
    char ss[50] = {'\0'};
    char cc;
    // char cc[50] = {'\0'};
    int t = s21_sscanf(str, format, &dd, &tt, &cc, &ss);

    int sdd;
    int stt;
    int snn = 0;
    char sss[50] = {'\0'};
    char scc;
    // char cc[50] = {'\0'};
    int b = sscanf(str, format, &sdd, &stt, &scc, &sss);

    printf("%s  %s\n", str, format);
    printf("21 t = %d  dd=%d  tt=%d  cc=%c  ss=%s nn=%d\n", t, dd, tt, cc, ss, nn);
    printf("ss t = %d  dd=%d  tt=%d  cc=%c  ss=%s nn=%d\n", b, sdd, stt, scc, sss, snn);
    // for(int i = 0; i < 6; i++){
    //   printf("cc %d %c\n", i, cc[i]);
    // };
  return 0;
}

int s21_sscanf(const char *str, const char *format, ...){
  char c;
  int records = 0;
  va_list args;
  va_start(args, format);
  int i = 0;  // для format
  int j = 0;  // для str

  // strchr(const char *str, int c)

  while((c = format[i]) != '\0'){
    printf("0 i = %d  %c\n", i, format[i]);
    if(c != '%'){
      // pass_spaces(int *i, int *j);
      if(strchr(SPACES, c) != NULL) {   // SPACES определен в define
          while (strchr(SPACES, str[j]) != NULL) {
            j++;
          }
      } else if(str[j] == format[i]){
        j++;
      } else {
          printf("ERROR\n");     //  СДЕЛАТЬ АВАРИЙНЫЙ ЭКЗИТ  exit;
          break;
      };
      i++;
      // printf("i %d\n", i);
      continue;
    };


    if(format[i+1] == '%') {
      i++;
      if(str[j] == '%') {
        i++;
        j++;
        continue;
      } else{
          printf("ERROR_2\n");     //  СДЕЛАТЬ АВАРИЙНЫЙ ЭКЗИТ  exit;
          break;
      }
    };    
    
    Prototype prot = {'\0', 0, 0, 0, 0, 0, 0, 0, -1, -1, '\0'};
    i = s21_read_format(&prot, format, i, args);
printf("1 i = %d  %c  * - %d\n", i, format[i], prot.width_star);

    // skip spaces in str
    int space_counter_for_n = 0;
    if(prot.spec != 'c'){
      while(strchr(SPACES, str[j]) != NULL){
        space_counter_for_n++;
        j++;
      }
    };
    printf("scn = %d\n", space_counter_for_n);

    records += s21_switch_scan_spec(&prot, format, str, &j, args, space_counter_for_n);

    i++;
    // printf("pointer - %p\n", p_args);
    // printf("spec - %c, width_number - %d, str - %s, format - %s\n", prot.spec, prot.width_number, str, format);
  };
  printf("j - %d, str[j] - %c\n", j, str[j]);
  va_end(args);
  return records;    /* возвращает число, равное количеству полей, значения которых были действи­тельно присвоены переменным. 
                  В это количество не входят поля, которые были считаны, но их значения не были ничему присвоены 
                  вследствие использования модификатора * для подавления присваивания. Если до присвоения значения 
                  первого поля произошла ошибка, возвращается EOF.
                */
}


int s21_switch_scan_spec(Prototype *prot, const char *format, const char *str, int *j, va_list args, int space_counter_for_n){
  
  // void *tmp_args = NULL;
  int width_counter = 0;
  int write_count = 0;
  char buff_str[4096] = {'\0'};

  if(prot -> width_number > 0){
    width_counter = prot -> width_number;
  } else {
    width_counter = INT_MAX;
  }
  printf("wn %d\n", prot -> width_number);
  switch (prot -> spec) {
  case 'd':
    write_count += scanf_spec_d(prot, str, buff_str, args, width_counter, j);
    *j += strlen(buff_str);

    // Проверить *

    printf("DD spec - %c, width_number - %d, * - :%c:, format - %s\n", prot -> spec, prot -> width_number, prot -> width_star, format);
    break;

  case 'c':
    write_count += scanf_spec_c(prot, str, buff_str, args, j);
    *j += strlen(buff_str);

    printf("CC spec - %c, width_number - %d, str - :%s:, buf - :%c:%d:\n", prot -> spec, prot -> width_number, str, buff_str[0], buff_str[0]);
    break;

  case 's':
    write_count += scanf_spec_s(prot, str, args, buff_str, width_counter, j);
    *j += strlen(buff_str);

    printf("SS spec - %c, width_number - %d, str - :%s:, buf - %s\n", prot -> spec, prot -> width_number, str, buff_str);
    break;
  
  case 'n':
    scanf_spec_n(args, j, space_counter_for_n);

    printf("NN spec - %c, width_number - %d, str - :%s:, format - %s\n", prot -> spec, prot -> width_number, str, format);
    break;

  default:
    break;
  };
  return write_count;
}

void scanf_spec_n(va_list args, int *j, int space_counter_for_n){
  int *p_args = NULL;
  p_args = va_arg(args, int*);
  printf("nJ - %d\n", *j - space_counter_for_n);
  *p_args = *j - space_counter_for_n;
}

int scanf_spec_s(Prototype *prot, const char *str, va_list args,  char *buff_str, int width_counter, int *j){
  char *p_args = NULL;
  int k = 0;
  if(prot -> width_star != '*') p_args = va_arg(args, char*);
  printf("S - %c\n", str[*j]);
  while(k < width_counter && strchr(SPACES, str[*j + k]) == NULL){
    buff_str[k] = str[*j + k];
    if(prot -> width_star != '*') *(p_args + k) = str[*j + k];
    k++;
    // printf("k - %d\n", k);
  };
  return 1;
}


int scanf_spec_c(Prototype *prot, const char *str,  char *buff_str, va_list args, int *j){
  char *p_args = NULL;
  int k = 0;

  if(prot -> width_star != '*') p_args = va_arg(args, char*);
  if(prot -> width_number <= 1){
    buff_str[k] = str[*j + k];
    // printf("p0 :%d:\n", *(p_args + k));
    printf("* %d\n", prot -> width_star);
    if(prot -> width_star != '*') {
      *p_args = str[*j];
      // printf("p :%d:\n", *(p_args + k));
      k++;
    }
  } else {
    while(k < prot -> width_number){
      buff_str[k] = str[*j + k];
      if(prot -> width_star != '*') {
        *(p_args + k) = str[*j + k];
        printf("p %c\n", *(p_args + k));
        k++;
      }
    };

  };
  return k;
}

int scanf_spec_d(Prototype *prot, const char *str,  char *buff_str, va_list args, int width_counter, int *j){
  void *p_args = NULL;
  int k = 0;
  int write_count = 0;
  long long int numb = 0;   // подумать, что сделать если первая сразу не цифра
  if(prot -> width_star != '*') p_args = va_arg(args, int*);
  if(str[*j + k] == '-'){
    buff_str[k] = str[*j + k];
    k++;
  };
  while(k < width_counter && strchr(SPACES, str[*j + k]) == NULL){
    if(isNumber(str[*j + k])){
      buff_str[k] = str[*j + k];
    } else {
      if(k == 0)  buff_str[k] = 0;   //  ??СДЕЛАТЬ АВАРИЙНЫЙ ЭКЗИТ  exit если первая не цифра;
      break;
    };
    // printf("%c", str[*j + k]);
    // printf("\n");
    k++;
  }

  numb = atoi(buff_str);
  if(prot -> length == 'l' && numb > LONG_MAX) numb = LONG_MAX;
  // Если *, то пропуск
  if(prot -> width_star != '*'){
    *(int *)p_args = numb;
    write_count = 1;
  };
  printf("WC %d", write_count);
  return write_count;
}

long long int atoi(char *str){
  long long int res = 0;
  int i = 0;
  int sign = 0;
  if(str[i] == 45) {
      i++;
      sign = 1;
  };
  for(int k=i; str[k] != '\0'; k++) {
    res = res*10;
    res = res + str[k] - '0';
  };
  if(sign == 1) res = res * (-1);
  return res;
}


int isNumber(char c) {
  int res = 0;
  if(c > 47 && c < 58) res = 1;
  return res;
}





int s21_read_format(Prototype *prot, const char *format, int i, va_list args) {
  int this_is_width = 0;
  int this_is_prec = 0;
  i++;
  while (format[i]) {
    // Check flags
    s21_check_flags(format, i, prot, &this_is_prec, &this_is_width);
    // Check width
    s21_check_width(format, i, &this_is_width, prot);
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
                     Prototype *prot) {
  if (s21_check_number(format, i) == true && *this_is_width == 0) {
    prot->width_number = s21_write_number(format, &i);
    *this_is_width = 1;
  } else if (prot->width_number == 0 && format[i] == '*' &&
             *this_is_width == 0) {
    // prot->width_star = va_arg(args, int);
    prot->width_star = '*';
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
