#include <stdio.h>

#define MAX_LINE_LEN 1000
#define MIN_LEN_WANTED 80

int getline(char s[], int len);

int main() {
    char line[MAX_LINE_LEN];
    int len;

    while ((len = getline(line, MAX_LINE_LEN)) > 0)
        if (len > MIN_LEN_WANTED)
            printf("String is larger %d chars: \n%s\n", MIN_LEN_WANTED, line);

}

int getline(char s[], int len) {
    int c;
    int i;

    for (i = 0; i < len - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}