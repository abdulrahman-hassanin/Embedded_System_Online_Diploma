#include <stdio.h>

void main()
{
    int N;

    printf("Enter an integer: ");
    fflush(stdin);  fflush(stdout);
    scanf("%d", &N);
    int sum = N;

    while(--N)
        sum += N;

    printf("Sum = %d", sum);
}