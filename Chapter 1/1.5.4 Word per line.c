#include <stdio.h>

#define IN 	1
#define OUT 	0


int main() {
	int c, state = OUT;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
		       	if (state == IN) {
				state = OUT;
				putchar('\n');
			}
		} else if (state == OUT) {
			state = IN;
		}
		if (state == IN)
			putchar(c);
	}
}
