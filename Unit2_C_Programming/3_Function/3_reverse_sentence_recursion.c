#include <stdio.h>

void reverse(char s[], int i)
{
    if(s[i] != '\0') {
        reverse(s, i+1);
        printf("%c", s[i]);
    }
}

void main()
{
    char sen[50];
    printf("Enter the sentence: ");
    fflush(stdin);  fflush(stdout);
    gets(sen);
    reverse(sen, 0);
}
