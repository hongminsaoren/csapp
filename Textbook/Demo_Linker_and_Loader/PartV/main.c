#include <stdio.h>
#include <stdlib.h>

int var_before_main = 1;

int main(int argc, char* argv[])
{
    printf("entry main\n");
    char* p = (char*)malloc(sizeof(char));
    if(p)
    { 
      free(p);
    }
}



