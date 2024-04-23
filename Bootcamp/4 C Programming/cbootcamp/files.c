#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *infile = fopen("in.txt", "r");
    if (!infile) {
        fprintf(stderr, "cannot open in.txt for reading\n");
        exit(1);
    }

    int a, b;
    if (fscanf(infile, "a = %d\nb = %d\n", &a, &b) < 2) {
        fprintf(stderr, "in.txt does not follow required format\n");
        exit(1);
    }

    FILE *outfile = fopen("out.txt", "w");
    if (!outfile) {
        fprintf(stderr, "cannot open out.txt for writing\n");
        exit(1);
    }

    if (fprintf(outfile, "a + b = %d\n", a + b) < 0) {
        fprintf(stderr, "cannot write to out.txt, weird\n");
        exit(1);
    }

    fclose(infile);
    fclose(outfile);

    return 0;
}
