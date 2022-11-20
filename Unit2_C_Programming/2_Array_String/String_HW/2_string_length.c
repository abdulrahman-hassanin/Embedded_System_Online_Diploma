#include <stdio.h>

void main()
{
    char s[1000], c;
    printf("Enter a string: ");
    fflush(stdin);      fflush(stdout);
    gets(s);

    int length = 0;
    for(int i=0; s[i]!='\0'; i++)
            length++;

    printf("length of string = %d", length);

}