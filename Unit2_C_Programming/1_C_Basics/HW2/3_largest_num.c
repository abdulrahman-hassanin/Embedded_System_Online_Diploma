#include <stdio.h>

void main()
{
    float x, y, z;

    printf("Enter three numbers: ");
    fflush(stdin);  fflush(stdout);
    scanf("%f%f%f", &x, &y, &z);

    if(x>=y && x>=z)
        printf("Largest Number = %.2f", x);
    else if(y>=x && y>=z)
        printf("Largest Number = %.2f", y);
    else
        printf("Largest Number = %.2f", z);
}