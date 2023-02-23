#include <stdio.h>

/* Every memory address is a lie, program memory layout is */

/* 0xbfffffff 			  */
/* ┌───────────────────────┐	  */
/* │ Environment Variables │ 	  */
/* ├───────────────────────┤ 	  */
/* │	      ...          │ 	  */
/* ├───────────────────────┤      */
/* │         Arg #2        │	  */
/* ├───────────────────────┤	  */
/* │         Arg #1        │ 	  */
/* ├───────────────────────┤ 	  */
/* │      Program name     │  	  */
/* ├───────────────────────┤      */
/* │     # of arguments    │ %esp */
/* ├───────────────────────┤ 	  */
/* │     Unmapped Memory   │ 	  */
/* ├───────────────────────┤ 	  */
/* │ Program Code and Data │ 	  */
/* └───────────────────────┘	  */
/* 0x08048000			  */


int main()
{
    int n1, n2, n3;

    n1 = n2 = n3 = 0;

    printf("n1: value %d - address decimal %d - address hex %hx\n", n1, &n1, &n1);
    printf("n2: value %d - address decimal %d - address hex %hx\n", n2, &n2, &n2);
    printf("n3: value %d - address decimal %d - address hex %hx\n", n3, &n3, &n3);
}
