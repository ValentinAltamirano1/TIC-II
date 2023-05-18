#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

char *eliminar_duplicados(char *);
int eliminar_duplicados_i(char s[]);
char *remove_char(char *, char);

int
main(int argc, char *argv[])
{
        int i;
        for (i=1; i<argc ; i++) {      
            char *word = argv[i];
            char *original_word = malloc(sizeof(strlen(word)));
            char *original_word2 = malloc(sizeof(strlen(word)));
            original_word = strcpy(original_word, word);
            original_word2 = strcpy(original_word2, word);

            printf("%s \n", "PRUEBA CON PUNTEROS");
            eliminar_duplicados(word);
            printf("%s , %s \n", original_word, word);

            printf("%s \n", "PRUEBA CON INDICES");
            int i = eliminar_duplicados_i(original_word);
            printf("%s , %s , %d \n", original_word2, original_word ,i);
        }
        return 0;
}

char *eliminar_duplicados(char *s)
{
        char *p = s;
        char *character = (p+1);
        for(p; *p != '\0'; p++){ 
                char* character = p + 1;
                for(character; *character != '\0'; character++){
                        if(*p == *character){
                                char *q = character;
                                while (*q != '\0') {
                                *q = *(q + 1);
                                q++;
                        }
                        character--;
                        }
                }
        }
        *(p + 1) = '\0';
        return s;
}

int eliminar_duplicados_i(char s[])
{
        int i,character;
        for(i=0; i<strlen(s)-1; i++){ 
                for(character=i+1; character<strlen(s); character++){
                        if(s[i] == s[character]){
                                s[character] = s[strlen(s) - 1];
                                s[strlen(s) - 1] = '\0';
                                s[i--];
                                character--;
                        }
                }
        }
        return strlen(s);
}