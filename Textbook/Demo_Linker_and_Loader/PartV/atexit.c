#include <stdio.h>

void post(void)
{
    printf("goodbye!\n");
}

int main()
{
    atexit(&post);
    printf("exiting from main\n");
}
