#include <stdio.h>

#define LEN 100

int any(char line[], char source[]);
void squeeze(char line[], char source[]);

int main()
{
    char s1[LEN], s2[LEN];

    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);

    printf("The first string is: %s\n", s1);
    printf("The second string is: %s\n", s2);

    printf("Any: %d\n", any(s1, s2));
    squeeze(s1, s2);

    printf("The resulting string is: %s\n", s1);

    printf("Any: %d\n", any(s1, s2));
}

void squeeze(char line[], char source[])
{
    int k = 0, flag;

    for (int i = 0; line[i] != '\0'; ++i) {
        flag = 1;
        for (int j = 0; source[j] != '\0'; ++j)
            if (line[i] == source[j]) {
                flag = 0;
                break;
            }
        if (flag)
            line[k++] = line[i];
    }

    line[k] = '\0';
}

int any(char line[], char source[])
{
    for (int i = 0; line[i] != '\0'; ++i)
        for (int j = 0; source[j] != '\0'; ++j)
            if (line[i] == source[j])
                return i;

    return -1;
}
