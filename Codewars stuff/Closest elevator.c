#include <stdio.h>
#include <math.h>

const char* elevator_v1(int left, int right, int call) {
    if (abs(call - left) < abs(call - right)) {
        return "left";
    }
    return "right";
}

/* Better solution */
const char* elevator_v2(int left, int right, int call) {
    return (abs(call-left) < abs(call-right)) ? "left" : "right";
}

int main() {
    printf("V1: %s\n",  elevator_v1(0, 0, 1));
    printf("V2: %s",    elevator_v2(0, 0, 1));
}

