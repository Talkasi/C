#include <stdio.h>

/* Definition power parameters */
#define CURRENT_POWER 10
#define POWER_START 0
#define ERROR -1

/* Declaration */
int power(int base, int n);

int main() {
    int i;

    for (i = POWER_START; i < CURRENT_POWER; ++i) {
        printf("2 ** %2d = %1d;\n-3 ** %2d = %1d;\n\n", i, power(2, i), i, power(-3, i) );
    }
}

/* Raise the base to n-th power if n >= 0 */
int power(int base, int n) {
    int i, p = 1;

    if (n < 0) return ERROR;
    else {
        for (i = 1; i <= n; ++i) {
            p = p * base;
        }
        return p;
    }
}

