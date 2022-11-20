#include <stdio.h>

void main()
{
    char s[100];
    printf("Enter the string: ");
    gets(s);

    int lastIndex = 0;
    for(int i=0; s[i]!='\0'; i++)
        lastIndex++;
    
    printf("The reversed string: ");
    for(int i=lastIndex-1; i>=0; i--)
        printf("%c", s[i]);
}