#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//  a.out -a <a> -b <b> -n

int main(int argc, char** argv) {
    int opt;

    bool negate = false;
    int a = 15000;
    int b = 213;

    while ((opt = getopt(argc, argv, "na:b:")) > 0) {
        switch (opt) {
            case 'n':
                negate = true;
                break;

            case 'a':
                a = atoi(optarg);
                break;;

            case 'b':
                b = atoi(optarg);
                break;

            default:
                exit(1);
                break;
        }
    }

    int c = a + b;
    printf("%d + %d = %d\n", a, b, c);

    if (negate) {
        printf("Negating %d yields %d\n", c, c * -1);
        c *= -1;
    }

    printf("The result is %d.\n", c);

    return 0;
}
