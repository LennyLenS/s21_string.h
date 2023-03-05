#include <stdarg.h>
#include <string.h>
#include <math.h>
#include "s21_specifiers.h"

int specifier_f(char *buff, va_list args, Prototype prot){
	if(prot.prec_number == -1){
		prot.prec_number = 6;
	}
	if(prot.length == 'L'){
		long double a = va_arg(args, long double);
		s21_double_to_str(a, buff, prot.prec_number, prot.sharp_flag);
	}
	else{
		double a = va_arg(args, double);
		s21_double_to_str(a, buff, prot.prec_number, prot.sharp_flag);
	}
	return s21_strlen(buff);
}


int specifier_o(char *buff, va_list args, Prototype prot){
	if(prot.length == 'l'){
		unsigned long int num = va_arg(args, unsigned long int);
        if(num == 0 && prot.prec_number == 0 && prot.width_number == 0){
            buff[0] = '\0';
        }else if(!(num == 0 && prot.prec_number == 0)){
		    UDecInNumSys(buff, num, 8, 0);
        }else{
            buff[0] = ' ';
        }
	}
	else{
		unsigned int num = va_arg(args, unsigned int);
        if(num == 0 && prot.prec_number == 0 && prot.width_number == 0){
            buff[0] = '\0';
        }else if(!(num == 0 && prot.prec_number == 0)){
		    UDecInNumSys(buff, num, 8, 0);
        }else{
            buff[0] = ' ';
        }
	}

	return s21_strlen(buff);
}

int specifier_u(char *buff, va_list args, Prototype prot){
	if(prot.length == 'l'){
		unsigned long int num = va_arg(args, unsigned long int);
        if(num == 0 && prot.prec_number == 0 && prot.width_number == 0){
            buff[0] = '\0';
        }else if(!(num == 0 && prot.prec_number == 0)){
		    UDecInNumSys(buff, num, 10, 0);
        }else{
            buff[0] = ' ';
        }
	}
	else{
		unsigned int num = va_arg(args, unsigned int);
        if(num == 0 && prot.prec_number == 0 && prot.width_number == 0){
            buff[0] = '\0';
        }else if(!(num == 0 && prot.prec_number == 0)){
		    UDecInNumSys(buff, num, 10, 0);
        }else{
            buff[0] = ' ';
        }
	}
	return s21_strlen(buff);
}

int specifier_X(char *buff, va_list args, Prototype prot){
	if(prot.length == 'l'){
		unsigned long int num = va_arg(args, unsigned long int);
        if(num == 0 && prot.prec_number == 0 && prot.width_number == 0){
            buff[0] = '\0';
        }else if(!(num == 0 && prot.prec_number == 0)){
		    UDecInNumSys(buff, num, 16, 1);
        }else{
            buff[0] = ' ';
        }
	}
	else{
		unsigned int num = va_arg(args, unsigned int);
        if(num == 0 && prot.prec_number == 0 && prot.width_number == 0){
            buff[0] = '\0';
        }else if(!(num == 0 && prot.prec_number == 0)){
		    UDecInNumSys(buff, num, 16, 1);
        }else{
            buff[0] = ' ';
        }
	}

	return s21_strlen(buff);
}

int specifier_x(char *buff, va_list args, Prototype prot){
	if(prot.length == 'l'){
		unsigned long int num = va_arg(args, unsigned long int);
        if(num == 0 && prot.prec_number == 0 && prot.width_number == 0){
            buff[0] = '\0';
        }else if(!(num == 0 && prot.prec_number == 0)){
		    UDecInNumSys(buff, num, 16, 0);
        }else{
            buff[0] = ' ';
        }
	}
	else{
		unsigned int num = va_arg(args, unsigned int);
        if(num == 0 && prot.prec_number == 0 && prot.width_number == 0){
            buff[0] = '\0';
        }else if(!(num == 0 && prot.prec_number == 0)){
		    UDecInNumSys(buff, num, 16, 0);
        }else{
            buff[0] = ' ';
        }
	}

	return s21_strlen(buff);
}

