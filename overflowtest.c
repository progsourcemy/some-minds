








/* compile with gcc -ftrapv overflowtest.c */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void procesig(int sig)
{
  printf("Overflow detected ---%d--- \r\n",sig); 
  /* exit(-1); */
}

int main()
{
  signal(SIGABRT, &procesig);
  int largeInt = 2147483647;
  int normalInt = 42;
  int overflowInt;
  overflowInt=largeInt + normalInt ;
  printf("111111\r\n"); 
  return 0;
}
