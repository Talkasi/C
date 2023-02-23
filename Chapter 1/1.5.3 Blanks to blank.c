#include <stdio.h>

/* Why does `putchar()` work only when input stream for `getchar()` is over? */

/* This misunderstanding appears, because terminal is line-buffered. */
/* Functions still only work on single characters but the terminal waits */
/* with submitting the characters to the program until the whole line wasn't entered */

int main()
{
    long c, prev_c = 0;

    while ((c = getchar()) != EOF) {
        if (prev_c == ' ' && c == ' ')
            ;
        else
            putchar(c);
        prev_c = c;
    }
}
