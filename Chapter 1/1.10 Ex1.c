#include <stdio.h>

#define MAX_LINE_LEN 100

int get_line(char s[], int len);
int insert_spaces(char s[], int len, int max_len, int position, int n);

int main()
{
    char line[MAX_LINE_LEN];
    int len, i, n;

    printf("Enter number `n` of blanks to replace tab (0 < n < 9): ");
    while (scanf("%d", &n) != 1 || n < 1 || n > 8) {
        printf("Input error. Try again: ");
    }

    getchar();
    printf("Enter line: ");
    while ((len = get_line(line, MAX_LINE_LEN)) > 0) {
        for (i = 0; line[i] != '\0'; ++i) {
            if (line[i] == '\t') {
                if (insert_spaces(line, len, MAX_LINE_LEN, i, n))
                    printf("\nMAX LENGTH REACHED, THERE WAS NO REPLACEMENT!\n");
                else
                    len += n;
            }
        }

        printf("Line: %s", line);
        printf("Enter new line: ");
    }
}

int get_line(char s[], int len)
{
    int i, c = 0;

    for (i = 0; i < len - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}

int insert_spaces(char s[], int len, int max_len, int position, int n)
{
    int i;

    if (position + n - 1 >= max_len)
        return 1;

    for (i = len + n - 1; i >= position + n; --i)
        s[i] = s[i - n + 1];

    for (i = position; i < position + n; ++i)
        s[i] = ' ';

    return 0;
}