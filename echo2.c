#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXWORD 100

void print_line(int, char *[]);

int
main(int argc, char *argv[])
{
        int i, res, j;
        bool flag = false;
        char *s = "hola";
        char *t[];
        for (i=1; i<argc ; i++) {
            t[i]=argv[i];            
            if((strcmp(s, argv[i])) == 0){
                flag = true;
            }
        }

        if (flag == true)
            print_line(argc, t);

        printf("\n");
        return 0;
}

void print_line(int len, char *t[])
{
    int i;
    for (i=1; i<len ; i++) {
        printf("%s%s", t[i], (i<len-1) ? " " : "");
    }
}