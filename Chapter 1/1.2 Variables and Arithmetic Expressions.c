#include <stdio.h>

/* Definition */
#define LOWER_T 0
#define UPPER_T 300
#define STEP 20

/* Print Fahrenheit-Celsius table */

int main()
{
    /* Part 1 */
    printf("Fahrenheit-Celsius table:\n");
    /* Initialisation */
    int fahr, celsius;
    int lower = LOWER_T, upper = UPPER_T;

    fahr = lower;

    while (fahr <= upper) {
        /* Great attention to celsius counting -
         * (fahr - 32) * (5 / 9) gives 0.
         * 5.0 / 9.0 * (fahr - 32) will solve this problem too.
         */
        celsius = (fahr - 32) * 5 / 9;
        printf("%3d %6d\n", fahr, celsius);
        fahr += STEP;
    }
    /* Part 2 */
    printf("\nThe second variant of this task solution:\n");
    float celsius_2, fahr_2 = LOWER_T;

    while (fahr_2 <= upper) {
        celsius_2 = (5.0 / 9.0) * (fahr_2 - 32.0);
        printf("%3.0f %6.1f\n", fahr_2, celsius_2);
        fahr_2 += STEP;
    }
};
