#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100
#define getch() getchar()
#define ungetch(c) ungetc(c, stdin)

char *encrypt(char *, char *, int);
char *decrypt(char *, char *, int);
int get_displace(char *, int);
int move(char *, int, char);

int main()
{
        char *encrypted_word;
        char *dic = "abcdefghijklm";
        char word[MAXWORD];
        int clave = 10;
        while((getword(word, MAXWORD)) != EOF){
                if(isalpha(word[0])){
                        printf("Word: %s", word);
                        encrypted_word = encrypt(word, dic, clave);
                        printf("Encrypt word: %s", encrypted_word);
                }
        }
        return 0;
}

char *encrypt(char *s, char *diccionary, int clave)
{
        int i, j;
        int displace = get_displace(diccionary, clave);
        char concat_word[MAXWORD];
        for(i = 0; i<strlen(s); i++){
                s[i] = s[move(diccionary, displace, s[i])];
                printf("%c \n", s[i]);
        }
        return s;
}

int move(char *diccionary, int displace, char word)
{
        int i, desp_word;
        int len_dicc = strlen(diccionary);
        for(i = 0; i<len_dicc; i++) {
                if (diccionary[i] == word){
                        desp_word = i + displace;
                        if (desp_word > len_dicc){
                                desp_word = displace - (len_dicc - i);
                        }
                        return desp_word;
                }
        }
        return i; // if word not found in diccionary return same position
}

int get_displace(char *diccionary, int clave)
{
        int desp;
        int dic_length = strlen(diccionary);
        desp = clave % dic_length;
        if (desp == 0)
                desp++;
        return desp;
}

int getword(char *word, int lim)
{
        int c, line;
        char *w = word;
        while(isspace(c = getch())){
                ;
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
