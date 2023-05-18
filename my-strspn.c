#include <stdio.h>

int my_strspn(char *, char *);

int main(int argc, char *argv[])
{
    /*int i;
    for (i=1; i<argc ; i++) {
        if(argc>=2){
            return 0;
        }  
        char *word = argv[i];
        char *second_word = argv[i+1];
    }
    return 0;*/
    char *s = "hola123";
    char *j = "123hola";
    char *k = "h12cnijsdnc";
    char *t = "abcdefghijklmnopqrstuvwxyz";
    printf("%d \n", my_strspn(s, t));
    printf("%d \n", my_strspn(j, t));
    printf("%d \n", my_strspn(k, t));
    return 0;
}

int my_strspn(char *s, char *accept)
{
    int found = 0;
    int count = 0;
    for(s; *s != '\0'; s++){
        count++;
        char *p = accept;	
        for(p; *p != '\0'; p++){
            if(*s == *p){
                found++;
            }
        }

        if(found != count){
            return found;
        }
    }
    return found;
}