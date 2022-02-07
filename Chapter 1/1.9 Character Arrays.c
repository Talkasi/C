#include <stdio.h>

#define MAX_LINE 1000
#define STOP_LEN 0

int getline(char line[], int maxline);

void copy(char to[], char from[]);

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
    if (max > 0)
        printf("Longest line is %s", longest_line);
}

int getline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != '.'; ++i) {
        s[i] = c;
    }

    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i = 0;

    while ((to[i] = from[i]) != '\0'){
        ++i;
    }
}