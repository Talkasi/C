#include <stdio.h>

#define MAX_LINE 1000

int max;
char line[MAX_LINE];
char longest_line[MAX_LINE];

int getline(void);

void copy(void);

char *reversed(char line[], int len);

/* TODO:
 *        - try to add reversed here */

int main() {
    int len;
    extern int max;
    extern char longest_line[MAX_LINE];

    max = 0;
    while ((len = getline()) > 0) {
        printf("We have %d symb in this line.\n", len);
        if (len > max) {
            max = len;
            copy();
        }
    }
    if (max > 0) {
        printf("Longest line is %s\n", longest_line);
        printf("Reversed line is %s", reversed(longest_line, max));
    }
}

char *reversed(char line[], int len) {
    int i;
    char s[len];

    for (i = 0; i < len; ++i) {
        s[i] = line[len - i - 1];
    }

    copy();

    return line;
}

int getline(void) {
    int c, i;
    extern char line[];

    for (i = 0; i < MAX_LINE - 1 && ((c = getchar()) != '.') && c != '\n' ; ++i) {
        line[i] = c;
    }


    line[i] = '\0';
    return i;
}

void copy(void) {
    int i = 0;
    extern char line[], longest_line[];

    while ((longest_line[i] = line[i]) != '\0') {
        ++i;
    }
}