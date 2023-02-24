#include "sub_func.h"

void shift_str(char *str, int size){
	for(int i = ans - 1; i > 0; -i){
		str[i] = str[i - 1];
	}
}

void UDecInNumSys(char *buff, unsigned long long int n, int mes, int flag){     //  изменил int n на long long int n
	int size_ans = 0;
	char str[2];
	str[0] = 'a';
	str[1] = 'A';
	while(n != 0){
		size_ans += 1;
		shift_str(buff, size_ans);
		if(n % mes > 9){
			buff[0] = n % mes - 10 + str[flag];    // поменял 'A' на 'a'
		}else{
			buff[0] = n % mes + '0';
		}
		n /= mes;
	}
	buff[size_ans] = '\0';
}

void s21_double_to_str(double num, char *str, int pres) {
	int count_before_dot = 0, index = 0;
	double num1 = 0, num2 = num;
	while(num >= 1){
		num /= 10;
		count_before_dot++;
	}
	for(int i = 0; i < count_before_dot; ++i){
		num *= 10;
		int y = (int)num;
		num1 = num1 * 10 + y;
		num -= y;
		str[index++] = y + '0';
	}
	if(count_before_dot == 0){
		str[index++] = '0';
	}
	str[index++] = '.';
	num2 -= num1;
	for(int i = 0; i < pres; ++i){
		num2 *= 10;
		int y = (int)num2;
		num2 -= y;
		str[index++] = y + '0';
	}


	num2 *= 10;
	int y = (int)num2;
	if(y >= 5){
		int trans = 1;
		for(int i = count_before_dot + pres; i > 0; --i){
			if(str[i] != '.'){
				int a = str[i] - '0';
				str[i] = (a + trans) % 10 + '0';
				trans = (a + 1) / 10;
			}
		}

		if(trans == 1 && str[0] == '9'){
			shift_str(str, count_before_dot + pres + 1);
			str[1] = '0';
			str[0] = '1';
		}
		else if(trans == 1){
			str[0] = str[0] + 1;
		}

	}
	str[index] = '\0';
}

void *s21_reverse (char *str) {   // str должен быть массивом или сделан через malloc, а не указателем char * на область памяти в стеке
    if(str == NULL) return NULL;
    int bgn = 0;
    int end = strlen(str) - 1;
    char temp;
    // printf("ee %s\n", str);
    // printf("d %d  %d\n", bgn, end);
    while(bgn < end) {
        temp = str[bgn];
        *(str + bgn) = *(str + end);
        *(str + end) = temp;
        bgn++;
        end--;
    }
    printf("ff %s\n", str);
    return str;
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
    printf("s21check: %s\n", str);
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
    printf("s21check: %s\n", str);
    return counter_symbols_str;
  }
  return flag_check_arg;
}

