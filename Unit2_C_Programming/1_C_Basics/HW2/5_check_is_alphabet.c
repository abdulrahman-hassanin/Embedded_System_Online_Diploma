#include <stdio.h>

void main()
{
    char c;

    printf("Enter a number: ");
    fflush(stdin);  fflush(stdout);
    scanf("%c", &c);

    if( (c>='a' && c<='z') || (c>='A' && c<='Z'))
        printf("%c is an alhphabet", c);
    else
        printf("%c is not an alhphabet", c);
}