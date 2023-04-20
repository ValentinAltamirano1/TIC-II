#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int count_character(char *, char *);

int main()
{
        char *s = "hola";
        char *t = "l";
        printf("%d \n", count_character(s, t));
        return 0;
}

int count_character(char *s, char *t)
{
        int i, j, count = 0;
        for(i = 0; i<strlen(s); i++){
                if(s[i] == t[0]){
                        count++;
                }
        }
        return count;
}