int s21_spec_p(va_list args, char *charbuf, Prototype *prot){
    void *num = va_arg(args, void*);
    char buff[512] = {'\0'};
    long long int num2 = (long long int)num;
    if(num == S21_NULL) num2 = 0;
    int i = 0;
    UDecInNumSys(buff, num2, 16, 0);

    int p_len = s21_strlen(buff);
    int space_len = 0;
    int zero_len = 0;
    if(prot->prec_number > p_len) zero_len = prot->prec_number - p_len;
    if(prot->width_number > p_len + zero_len + 2) space_len = prot->width_number - (p_len + zero_len + 2);

    if(prot->minus_flag != 1){
        for(int k = 0; k < space_len; k++){
            *(charbuf + i) = ' ';
            i++;
        };
    }

    s21_strcat(charbuf, "0x");
    i +=2;

    for(int k = 0; k < zero_len; k++){
        *(charbuf + i) = '0';
        i++;
    };

    s21_strcat(charbuf, buff);
    i += p_len;
    if(prot->minus_flag == 1){
        for(int k = 0; k < space_len; k++){
            *(charbuf + i) = ' ';
            i++;
        };
    }
    return s21_strlen(charbuf);
}




void s21_spec_n(va_list args, int j){
    int *var = va_arg(args, int*);
    *var = j;
}

int s21_spec_id(va_list args, Prototype *prot, char *charbuf) {
    __int128_t num = 0;
    int neg_flag = 0;
    if(prot->length == 'h'){
        num = (short)va_arg(args, int);
    } else if(prot->length == 'l'){
        num = va_arg(args, long int);
    } else {
        num = va_arg(args, int);
    };

    int num_i = 0;

    if(num < 0){
        neg_flag = 1;
        num *= -1;
        charbuf[num_i] = '-';
        num_i = 1;
    }

    if(num == 0){
        if (prot->prec_number == 0) {
            charbuf[num_i] = '\0';
        num_i++;
        } else {
            charbuf[num_i] = '0';
        num_i++;
        }
        
    } else {
        while (num > 0){
            int tmp_dig = 0;
            tmp_dig = num%10;
            num = num / 10;
            charbuf[num_i] = tmp_dig + '0';
            num_i++;
        }
    }

    s21_reverse(charbuf, neg_flag);
    return num_i;
}



int s21_spec_s(char *str, va_list args, Prototype *prot) {
    int i = 0;
    int len = 0;
   // int sp_qnt = 0;
    char *strng_arg = va_arg(args, char*);

    if(strng_arg == S21_NULL){
      if (prot->prec_number == 0) {
         i += prep_string(str, strng_arg, prot->prec_number, i);
      } else {
         s21_strncpy(str, "(null)", fmin(6, prot->prec_number));
      } 
        return 2;
    }

    
    len = (int)s21_strlen(strng_arg);
    
  //  if(strng_arg == S21_NULL){
  //       s21_strcpy(str, "(null)");
  //   } else
   if (prot->prec_number < len && prot->prec_number != -1 ) {
       i += prep_string(str, strng_arg, prot->prec_number, i);
   } else if (prot->prec_number == 0) {
       i += prep_string(str, strng_arg, prot->prec_number, i);
   } else if (len <= prot->prec_number  || prot->prec_number == -1 ) {
       i += prep_string(str, strng_arg, len, i);
   }
 
    return i;
}


int s21_spec_c(char *str, va_list args, Prototype *prot) {
    char c = va_arg(args, int);
    // if(c == '\0') c = 0;
    //  printf(":%d:\n", c);
    int sp_qnt = 0;
    int i = 0;
    int ret = 0;
    if(prot->width_number > 0){
        sp_qnt = prot->width_number -1;
    };
    if(prot->minus_flag == 1){
        str[i] = c;
        i++;
        i += print_spaces(str, sp_qnt, i);
    } else {
        i += print_spaces(str, sp_qnt, i);
        str[i] = c;
        i++;
    };
    if(c == 0) ret = -1;
    // printf("i :%d: s:%d:\n", i, str[i]);
    return ret;
}


