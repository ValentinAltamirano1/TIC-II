#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

void filecopy(FILE *, FILE *);
void read_first_lines(FILE *, int);

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
                read_first_lines(fp, 10);
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

void read_first_lines(FILE * fp, int lines)
{
    char c1[MAXLINE];
    int contador = 0;
    while ((fgets(c1, sizeof(c1), fp)) != NULL && contador < lines){ //read line by line and control if lines are less than 10
        contador++;
        printf("%s", c1); //print lines
    }
}