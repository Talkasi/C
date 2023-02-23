#include <stdio.h>

#define N_ASCII 128


int main()
{
    int c, a[N_ASCII];

    for (int i = 0; i < N_ASCII; ++i)
        a[i] = 0;

    while ((c = getchar()) != EOF)
        ++a[c];

    for (int i = 0; i < N_ASCII; ++i) {
        if (a[i] != 0) {
            putchar('\n');
            if (i <= 32 || i == 127)
                printf("%3d: ", i);
            else {
                printf("  ");
                putchar(i);
                printf(": ");
            }

            while (a[i] != 0) {
                putchar('-');
                --a[i];
            }

            putchar('\n');
        }
    }
}
