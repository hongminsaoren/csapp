#include <stdio.h>

int main(int argc, char *argv[]) {
	
    extern char *optarg;
    extern int optind, opterr, optopt;

    int helpFlag = 0;
    int errorFlag = argc <= 4;
	
    char arg;
    float a = -1;
    float b = -1;
    float c = -1;

    while ((arg = getopt(, , "")) != ) {
        switch (arg) {
            case 'h':
                break;
            case 'a':
                break;
            case 'b':
                break;
            case 'c':
                break;
            case '?':
            default:
                errorFlag = 1;
                break;
        }
    }

    if (errorFlag || helpFlag) {
        fprintf(stderr, "usage: ...");
        exit(errorFlag);
    }

    if (a == -1 && b != -1 && c != -1) {
        printf("a = %f\n", );
    }
    else if (a != -1 && b == -1 && c != -1) {
        printf("b = %f\n", );
    }
    else if (a != -1 && b != -1 && c == -1) {
        printf("c = %f\n", );
    }
    else if (a != -1 && b != -1 && c != -1) {
        printf("Those values %s work\n", ( ) ? "do" : "don't");
    }

    return 0;
}

