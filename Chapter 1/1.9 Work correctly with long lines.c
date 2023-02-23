#include <stdio.h>

#define MAX_LINE 100
#define STOP_LEN 0

int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len, max = 0;
    char line[MAX_LINE];
    char longest_line[MAX_LINE];

    while ((len = getline(line, MAX_LINE)) != STOP_LEN) {
        printf("There are %d symbols in this line.\n", len);
        if (len > max) {
            printf("Current line is: %s\n", line);
            max = len;
            copy(longest_line, line);
        }
    }
    if (max > 0)
        printf("Longest line is %s", longest_line);
}

int getline(char s[], int lim)
{
    int c, i, end = 0;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim - 1)
            s[i] = c;
    }

    if (c == '\n') {
        if (i < lim) {
            s[i] = c;
            end = ++i;
        } else {
            ++i;
            end = lim - 1;
        }
    }

    s[end] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}