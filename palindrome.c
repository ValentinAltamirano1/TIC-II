#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int palindrome(char *);

int main()
{
        char *s = "ana";
        char *t = "reconocer";
        printf("%d \n", palindrome(s));
        printf("%d \n", palindrome(t));
        return 0;
}

int palindrome(char *s)
{
        int i;
        char *word = malloc(sizeof (strlen(s)));
        int length = strlen(s);
        for(i = 0; i<length ; i++){
            word[i] = s[length - i - 1];
        }

        if (strcmp(s, word) == 0){
            return 1;
        }

        return 0;
}