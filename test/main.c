#include <stdio.h>
int howManyBits(int x)
{
	int sign = x >> 31;
	///if x is negative, then x = ~x + 1
	x = (sign & ((~x)+1)) | (~sign & x);
	int b16, b8, b4, b2, b1, b0;
	b16 = (!!(x >> 16)) << 4;
	x = x >> b16;
	b8 = (!!(x >> 8)) << 3;
	x = x >> b8;
	b4 = (!!(x >> 4)) << 2;
	x = x >> b4;
	b2 = (!!(x >> 2)) << 1;
	x = x >> b2;
	b1 = (!!(x >> 1));
	x = x >> b1;
	b0 = x;
	printf("%d %d %d %d %d %d\n", b16, b8, b4, b2, b1, b0);
	return b16 + b8 + b4 + b2 + b1 + b0 + 1;
}
int main() {
	printf("%d\n", howManyBits(0x80000000));
	return 0;
}