bool s21_mantisssa_and_degree(double *num, bool flag_zero, int *num_int, int *e,
                              Prototype *prot) {
  bool flag_zero_negative = false;
  if (*num == 0) flag_zero = true;
  if ((prot->spec == 'e' || prot->spec == 'E') &&
      (*num > -1 && signbit(*num) && *num < 0.0))
    flag_zero_negative = true;
  if ((prot->spec == 'g' || prot->spec == 'G') &&
      (*num > -1 && signbit(*num) && *num < 0.0))
    flag_zero_negative = true;
  *num_int = (int)*num;  // целая часть дробного числа
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

void s21_fractional_and_integer_part_of_a_number(int *num_int, double *num,
                                                 Prototype *prot,
                                                 bool flag_zero_negative,
                                                 bool flag_minus_num_g) {
  // Разбиваем дробное число на два интовых типа целое число и дробная часть
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

int s21_rounding_and_precision_number(
    double *num, int *multiply, Prototype *prot, double *save_number_for_g,
    int *e, int *check_g, int *precision, bool flag_zero_plus,
    bool flag_zero_negative, bool flag_g, int *save_precision_for_rounding_g) {
  // Тут идет округление числа если точность задана в else будет вызываться
  // функция точности
  // если после знака запятой будет < 6 цифр, то нужно округлять
  int flag = -1;
  int dont_write_number_with_point = 0;
  int counter_g_minus_e = 0;
  int counter_g_plus_e = 0;
  int counter_g_final_precison = 0;
  int save_precision_g = -1;
  bool flag_g_e_more_minus_four = false;
  bool this_is_used = false;
  if ((prot->spec == 'g' || prot->spec == 'G') && (*e >= -4 && *e <= 5)) {
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
  if (prot->prec_star != -1)
    *precision = prot->prec_star;
  else if (prot->prec_number != -1)
    *precision = prot->prec_number;
  if (prot->prec_number == 0 || prot->prec_star == 0) {
    dont_write_number_with_point = 1;
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
        }
        *precision -= counter_g_plus_e;
        *save_precision_for_rounding_g = *precision;
        flag = -1;
      }
      if (prot->length == 'L')
        *num = roundl(*num * pow(10, *precision + counter_g_final_precison)) /
               pow(10, *precision + counter_g_final_precison);
      else
        *num = round(*num * pow(10, *precision + counter_g_final_precison)) /
               pow(10, *precision + counter_g_final_precison);
      // multiply сделать для g
      if (this_is_used == true) {
        *save_number_for_g = *num;
      }
      for (int i = 0; i < *precision; i++) {
        *num *= 10;
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
      *num = (int)*num;  // получение дробного числа в виде инта
    }
  }
  return dont_write_number_with_point;
}

void s21_writing_int_number_with_point(int *num_int, int *symbol, char *str_int,
                                       bool flag_zero_negative,
                                       int *counter_symbols_str,
                                       int *dont_write_number_with_point,
                                       double *save_number_for_g, int *e,
                                       Prototype *prot, int *num_i_g,
                                       bool flag_minus_num) {
  // Записываем целое число в массив char в виде "-4." если целое число
  // отрицательное. "4." если число положительное
  bool check_g = false;
  double send_to_function_num = 0;
  if ((prot->spec == 'g' || prot->spec == 'G') && (*e >= -4 && *e <= 5)) {
    *num_int = (int)*save_number_for_g;
    check_g = true;
  }
  if (check_g == true) {
    *symbol = *num_int;
    send_to_function_num = *symbol;
  } else
    *symbol = *num_int % 10;
  if (*dont_write_number_with_point == 1) {
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
        *num_i_g = s21_double_to_str(send_to_function_num, str_int, 0);
        if (*num_i_g == 0 && send_to_function_num >= 0 &&
            flag_zero_negative == false) {
          str_int[0] = '0';
          str_int[1] = '.';
        } else {
          s21_reverse(str_int);
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
          int counter = 10;
          flag_minus_num = true;
          send_to_function_num *= -1;
          *num_i_g = s21_double_to_str(send_to_function_num, str_int, 0);
          s21_reverse(str_int);
          s21_check_fractional_number_for_zeros(&counter, str_int,
                                                flag_minus_num);
          str_int[*num_i_g + 1] = '.';
        }
        if (*num_i_g == 6) str_int[*num_i_g] = '\0';
      } else {
        str_int[0] = *symbol + '0';
        str_int[1] = '.';
        *counter_symbols_str += 2;
      }
    }
  }
}

int s21_concat_fractional_number_with_degree(
    int num_i, int counter_symbols_str, char *str_double, double num,
    Prototype *prot, char symbol_e, int e, char *str_degree,
    int *dont_write_number_with_point) {
  // Записываем дробную часть числа в массив char и соединяем дробную число
  // с степенью
  if (*dont_write_number_with_point != 1) {
    num_i = s21_double_to_str(num, str_double, num_i);
    s21_reverse(str_double);
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
    s21_double_to_str(e, str_degree, 0);
    s21_reverse(str_degree);
  } else {
    str_double[num_i + 2] = '0';
    counter_symbols_str++;
  }
  if (e == 0) {
    str_double[num_i + 3] = '0';
    counter_symbols_str++;
  } else {
    if (e < 0) e *= -1;
    s21_double_to_str(e, str_degree, 0);
    s21_reverse(str_degree);
    s21_strcat(str_double, str_degree);  // соединяем число с степенью
  }
  return counter_symbols_str;
}

void s21_check_fractional_number_for_zeros(int *multiply, char *str_double,
                                           bool flag_minus_num) {
  // Проверка на то,что есть ли в дробной части нули
  // Обнулить bool minus_num потому что эту функцию еще раз вызываю
  while (*multiply >= 10) {
    int check = s21_strlen(str_double) - 1;
    for (; check >= 0; check--) {
      str_double[check + 1] = str_double[check];
    }
    if (flag_minus_num == true) {
      str_double[0] = '-';
    } else
      str_double[0] = '0';
    *multiply /= 10;
  }
}
