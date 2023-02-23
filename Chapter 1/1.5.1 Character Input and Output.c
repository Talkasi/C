#include <stdio.h>

/* Copy input to output */
int main()
{
    int c;

    printf("%d\n", EOF);

    while ((c = getchar()) != EOF) {
        putchar(c);
    }
}
