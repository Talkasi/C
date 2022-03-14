#include <stdio.h>

long pillars(int num_of_pillars, int distance, int width) {
    return num_of_pillars == 1 ? 0 : (num_of_pillars - 1) * distance * 100 + width * (num_of_pillars - 2);
}

int main() {
    printf("V1: %ld\n", pillars(1, 10, 10));
}
