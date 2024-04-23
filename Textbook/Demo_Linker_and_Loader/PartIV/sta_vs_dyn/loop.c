#include <stdlib.h>

int main()
{
    void* pm = NULL;

    for(;;)
    {
       pm = malloc(100); 
       sleep(500);
       if(pm)
       {
           free(pm);
       }
    }
}
