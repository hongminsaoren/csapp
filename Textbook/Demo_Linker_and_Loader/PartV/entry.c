#include <stdio.h>

__attribute((constructor)) void before_main() 
{ printf("%s\n",__FUNCTION__); }

int main() {
    printf("%s\n",__FUNCTION__);
}