// ----------------------------- Artem func start -----------------------------


int s21_spec_e(int counter_symbols_str, char *str, char *intermediate_str,
               va_list args, Prototype *prot) {
  int e = 0;
  long long int num_int = 0;
  int symbol = 0;
  int num_i = 0;
  char str_int[512] = {'\0'};
  char str_double[270] = {'\0'};
  char str_double_g[270] = {'\0'};
  char symbol_e = '\0';
  char str_degree[560] = {'\0'};
  // char *res;
  bool flag_zero = false;
  bool flag_zero_negative = false;
  bool flag_zero_plus = false;
  bool flag_minus_num = false;
  bool flag_minus_num_g = false;
  bool check_num_i_g = false;
  bool flag_g = false;
  bool this_is_used = false;
  bool flag_g_prec_1 = true;
  int save_precision_g_1 = 0;
  int have_precision_g = 0;
  unsigned long int multiply = 1;
  int dont_write_number_with_point = 0;
  int check_g = 0;
  int precision = 6;
  int save_precision_for_rounding_g = 0;
  int save_multiply = 0;
  int save_degree = 0;
  unsigned long int multiply_for_fractional_num = 1;
  long int multiply_num_i_g = 1;
  int num_i_g = 0;
  double num = 0.;
  if (prot->length == 'L')
    num = va_arg(args, long double);
  else
    num = va_arg(args, double);
  double save_number_for_g = num;
  if (s21_check_arg(prot, counter_symbols_str, str, num) != 0) {
    s21_strcat(intermediate_str, str);
    return counter_symbols_str;
  }
  if (prot->spec == 'g' || prot->spec == 'G') flag_g = true;
  if ((prot->spec == 'e' || prot->spec == 'E') && (num < 1 && num > 0.0) &&
      flag_zero_plus == false)
    flag_zero_plus = true;
  if ((prot->spec == 'g' || prot->spec == 'G') && (num < 1 && num > 0.0) &&
      flag_zero_plus == false)
    flag_zero_plus = true;
  if ((prot->spec == 'g' || prot->spec == 'G') && (num < 0))
    flag_minus_num_g = true;
  flag_zero_negative =
      s21_mantisssa_and_degree(&num, flag_zero, &num_int, &e, prot);
  if (num_int == 0 && (prot->spec == 'g' || prot->spec == 'G')) {
    str_int[0] = '0';
    s21_strcat(intermediate_str, str_int);
    //printf("Finally1: %s\n", intermediate_str);
    return counter_symbols_str;
  }
  if (flag_g == true && 1 > e && e >= -4 &&
      (prot->prec_number == 1 || prot->prec_star == 1))
    flag_g_prec_1 = false;
  // ------------------------------------------ если .0 тут проверку сделать num
  if (prot->prec_number == 0 || prot->prec_star == 0)
    num = round(num * pow(10, 0)) / pow(10, 0);
  else if ((prot->prec_number == 1 || prot->prec_star == 1) &&
           (flag_g_prec_1 = true))
    num = round(num * pow(10, 0)) / pow(10, 0);
  s21_fractional_and_integer_part_of_a_number(
      &num_int, &num, prot, flag_zero_negative, flag_minus_num_g);
  // при точности десять баг не выводит дробную часть
  dont_write_number_with_point = s21_rounding_and_precision_number(
      &num, &multiply, prot, &save_number_for_g, &e, &check_g, &precision,
      flag_zero_plus, flag_zero_negative, flag_g,
      &save_precision_for_rounding_g, this_is_used, &have_precision_g,
      &save_precision_g_1, &save_degree, &num_int);
  if (check_g != 1) {
    s21_writing_int_number_with_point(
        &num_int, &symbol, str_int, flag_zero_negative, &counter_symbols_str,
        &dont_write_number_with_point, &save_number_for_g, prot, &num_i_g,
        flag_minus_num, &have_precision_g, &save_precision_g_1, &save_degree,
        &e);
    counter_symbols_str = s21_concat_fractional_number_with_degree(
        num_i, counter_symbols_str, str_double, num, prot, symbol_e, e,
        str_degree, &dont_write_number_with_point);
    s21_check_fractional_number_for_zeros(&multiply, str_double, flag_minus_num,
                                          flag_g, this_is_used);

    s21_strcat(str_int, str_double);  // соединяем 2 строки получаем число
    s21_strcat(intermediate_str,
               str_int);  // закидываем готовый результат в промежуточную строку
  } else {
    s21_writing_int_number_with_point(
        &num_int, &symbol, str_int, flag_zero_negative, &counter_symbols_str,
        &dont_write_number_with_point, &save_number_for_g, prot, &num_i_g,
        flag_minus_num, &have_precision_g, &save_precision_g_1, &save_degree,
        &e);
    save_multiply = multiply;
    precision++;
    s21_check_fractional_number_for_zeros(&multiply, str_double, flag_minus_num,
                                          flag_g, this_is_used);
    while (precision > 0 && multiply != 1) {
      precision--;
      save_multiply *= 10;
    }
    //  Разобраться с дробной частью частью когда степень e положительная

    save_number_for_g *= save_multiply;
    // Разобраться с точностью
    if (num_i_g == 0) {
      while (precision > 0) {
        precision--;
        multiply_for_fractional_num *= 10;
      }
    } else
      num_i_g = precision - num_i_g;
    if (num_i_g != 0) {
      while (num_i_g > 0) {
        num_i_g--;
        multiply_num_i_g *= 10;
      }
      check_num_i_g = true;
    }
    s21_fractional_and_integer_part_of_a_number(&num_int, &save_number_for_g,
                                                prot, flag_zero_negative,
                                                flag_minus_num_g);
    if (save_multiply != 1) {
      multiply_num_i_g /= save_multiply;
      save_precision_for_rounding_g = 0;
    }
    if (num_i_g == 0 && check_num_i_g == false)
      save_number_for_g *= multiply_for_fractional_num;
    // ТУТ ТОЖЕ НАДО ОКРУГЛЯТЬ
    else {
      save_number_for_g *= multiply_num_i_g;
      save_number_for_g =
          round(save_number_for_g * pow(10, save_precision_for_rounding_g)) /
          pow(10, save_precision_for_rounding_g);
    }
    save_number_for_g = (long int)save_number_for_g;
    // if (save_number_for_g < 0) save_number_for_g *= -1;
    s21_double_to_str_artem(save_number_for_g, str_double_g, num_i);
    s21_reverse_artem(str_double_g);
    s21_strcat(str_double, str_double_g);
    s21_strcat(str_int, str_double);
    // убираем незначащие нули
    int counter_g_leading_zeros = 0;
    int counter_g_prec = 0;
    bool this_is_zero = false;
    bool this_is_int = false;
    // Мб for надо убрать
    if (str_int[counter_g_prec] == '-' && str_int[counter_g_prec + 1] == '.') {
      counter_g_leading_zeros += 1;
      this_is_zero = true;
      this_is_int = true;
    } else if (str_int[counter_g_prec] == '-')
      counter_g_prec += 1;
    while (this_is_int == false && this_is_zero == false) {
      if (str_int[counter_g_prec] != '.') {
        counter_g_leading_zeros += 1;
        counter_g_prec += 1;
      } else {
        counter_g_prec += 1;
        this_is_int = true;
      }
    }
    if (have_precision_g == 0) {
      save_precision_g_1 = 6;
      save_precision_g_1 -= counter_g_leading_zeros;
    } else
      save_precision_g_1 -= counter_g_leading_zeros;
    for (int i = 1; i <= save_precision_g_1; i++) {
      if (str_int[counter_g_prec] != '\0') counter_g_prec++;
      // if (str_int[counter_g_prec] != '0')
    }
    counter_g_prec--;
    bool this_is_not_zero = false;
    while (this_is_not_zero == false) {
      if (str_int[counter_g_prec] == '0') {
        counter_g_prec--;
      } else
        this_is_not_zero = true;
    }
    if (this_is_not_zero == true) {
      str_int[counter_g_prec + 1] = '\0';
    }
    s21_strcat(intermediate_str, str_int);
  }

  //printf("Дробная часть %s\n", str_double);
  //printf("Finally1: %s\n", intermediate_str);
  // Вызываем функцию Юли
  // s21_strcat(intermediate_str, res);
  // Считаем кол-во символов
  // Возвращаем кол-во символов в строке
  // Объединить intermediate_str
  // printf("intermediate_str: %s\n", intermediate_str);
  return counter_symbols_str;
}

