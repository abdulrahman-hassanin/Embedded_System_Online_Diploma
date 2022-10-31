#include <stdio.h>

void main()
{
    float x;

    printf("Enter a number: ");
    fflush(stdin);  fflush(stdout);
    scanf("%f", &x);

    if(x>0)
        printf("%.2f is positive.", x);
    else if(x<0)
        printf("%.2f is negative.", x);
    else
        printf("You entered zero.");
}