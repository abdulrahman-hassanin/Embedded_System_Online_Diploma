#include <stdio.h>

void main()
{
    int x;
    printf("Enter an intger: ");
    fflush(stdin);  fflush(stdout);
    scanf("%d", &x);
    printf("You Entered: %d", x);
}