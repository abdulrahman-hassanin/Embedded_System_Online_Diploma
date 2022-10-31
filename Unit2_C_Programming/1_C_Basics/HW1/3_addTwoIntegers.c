#include <stdio.h>

void main()
{
    int x, y;
    printf("Enter two intgers: ");
    fflush(stdin);  fflush(stdout);
    scanf("%d%d", &x, &y);
    printf("Sum: %d", x+y);
}