#include <string.h>
#include <stdio.h>

int main() {
    //  Both are 16 bytes, each can fit a 15-char C string
    char dst1[16], dst2[16];

    //  Initialize all bytes to 0 (same value as the NUL terminator)
    memset(dst1, 0, 16);
    memset(dst2, 0, 16);

    //  A 9-byte array representing an 8-char C string
    char *base = "this is ";
    strcpy(dst1, base);
    strcpy(dst2, base);

    /*
     *  dst1, dst2:
     *  --------------------------------------------------------------
     *  t   h   i   s   _   i   s   _   \0  \0  \0  \0  \0  \0  \0  \0
     *  --------------------------------------------------------------
     *  0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15
     *  --------------------------------------------------------------
     */

    //  An 8-byte array representing a 7-char C string
    char *src1 = "entropy";

    //  An 9-byte array representing a 8-char C string
    char *src2 = "entropy+";

    strcat(dst1, src1);      //  OK

    /*
     *  dst1:
     *  --------------------------------------------------------------
     *  t   h   i   s   _   i   s   _   e   n   t   r   o   p   y  \0
     *  --------------------------------------------------------------
     *  0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15
     *  --------------------------------------------------------------
     */

    strcat(dst2, src2);      //  UNDEFINED

    /*
     *  dst2:
     *  --------------------------------------------------------------
     *  t   h   i   s   _   i   s   _   e   n   t   r   o   p   y   +
     *  --------------------------------------------------------------
     *  0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15
     *  --------------------------------------------------------------
     */

    return 0;
}