int s21_check_arg(Prototype *prot, int counter_symbols_str, char *str,
                  double num) {
  int flag_check_arg = 0;
  if (num == INFINITY || num == -INFINITY) {
    int counter = 0;
    if (num == -INFINITY) {
      str[counter_symbols_str] = '-';
      counter++;
    }
    if (prot->spec == 'E' || prot->spec == 'G') {
      str[counter_symbols_str + counter] = 'I';
      str[counter_symbols_str + counter + 1] = 'N';
      str[counter_symbols_str + counter + 2] = 'F';
    } else {
      str[counter_symbols_str + counter] = 'i';
      str[counter_symbols_str + counter + 1] = 'n';
      str[counter_symbols_str + counter + 2] = 'f';
    }
    if (counter > 0)
      counter_symbols_str += 4;
    else
      counter_symbols_str += 3;
    // printf("s21check: %s\n", str);
    return counter_symbols_str;
  }
  if (s21_isnan(num) == 1) {
    if (prot->spec == 'E' || prot->spec == 'G') {
      str[counter_symbols_str] = 'N';
      str[counter_symbols_str + 1] = 'A';
      str[counter_symbols_str + 2] = 'N';
    } else {
      str[counter_symbols_str] = 'n';
      str[counter_symbols_str + 1] = 'a';
      str[counter_symbols_str + 2] = 'n';
    }
    counter_symbols_str += 3;
    // printf("s21check: %s\n", str);
    return counter_symbols_str;
  }
  return flag_check_arg;
}

