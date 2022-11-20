#include <stdio.h>

void main()
{
    char s[1000], c;
    printf("Enter a string: ");
    fflush(stdin);      fflush(stdout);
    gets(s);
    printf("Enter a character to find frequency: ");
    fflush(stdin);      fflush(stdout);
    scanf("%c", &c);

    int freq = 0;
    for(int i=0; s[i]!='\0'; i++)
        if(s[i] == c)
            freq++;

    printf("Frequency of e = %d", freq);

}