#include <stdio.h>

#define MAX_LINE 1000
#define STOP_LEN 0

int getline(char s[], int lim);

void copy(char to[], char from[]);
char * reversed(char line[], int len);

/* TODO: fix rubbish bug */

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
    }
}

char * reversed(char line[], int len) {
    int i;
    char s[len];

    for (i = 0; i < len; ++i) {
        s[i] = line[len - i - 1];
    }

    copy(line, s);
    if (line[len - 1] == '\n' || line[len - 1] == '\0' || line[len - 1] == '\7' ) {
        line[len - 1] = '\0';
    }
    return line;
}

int getline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != '.'; ++i) {
        if (s[i] != '\n' || s[i] != '\0' || s[i] != '\7'){
            s[i] = c;
        }
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