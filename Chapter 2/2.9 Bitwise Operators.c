#include <stdio.h>

void print_bin_representation(int x);
int setbits(int x, int p, int n, int y);
int invert(int x, int p, int n);

int main()
{
    print_bin_representation((10) );
    print_bin_representation(10 & ~0x08);
//    print_bin_representation(setbits(11111, 10, 2, 14));
//    print_bin_representation(invert(100, 4, 2));
    return 0;
}

int setbits(int x, int p, int n, int y)
{
    return (~0U << (p + 1) | ~0U >> (sizeof(int) * 8 - p + n - 1) | (~0U >> (sizeof(int) * 8 - n) & y) << (p - n + 1)) & x;
}

int invert(int x, int p, int n)
{
    print_bin_representation(x);
    return x & ~(~0U << (p - n + 1)) | x >> (p + 1) << (p + 1) | (~(x >> (p - n + 1)) & ~(~0U << n)) << (p - n + 1) ;
}

void print_bin_representation(int x)
{
    for (int i = sizeof(int) * 8 - 1; i >= 0; --i)
        printf("%d", (x >> i & 1) != 0);

    printf("\n");
}
