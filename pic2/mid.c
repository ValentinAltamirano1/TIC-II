#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

#include "deq.h"
#include "wrappers.h"

void filecopy(FILE *, FILE *);
void printlines(FILE *);

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
                printlines(fp); //llamo a la funcion para imprimir las lineas
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

void printlines(FILE *ifp)
{
    char c1[MAXLINE], c2[MAXLINE];
    int contador = 0;
    struct deq *my_deq1 = deq_create(); //creo la cola
    while ((fgets(c1, sizeof(c1), ifp)) != NULL){ //read line by line
        deq_append(my_deq1, c1); //agrego a la cola
        if(((my_deq1->count) % 2) == 0 && my_deq1->count >= 3){ //si la cola tiene cantidad impar y mayor a 3, puedo asegurar que el primero no es necesario tenerlo
            deq_pop_left(my_deq1); //saco el primero
        }
    }
    if ((my_deq1->count % 2) == 0){ //si son pares, las del medio son 2
        printf("LINEA DEL MEDIO: %s", my_deq1->leftmost->str); //devuelvo el primero de la cola
        printf("LINEA DEL MEDIO: %s", my_deq1->leftmost->next->str); //devuelvo el segundo de la cola
    }else{
        printf("LINEA DEL MEDIO: %s", my_deq1->leftmost->str); //devuelvo el primero de la cola
    }
}