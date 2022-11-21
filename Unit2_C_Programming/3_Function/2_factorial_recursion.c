#include <stdio.h>

int factorial(int n)
{
    if(n==1) return 1;
    return n*factorial(n-1);
}

void main()
{
    int a;
    printf("Enter the number: ");
    fflush(stdin);  fflush(stdout);
    scanf("%d", &a);

    int fact = factorial(a);
    printf("factorial of %d = %d", a, fact);
}
