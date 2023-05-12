#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 1000


void compare(FILE *, FILE *);

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    char *prog = argv[0];
    if (argc != 3){
        printf("error, not 2 files");
        exit(1);
    }
    if ((fp1 = fopen(*++argv, "r")) == NULL || (fp2 = fopen(*++argv, "r")) == NULL) {
        fprintf(stderr, "%s: can't open %s\n", prog, *argv);
        exit(1);
    } else {
        compare(fp1, fp2);
        fclose(fp1);
        fclose(fp2);
    }
    
    if (ferror(stdout)) {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }
    exit(0);
}

void compare(FILE *ifp, FILE *ofp)
{
    char c1[MAXLINE], c2[MAXLINE];
    int contador = 0;
    while ((fgets(c1, sizeof(c1), ifp)) != NULL && (fgets(c2, sizeof(c2), ofp)) != NULL){
        contador ++;
        if (strcmp(c1,c2) != 0){
            printf("Linea %d : %s \n", contador, c1);
            printf("Linea %d : %s \n", contador, c2);
        }
    }
}