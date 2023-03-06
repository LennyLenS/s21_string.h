#include <stdio.h>
#include <string.h>
#include "s21_sprintf.h"
int main()
{

  char str1[100];
  char str2[100];
  char *str3 = "Test %ls Test2";
  wchar_t *val[] = L"3wtf80";
  sprintf(str1, str3, val);
  s21_sprintf(str2, str3, val);

   printf("#%s#\n#%s#\n", str1, str2);
   printf("%d %d", (int)strlen(str1), (int)strlen(str2));
}

// 72363107597385858