bool s21_mantisssa_and_degree(double *num, bool flag_zero,
                              long long int *num_int, int *e, Prototype *prot) {
  bool flag_zero_negative = false;
  if (*num == 0) flag_zero = true;
  if ((prot->spec == 'e' || prot->spec == 'E') &&
      (*num > -1 && signbit(*num) && *num < 0.0))
    flag_zero_negative = true;
  if ((prot->spec == 'g' || prot->spec == 'G') &&
      (*num > -1 && signbit(*num) && *num < 0.0))
    flag_zero_negative = true;
  *num_int = (long long int)*num;  // целая часть дробного числа
  // Мантисса + подсчет степени
  if (*num >= 1 || *num <= -1 || flag_zero == true) {
    if ((*num_int >= 10 || *num_int <= -10)) {
      do {
        *num /= 10;
        *e += 1;
      } while (*num > 10 || *num < -10);
    }

  } else {
    do {
      *num *= 10;
      *e -= 1;
      *num_int = (int)*num;
    } while (*num_int == 0 && flag_zero == false);
  }
  return flag_zero_negative;
}
void s21_fractional_and_integer_part_of_a_number(long long int *num_int,
                                                 double *num, Prototype *prot,
                                                 bool flag_zero_negative,
                                                 bool flag_minus_num_g) {
  // Разбиваем дробное число на два интовых типа целое число и дробная часть
  // здесь фиксить баг с точностью 1
  *num_int = (int)*num;
  if (*num_int >= 0)
    *num -= *num_int;
  else {
    *num *= -1;
    *num += *num_int;
  }
  if ((prot->spec == 'g' || prot->spec == 'G') && flag_zero_negative == true &&
      flag_minus_num_g == true)
    *num *= -1;
  // else {
  //   *num *= -1;
  //   *num += *num_int;
  // }
}
// Передавть num_int
int s21_rounding_and_precision_number(
    double *num, unsigned long int *multiply, Prototype *prot,
    double *save_number_for_g, int *e, int *check_g, int *precision,
    bool flag_zero_plus, bool flag_zero_negative, bool flag_g,
    int *save_precision_for_rounding_g, bool this_is_used,
    int *have_precision_g, int *save_precision_g_1, int *save_degree,
    long long int *num_int) {
  // Тут идет округление числа если точность задана в else будет вызываться
  // функция точности
  // если после знака запятой будет < 6 цифр, то нужно округлять
  (void)num_int;
  long long int flag = -1;
  int dont_write_number_with_point = 0;
  int counter_g_minus_e = 0;
  int counter_g_plus_e = 0;
  int counter_g_final_precison = 0;
  int save_precision_g = -1;
  double check_fractional_num_from_zeros_g = 0;
  double check_fractional_num_g = 0;
  bool flag_g_e_more_minus_four = false;
  bool this_is_prec_with_zeros = false;

  if (prot->prec_star != -1) {
    *precision = prot->prec_star;
    *save_precision_g_1 = *precision;
    *have_precision_g = 1;
  } else if (prot->prec_number != -1) {
    *precision = prot->prec_number;
    *save_precision_g_1 = *precision;
    *have_precision_g = 1;
  }
  *save_degree = *e;
  if ((prot->spec == 'g' || prot->spec == 'G') &&
      ((*e >= -4 && *e <= 5 && (*have_precision_g == 0)) ||
       (*precision > *e && *e >= -4 && *have_precision_g == 1))) {
    flag_g_e_more_minus_four = true;
    *num = *save_number_for_g;
    while (*e < 0) {
      *e += 1;
      counter_g_minus_e++;
    }
    if (counter_g_minus_e > 0) counter_g_final_precison = counter_g_minus_e;
  }
  if (flag_g_e_more_minus_four == true) {
    *num = *save_number_for_g;
    *check_g = 1;
  }
  if (prot->prec_number == 0 || prot->prec_star == 0) {
    dont_write_number_with_point = 1;
    if (prot->spec == 'g' || prot->spec == 'G') *save_number_for_g = *num_int;
  } else {
    if (prot->prec_number == -1 || prot->prec_star == -1) {
      if (prot->spec == 'g' || prot->spec == 'G') {
        *precision -= 1;
        save_precision_g = *precision;
      }
      if (counter_g_minus_e == 0 && flag_g_e_more_minus_four == true) {
        this_is_used = true;
        *precision += 1;
        flag = (int)*num;
        if (flag < 0) flag *= -1;
        while (flag > 0) {
          flag /= 10;
          counter_g_plus_e++;
        }  // придумать че делать если в дробной части < 3-ех
        check_fractional_num_g = *save_number_for_g;
        s21_fractional_and_integer_part_of_a_number(
            &flag, &check_fractional_num_g, prot, 0, 0);

        *precision -= counter_g_plus_e;
        check_fractional_num_from_zeros_g = *save_number_for_g;
        for (int i = 0; i < *precision; i++)
          check_fractional_num_from_zeros_g *= 10;
        // Здесь баг
        if ((int)check_fractional_num_from_zeros_g % 10 != 0)
          this_is_prec_with_zeros = true;
        int counter = *precision;
        for (int i = 0; i < counter && this_is_prec_with_zeros == false; i++) {
          check_fractional_num_g *= 10;
          if ((int)check_fractional_num_g % 10 == 0) *precision -= 1;
        }
        *save_precision_for_rounding_g = *precision;
        flag = -1;
      }
      if (prot->length == 'L')
        *num = roundl(*num * pow(10, *precision + counter_g_final_precison)) /
               pow(10, *precision + counter_g_final_precison);
      else
        *num = round(*num * pow(10, *precision + counter_g_final_precison)) /
               pow(10, *precision + counter_g_final_precison);
      if (flag_g == true && *check_g == 0)
        *num = round(*num * pow(10, *precision + counter_g_final_precison)) /
               pow(10, *precision + counter_g_final_precison);
      // multiply сделать для g
      if (this_is_used == true) {
        *save_number_for_g = *num;
      }
      for (int i = 0; i < *precision; i++) {
        // int counter = 0;
        *num *= 10;
        // баг с большим числом
        flag = (int)*num;
        if ((flag_zero_negative == false && flag_zero_plus == false &&
             flag_g == true) &&
            flag % 10 == 0)
          *multiply *= 10;
        if (flag == 0) *multiply *= 10;
      }
      if (this_is_used == true) {
        *precision = save_precision_g;  // сохранение точности
      }
      if (flag_g == true && *check_g == 0)
        *num = round(*num * pow(10, 0)) / pow(10, 0);
      if (*num < 0) *num = fabs(*num);
      *num = (unsigned long int)*num;  // получение дробного числа в виде инта
    }
  }
  return dont_write_number_with_point;
}
void s21_writing_int_number_with_point(
    long long int *num_int, int *symbol, char *str_int, bool flag_zero_negative,
    int *counter_symbols_str, int *dont_write_number_with_point,
    double *save_number_for_g, Prototype *prot, int *num_i_g,
    bool flag_minus_num, int *have_precision_g, int *save_precision_g_1,
    int *save_degree, int *e) {
  // Записываем целое число в массив char в виде "-4." если целое число
  // отрицательное. "4." если число положительное
  //(void)*save_number_for_g;
  bool check_g = false;
  double send_to_function_num = 0;
  if ((prot->spec == 'g' || prot->spec == 'G') &&
      ((*save_degree >= -4 && *save_degree <= 5 &&
        (prot->prec_number == -1 || prot->prec_star == -1)) ||
       (*save_precision_g_1 > *save_degree && *save_degree >= -4 &&
        (prot->prec_number != -1 || prot->prec_star != -1)))) {
    // 838 точность 2 неверно 838 точность 3 верно
    if (*save_precision_g_1 <= *e && *save_precision_g_1 != 0)
      *num_int = *num_int % 10;
    else
      *num_int = (int)*save_number_for_g;
    check_g = true;
  }
  if (check_g == true) {
    *symbol = *num_int;
    send_to_function_num = *symbol;
  } else
    *symbol = *num_int % 10;
  if (*dont_write_number_with_point == 1) {
    if (*symbol < 0) {
      *symbol *= -1;
      str_int[0] = '-';
      str_int[1] = *symbol + '0';
    } else
      str_int[0] = *symbol + '0';
  } else {
    if ((*symbol < 0 || flag_zero_negative == true) &&
        check_g == false) {  // если e будет мб ошибка
      *symbol *= -1;
      str_int[0] = '-';
      str_int[1] = *symbol + '0';
      str_int[2] = '.';
      *counter_symbols_str += 3;
    } else {
      if (check_g == true) {
        *num_i_g = s21_double_to_str_artem(send_to_function_num, str_int, 0);
        if (*num_i_g == 0 && send_to_function_num >= 0 &&
            flag_zero_negative == false) {
          str_int[0] = '0';
          str_int[1] = '.';
        } else {
          s21_reverse_artem(str_int);
          if (flag_zero_negative == false && send_to_function_num >= 0)
            str_int[*num_i_g] = '.';
        }
        if (flag_zero_negative == true) {
          send_to_function_num *= -1;
          str_int[0] = '-';
          str_int[1] = '0';
          str_int[2] = '.';
        }
        if ((*num_i_g == 0 && send_to_function_num < 0) &&
            flag_zero_negative == false) {
          unsigned long int counter = 10;
          flag_minus_num = true;
          send_to_function_num *= -1;
          *num_i_g = s21_double_to_str_artem(send_to_function_num, str_int, 0);
          s21_reverse_artem(str_int);
          s21_check_fractional_number_for_zeros(&counter, str_int,
                                                flag_minus_num, 0, 0);
          str_int[*num_i_g + 1] = '.';
        }
        if ((*num_i_g == 6 && *have_precision_g == 0) ||
            (*num_i_g == *save_precision_g_1 && *have_precision_g == 1)) {
          if (str_int[0] == '-') *num_i_g += 1;
          str_int[*num_i_g] = '\0';
        }
      } else {
        str_int[0] = *symbol + '0';
        str_int[1] = '.';
        *counter_symbols_str += 2;
      }
    }
  }
  // дописать для G
  if ((*num_i_g == 6 && *have_precision_g == 0 &&
       (prot->spec == 'g' || prot->spec == 'G')) ||
      ((*num_i_g == *save_precision_g_1 && *have_precision_g == 1) &&
       (prot->spec == 'g' || prot->spec == 'G')))
    str_int[*counter_symbols_str - 1] = '\0';
}

