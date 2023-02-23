#include <stdio.h>

int main()
{
    long c;
    int n_blanks = 0, n_tabs = 0, n_lines = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n')
            ++n_lines;
        if (c == '\t')
            ++n_tabs;
        if (c == ' ')
            ++n_blanks;
    }

    printf("While version:\nblanks - %d, tabs -  %d, lines - %d\n", n_blanks, n_tabs, n_lines);

    /* As per EOF is end of file, first version of the task solution should be commented for second version proper work. */
    /* This example is good for understanding that EOF is actually end-of-file for the program stdin, so it makes */
    /* all further `getchar()` attempts to be irrelevant and equal -1, which represents EOF numeric value. */
    c = 0;

    n_blanks = 0;
    n_lines = 0;
    n_tabs = 0;

    for (; (c = getchar()) != EOF;) {
        printf("In for loop");
        if (c == '\n')
            ++n_lines;
        if (c == '\t')
            ++n_tabs;
        if (c == ' ')
            ++n_blanks;
    }

    printf("For  version:\nblanks - %d, tabs - %d, lines - %d\n", n_blanks, n_tabs, n_lines);
}
