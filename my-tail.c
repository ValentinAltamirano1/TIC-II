#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define MAXLINE 1000

void filecopy(FILE *, FILE *);
void read_last_lines(FILE *, int);
struct list *list_create(int capacity);
void list_insert_last_word(struct list *, char *);
char *strdup_or_exit(const char *s);
void *malloc_or_exit(size_t size);


struct list {               // lista enlazada simple
    int capacity;           // capacidad de la lista
    int qty;                // cantidad de elementos de la lista
    struct listnode *first, *last;  // punteros al nodo comienzo y nodo final
};

struct listnode {           // nodo de una lista enlazada simple
    char *word;             // palabra asociada a este nodo
    struct listnode *next;  // siguiente de la lista o NULL si es el último
};

int main(int argc, char *argv[])
{
    FILE *fp;
    char *prog = argv[0]; /* program name for errors */
    if (argc == 1){ /* no args; copy standard input */
        filecopy(stdin, stdout);
    }else{
        while (--argc > 0){
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);
            } else {
                read_last_lines(fp, 10);
                fclose(fp);
            }
        }
    }
    if (ferror(stdout)) {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }
    exit(0);
}

void filecopy(FILE *ifp, FILE *ofp)
{
    int c;
    while ((c = getc(ifp)) != EOF)
        putc(c, ofp);
}

void read_last_lines(FILE *fp, int lines) {
    char line[MAXLINE];
    struct list *new_list = list_create(lines);
    
    while (fgets(line, sizeof(line), fp) != NULL) {
        list_insert_last_word(new_list, strdup_or_exit(line));
    }
    
    struct listnode *current = new_list->first;
    int count = 0;
    
    while (current != NULL && count < new_list->qty) {
        printf("%s", current->word);
        current = current->next;
        count++;
    }
    
    while (new_list->first != NULL) {
        struct listnode *temp = new_list->first;
        new_list->first = new_list->first->next;
        free(temp->word);
        free(temp);
    }
    
    free(new_list);
}

struct list *list_create(int capacity) 
{
    struct list *l = (struct list *)malloc_or_exit(sizeof(struct list));
    l->qty = 0;
    l->capacity = capacity;
    l->first = NULL;
    l->last = NULL;
    return l;
}

void list_insert_last_word(struct list *l, char *word) 
{
    struct listnode *newnode = (struct listnode *)malloc_or_exit(sizeof(struct listnode));
    newnode->word = word;
    newnode->next = NULL;

    if (l->first == NULL) { // Lista vacía
        l->first = newnode;
        l->last = newnode;
        l->qty++;
    } else {
        l->last->next = newnode; // Apuntar el último nodo al nuevo nodo
        l->last = newnode;
        l->qty++;

        if (l->qty > l->capacity) {
            // Eliminar el primer nodo de la lista
            struct listnode *temp = l->first;
            l->first = l->first->next;
            free(temp->word);
            free(temp);
            l->qty--;
        }
    }
}

char *strdup_or_exit(const char *s)
{
    char *p;
    p = malloc_or_exit(strlen(s) + 1);
    (void) strcpy(p, s);
    return p;
}

void *malloc_or_exit(size_t size)
{
    void *p = malloc(size);
    if (p == NULL) {        // no hay memoria para asignar
        error(EXIT_FAILURE, errno, "malloc error - exit\n");
    }
    return p;
}