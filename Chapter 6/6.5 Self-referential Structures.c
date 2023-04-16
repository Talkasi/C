#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode {           /* The tree node: */
    char *word;          /* pointer to the text */
    int count;           /* number of occurrences */
    struct tnode *left;  /* left child */
    struct tnode *right; /* right child */
};

#define MAX_WORD 100
struct tnode *add_tree(struct tnode *, char *);
void tree_print(struct tnode *);
int get_word(char *, int);

/* word frequency count */
int main()
{
    struct tnode *root;
    char word[MAX_WORD];

    root = NULL;
    while (get_word(word, MAX_WORD) != EOF)
        if (isalpha(word[0]))
            root = add_tree(root, word);

    tree_print(root);
    return 0;
}

struct tnode *talloc(void);
char *my_strdup(char *);

/* add_tree: add a node with w at or below p */
struct tnode *add_tree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL) {  /* a new word has arrived */
        p = talloc(); /* make a new node */
        p->word = my_strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;
    else if (cond < 0)
        p->left = add_tree(p->left, w);
    else
        p->right = add_tree(p->right, w);

    return p;
}

/* tree_print */
void tree_print(struct tnode *p)
{
    if (p != NULL) {
        tree_print(p->left);
        printf("%4d %s\n", p->count, p->word);
        tree_print(p->right);
    }
}

struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *my_strdup(char *s) /* make a duplicate of s */
{
    char *p;

    p = (char *) malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);

    return p;
}

int get_word(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;

    if (c != EOF)
        *w++ = c;

    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }

    for (; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }

    *w = '\0';
    return word[0];
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