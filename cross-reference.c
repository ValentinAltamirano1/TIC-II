#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXWORD 100
#define getch() getchar()
#define ungetch(c) ungetc(c, stdin)

int line;

struct linenode {
    int line_num;
    struct linenode *next; 
};

struct node {
        char *word;
        int count;
        struct linenode *lines;
        struct node *left, *right;
};

struct node *addtree(struct node *, char *);
struct node *root;
void treeprint(struct node *, struct linenode *);
void addline(struct node *, int);
int getword(char *, int);

int main()
{
    char word[MAXWORD];
    struct node *root = NULL;
    while((getword(word, MAXWORD)) != EOF){
        if (isalpha(word[0])){
            root = addtree(root, word);
        }
    }
    treeprint(root, root -> lines);
    return 0;
}

struct node *newnode(char *word)
{
        struct node *p;
        p = malloc(sizeof (struct node));
        if (p == NULL)
                return NULL;
        p -> word = malloc(strlen(word) +1);
        strcpy( p -> word, word);
        if (p -> word == NULL) {
                free(p);
                return NULL;
        }
        p -> count = 1;
        p -> left = p -> right = NULL;
        return p;
}

struct node *addtree(struct node *root, char *word)
{
    int comp;
    if (root == NULL) {
        root = newnode(word);
        addline(root, line);
        return root;
    } else {
        if ((comp= strcmp(word, root -> word)) == '\0') {
            root -> count ++;
            addline(root, line);
            return root;
        } else if (comp<0) {            
            root -> right = addtree(root -> right, word);
            return root;
        } else {
            root -> left = addtree(root -> left, word);
            return root;
        }
    }
}

void treeprint(struct node *p, struct linenode *s) //print tree in order
{
    if(p != NULL){
        treeprint(p -> left, s);
        printf("%4d %s %d\n", p -> count, p -> word, s -> line_num);
        treeprint(p -> right, s);
    }
}

int getword(char *word, int lim)
{
    int c;
    char *w = word;
    while(isspace(c = getch())){
        if(c == '\n')
            line++;
    }
    if(c != EOF)
        *w++ = c;
    if(!isalpha(c)){
        *w = '\0';
        return c;
    }
    for (; --lim>0; w++)
        if(!isalnum(*w = getch())){
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

void addline(struct node *root, int line)
{
    struct linenode *newline =(struct linenode*) malloc(sizeof(struct linenode));
    newline -> line_num = line;
    newline -> next = root -> lines;
    root -> lines = newline;
}