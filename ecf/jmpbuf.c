#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

int main()
{
  printf("sizeof(jmpbuf)=%d\n", (int) sizeof(jmp_buf));
  exit(0);
}
