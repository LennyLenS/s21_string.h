#include <stdio.h>
#include <string.h>
#include "s21_sprintf.h"
int main()
{
 char str1[100];
  char str2[100];
  char *str3 = "%o Test %o Te%-+#nst %o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int valn1 = 0, valn2 = 0;

// sprintf(str1, str3, val, val2, &valn1, val3);
// s21_sprintf(str2, str3, val, val2, &valn2, val3);

//   sprintf(str1, str3, num, num, num);
//   s21_sprintf(str2, str3, num, num, num);

   int a = sprintf(str1, str3, val, val2, &valn1, val3);
   int b = s21_sprintf(str2, str3, val, val2, &valn2, val3);
   
   printf("#%s#\n#%s#\n", str1, str2);
   printf("%d %d", (int)strlen(str1), (int)strlen(str2));
}