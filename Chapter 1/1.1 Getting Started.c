#include <stdio.h>

int main() {
    /* Part 1 */
    printf("Hello, world.\n\n");

    /* Part 2, has identical output */
    printf("Hello,\t\b");
    printf("world");
    printf(".\n\n");

    /* Interesting addition:
     * The way \number can be used
     */

    printf("\\1: \1\n");
    printf("\\2: \2\n");
    printf("\\3: \3\n");
    printf("\\4: \4\n");
    printf("\\5: \5\n");
    printf("\\6: \6\n");
    printf("\\0, \\7: \0, \7\n");
}