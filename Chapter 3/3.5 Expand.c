#include <stdio.h>

void expand(char s1[], char s2[]);

int main()
{
    char s1[100];
    expand("4A-Z2424", s1);

    printf("%s", s1);
    return 0;
}

void expand(char s1[], char s2[])
{
    int j = 0;
    char from, to;

    for (int i = 0; s1[i] != '\0'; ++i) {
        if (s1[i] == '-') {
            if (i != 0 && s1[i + 1] != '\0') {
                from = s1[i - 1] + 1;
                to = s1[i + 1];

                if (from > to) {
                    s2[j++] = s1[i];
                    continue;
                }

                while (from < to)   {
                    s2[j++] = from;
                    from += 1;
                }
            }
        } else {
            s2[j++] = s1[i];
        }
    }
}