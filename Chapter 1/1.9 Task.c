#include <stdio.h>

#define MAX_LINE 1000
#define STOP_LEN 0

int getline(char s[], int lim);

void copy(char to[], char from[]);

char *reversed(char line[], int len);

int main() {
    int len, max = 0;
    char line[MAX_LINE];
    char longest_line[MAX_LINE];

    while ((len = getline(line, MAX_LINE)) != STOP_LEN) {
        printf("We have %d symb in this line.\n", len);
        if (len > max) {
            max = len;
            copy(longest_line, line);
        }
    }
    if (max > 0) {
        printf("Longest line is %s\n", longest_line);
        printf("Reversed line is %s", reversed(longest_line, max));
        /* Another way to solve bug with rubish was to use %.'len's, but it is harder to implement */
    }
}

char *reversed(char line[], int len) {
    int i;
    char s[len];

    for (i = 0; i < len; ++i) {
        s[i] = line[len - i - 1];
    }

    copy(line, s);
    line[len] = '\0';
    return line;
}

int getline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != '.' && c != '\n'; ++i) {
        s[i] = c;
    }

    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i = 0;

    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}
