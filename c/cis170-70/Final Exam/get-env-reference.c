#include <stdio.h>
#include <stdlib.h>
int main()
{
printf("test\n");
const char* s = getenv("PS1");
printf("PS1 :%s\n",(s!=NULL)? s : "getenv returned NULL");
printf("end test\n");

printf("\033[1;31m");
  printf("Hello world\n");
  printf("\033[0m;");
  return 0;
}
