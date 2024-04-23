#include <stdio.h>
#define MACRO 4

int main()
{
   int i;
   printf("Hello World\n");
   i = MACRO; /* this is comment line */
   #include "const_table.h"
   return 0;
}
