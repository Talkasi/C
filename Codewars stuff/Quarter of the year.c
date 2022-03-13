#include <stdio.h>

int quarter_of_v1(int month) {
    if (month%3 == 0)
        return month/3;
    return month/3 + 1;
}

/* Better solution */
int quarter_of_v2(int month) {
    return (month + 2)/3;
}

int main() {
    printf("V1: %d\n",  quarter_of_v1(12));
    printf("V2: %d",    quarter_of_v2(12));
}