int s21_concat_fractional_number_with_degree(
    int num_i, int counter_symbols_str, char *str_double, double num,
    Prototype *prot, char symbol_e, int e, char *str_degree,
    int *dont_write_number_with_point) {
  // Записываем дробную часть числа в массив char и соединяем дробную число
  // с степенью
  if (*dont_write_number_with_point != 1) {
    num_i = s21_double_to_str_artem(num, str_double, num_i);
    s21_reverse_artem(str_double);
  }
  if (prot->spec == 'E' || prot->spec == 'G')
    symbol_e = 'E';
  else
    symbol_e = 'e';
  str_double[num_i] = symbol_e;
  counter_symbols_str++;
  if (e >= 0) {
    str_double[num_i + 1] = '+';
    counter_symbols_str++;
  }
  if (e < 0) {
    str_double[num_i + 1] = '-';
    counter_symbols_str++;
  }
  if (e >= 10) {
    s21_double_to_str_artem(e, str_degree, 0);
    s21_reverse_artem(str_degree);
  } else {
    str_double[num_i + 2] = '0';
    counter_symbols_str++;
  }
  if (e == 0) {
    str_double[num_i + 3] = '0';
    counter_symbols_str++;
  } else {
    if (e < 0) e *= -1;
    s21_double_to_str_artem(e, str_degree, 0);
    s21_reverse_artem(str_degree);
    s21_strcat(str_double, str_degree);  // соединяем число с степенью
  }
  return counter_symbols_str;
}

void s21_check_fractional_number_for_zeros(unsigned long int *multiply,
                                           char *str_double,
                                           bool flag_minus_num, bool flag_g,
                                           bool this_is_used) {
  // Проверка на то,что есть ли в дробной части нули
  // Обнулить bool minus_num потому что эту функцию еще раз вызываю
  (void)flag_g;
  (void)this_is_used;
  while (*multiply >= 10) {
    int check = s21_strlen(str_double) - 1;
    for (; check >= 0; check--) {
      str_double[check + 1] = str_double[check];
    }
    if (flag_minus_num == true) {
      str_double[0] = '-';
    } else
      // if(flag_g == true  && this_is_used == true){

      // }
      // else{
      //   str_double[0] = '0';
      // }
      str_double[0] = '0';
    *multiply /= 10;
  }
}

// ----------------------------- Artem func end -----------------------------
