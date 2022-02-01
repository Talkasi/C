#include <stdio.h>

/* Print Fahrenheit-Celsius table */

int main() {
    /* Part 1 */
    printf("Fahrenheit-Celsius table:\n");
    /* Initialisation */
    int fahr, celsius;
    int lower = 0, upper = 300, step = 20;

    fahr = lower;

    while (fahr <= upper) {
        /* Great attention to celsius counting -
         * (fahr - 32) * (5 / 9) gives 0.
         * 5.0 / 9.0 * (fahr - 32) will solve this problem too.
         */
        celsius = (fahr - 32) * 5 / 9;
        printf("%3d %6d\n", fahr, celsius);
        fahr += step;
    }
    /* Part 2 */
    printf("\nThe second variant of this task solution:\n");
    float celsius_2, fahr_2 = 0;

    while (fahr_2 <= upper) {
        celsius_2 = (5.0 / 9.0) * (fahr_2 - 32.0);
        printf("%3.0f %6.1f\n", fahr_2, celsius_2);
        fahr_2 += 20;
    }
};
