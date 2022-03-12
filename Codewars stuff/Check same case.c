#include <stdio.h>
#include <ctype.h>

int same_case_v1(char a, char b) {
    if (('A' <= a && a <= 'Z') && ('A' <= b && b <= 'Z') || ('a' <= a && a <= 'z') && ('a' <= b && b <= 'z')) {
        return 1;
    } else {
        if (a < 'A' || b < 'A' || a > 'z' || b > 'z' || (b > 'Z' && b < 'a') || (a > 'Z' && a < 'a'))
            return -1;
        else {
            return 0;
        }
    }
}

/* While the better solution is to: */
int same_case_v2(char a, char b) {
    if (!isalpha(a) || !isalpha(b))
        return -1;
    return isupper(a) == isupper(b);
}

int main() {
    printf("V1: %d\n",  same_case_v1('S', 'X'));
    printf("V2: %d",    same_case_v2('S', 'X'));
}
