#include <stdio.h>

void main()
{
    int c;

    printf("Enter an alphabet: ");
    fflush(stdin);  fflush(stdout);
    scanf("%c", &c);

    ( c=='a' || c=='A' || c=='e' || c=='E' || c=='i' || c=='I'|| c=='o' || c=='O' || 
    c=='u' || c=='U') ? printf("%c is a vowel.", c) : printf("%c is a constant.", c); 
}