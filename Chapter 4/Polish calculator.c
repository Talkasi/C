#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'
#define SIGN -1

int getop(char[]);
void push(double);
double pop(void);
void swap_two_on_stack_top(void);
void duplicate_stack_top(void);
void print_stack_top(void);
void stack_clear(void);

/* Reverse Polish calculator */
int main()
{
    int type;
    double op2, op1;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("Error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                op1 = pop();
                if (op2 != 0.0 && op2 == (int) op2 && op1 == (int) op1)
                    push((int) op1 % (int) op2);
                else
                    printf("Error: zero divisor or operators are not integers\n");
                break;
            case SIGN:
                push(-pop());
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("Error: unknown command %s\n", s);
                break;
        }
    }

    return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("Error: stack is full, can't push %g\n", f);
}

/* pop: pop and return top value from the stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void stack_clear(void)
{
    for (sp = 0; sp < MAXVAL; ++sp)
        val[sp] = 0;
    sp = 0;
}

void print_stack_top(void)
{
    if (sp > 0)
        printf("On top of the stack: %.8g\n", val[sp]);
    else
        printf("Error: nothing in stack");
}

void duplicate_stack_top(void)
{
    if (sp > 0) {
        double duplicate = val[sp];
        val[sp++] = duplicate;
    } else {
        printf("Error: nothing to duplicate\n");
    }
}

void swap_two_on_stack_top(void)
{
    if (sp > 1) {
        double tmp = val[sp - 1];
        val[sp - 1] = val[sp];
        val[sp] = tmp;
    } else {
        printf("Error: nothing to swap\n");
    }
}


int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c;

    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;

    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
