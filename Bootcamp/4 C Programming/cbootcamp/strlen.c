#include <string.h>
#include <stdio.h>

void bad_reverse(char *src, char* dst) {
    printf("bad_reverse: reversing %s...\n", src);

    //  Get character array length
    size_t len = strlen(src) + 1;

    size_t last_index = len - 1;

    //  Reverse each byte in the character array
    size_t i;
    for (i = 0; i < len; ++i) {
        dst[i] = src[last_index - i];
        printf(
            "bad_reverse: set dst[%zu] to src[%zu] = \'%c\'\n",
            i, last_index - i, src[last_index - i]
        );
    }
}

void good_reverse(char *src, char* dst) {
    printf("good_reverse: reversing %s...\n", src);

    //  Get string length
    size_t len = strlen(src);

    size_t last_index = len - 1;

    //  Reverse each byte before the NUL terminator
    size_t i;
    for (i = 0; i < len; ++i) {
        dst[i] = src[last_index - i];
        printf(
            "good_reverse: set dst[%zu] to src[%zu] = \'%c\'\n",
            i, last_index - i, src[last_index - i]
        );
    }

    //  Set the NUL terminator
    dst[len] = 0;
    printf("good_reverse, set dst[%zu] to NUL\n", len);
}

int main() {
    char *hello = "hello";
    printf("\nhello has length: %zu\n\n", strlen(hello));

    char olleh1[6], olleh2[6];

    bad_reverse(hello, olleh1);
    printf("\nolleh1 is: %s\n\n", olleh1);

    good_reverse(hello, olleh2);
    printf("\nolleh2 is: %s\n\n", olleh2);

    return 0;
}
