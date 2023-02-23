#include <stdio.h>

#define MAX_WORD_LEN 100

int main()
{
    int current_length = 0, c;
    int words_length[MAX_WORD_LEN];

    for (int i = 0; i < MAX_WORD_LEN; ++i)
        words_length[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (current_length >= MAX_WORD_LEN)
                ++words_length[0];
            else if (current_length > 0)
                ++words_length[current_length];

            current_length = 0;
        } else {
            ++current_length;
        }
    }

    if (words_length[0] > 0) {
        printf("Big words (> 99 chars): ");
        for (int i = 0; i < words_length[0]; ++i)
            printf("-");
        printf("\n");
    }

    for (int i = 1; i < MAX_WORD_LEN; ++i) {
        if (words_length[i] > 0) {
            printf("%22d: ", i);
            for (int j = 0; j < words_length[i]; ++j)
                printf("-");
            printf("\n");
        }
    }
}
