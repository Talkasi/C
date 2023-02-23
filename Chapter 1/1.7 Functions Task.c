#include <stdio.h>

/* Definition */
#define LOWER_T (float) 0
#define UPPER_T (float) 300
#define STEP (float) 20

/* Print Fahrenheit-Celsius table */
int temperature(float fahr, float upper);

int main()
{
    printf("Fahrenheit-Celsius table:\n");

    /* Initialisation */
    float fahr = LOWER_T, upper = UPPER_T;

    temperature(fahr, upper);
};

int temperature(float fahr, float upper)
{
    float celsius;

    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr += STEP;
    }

    return 0;
}
