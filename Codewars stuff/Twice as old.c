#include <stdio.h>
#include <math.h>

int twice_as_old_v1(int father_age, int son_age) {
    int n_years = 0;

    if (father_age < son_age * 2) {
        while (father_age != son_age * 2) {
            ++n_years;
            --father_age;
            --son_age;
        }
    } else if (father_age != son_age * 2) {
        while (father_age != son_age * 2) {
            ++n_years;
            ++father_age;
            ++son_age;
        }
    }

    return n_years;
}

/* While the solution consist from 1 line */
int twice_as_old_v2(int father_age, int son_age) {
    return abs(father_age - son_age * 2);
}

int main() {
    int test_value_1 = 29, test_value_2 = 0;
    printf("V1: %d\n", twice_as_old_v1(test_value_1, test_value_2));
    printf("V2: %d",   twice_as_old_v2(test_value_1, test_value_2));
}
