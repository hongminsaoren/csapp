#include <string.h>
#include <stdio.h>

int main() {
    //  8 bytes, can fit a 7-char C string
    char dst[8];

    //  An 8-byte array represnting a 7-char C string
    char *src1 = "entropy";

    //  A 9-byte array representing an 8-char C string
    char *src2 = "entropy+";

    //  Not NUL-terminated
    char not_nul_term[8] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xDE, 0xAD, 0xBE, 0xEF };

    strcpy(dst, src1);              //  length of dst >= length of src1... OK
    strcpy(dst, src2);              //  length of dst < length of src1...  UNDEFINED
    strcpy(src1, src1 + 4);         //  source and dest string overlap...  UNDEFINED
    strcpy(dst, not_nul_term);      //  source is not NUL-terminated...    UNDEFINED
    strcpy((char*)(&main), src1);   //  dest is not a string..             UNDEFINED

    return 0;
}
