#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *types[] = {"int", "long", "short", "double", "float", "char"};

struct var_list {
    char *word;
    struct var_list *left;
    struct var_list *right;
};

#define N_TYPES sizeof types / sizeof types[0]
#define MAX_LINE 100

int get_first_word(char *line, int lim);
struct var_list *add_words(struct var_list *p, char *line);
struct var_list *talloc();
char *my_strdup(char *s);
int is_type(char *word);
void tree_print(struct var_list *p);

void skip_line();
int getch(void);
void ungetch(int c);

int main(int argc, char *argv[])
{
    char line[MAX_LINE];
    struct var_list *root = NULL;

    while (get_first_word(line, MAX_LINE) != EOF) {
        if (is_type(line)) {
            root = add_words(root, line);
        } else
            skip_line();
    }

    tree_print(root);

    return 0;
}

void skip_line()
{
    int c;

    while ((c = getch()) != '\n' && c != EOF)
        ;
}

int get_first_word(char *line, int lim)
{
    int c;
    char *l = line;

    while (isspace(c = getch()))
        ;

    if (c != EOF)
        *l++ = c;

    if (!isalpha(c)) {
        *l = '\0';
        return c;
    }

    while (isalnum(c = getch()) && lim > 0) {
        if (c == '*')
            continue;
        *l++ = c;
        --lim;
    }

    if (!isalnum(c))
        ungetch(c);

    *l = '\0';
    return line[0];
}

int is_type(char *word)
{
    for (int i = 0; i < N_TYPES; ++i)
        if (strcmp(word, types[i]) == 0)
            return 1;

    return 0;
}

void tree_print(struct var_list *p) {
    if (p != NULL) {
        tree_print(p->left);
        printf("%s\n", p->word);
        tree_print(p->right);
    }
}

struct var_list *add_tree(struct var_list *p, char *w)
{
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = my_strdup(w);
        p->left = p->right = NULL;
    } else if ((cond = strcmp(p->word, w)) > 0)
        p->left = add_tree(p->left, w);
    else if (cond < 0)
        p->right = add_tree(p->right, w);

    return p;
}

struct var_list *add_words(struct var_list *p, char *line)
{
    char *l = line;
    int c;

    while ((c = getch()) != '\n' && c != EOF) {
        if (c == '*')
            continue;

        if (isspace(c) || c == ';' || c == ',') {
            *l = '\0';
            if (strlen(line) > 0 && !is_type(line)) {
                p = add_tree(p, line);
            }
            l = line;
        } else if (isalpha(c))
            *l++ = c;
        else
            l = line;

        if (c == ';' || c == ')') {
            skip_line();
            ungetch('\n');
        }
    }

    return p;
}

struct var_list *talloc()
{
    return (struct var_list *) malloc(sizeof(struct var_list));
}

char *my_strdup(char *s) /* make a duplicate of s */
{
    char *p;

    p = (char *) malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);

    return p;
}

#define BUFSIZE 1000

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