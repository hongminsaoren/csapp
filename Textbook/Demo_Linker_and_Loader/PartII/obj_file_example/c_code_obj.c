#include <stdio.h>

int g_init_var1 = 1;
int g_uninit_var2;

void foo(int i)
{
    printf("%d",i);
}

int main(void)
{
    static int var3 = 2;
    static int var4;
    
    int x = 3;
    foo(x);
    return 0;
}




