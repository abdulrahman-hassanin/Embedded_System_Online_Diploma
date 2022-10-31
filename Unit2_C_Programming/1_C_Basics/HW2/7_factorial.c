#include <stdio.h>

void main()
{
    int N;

    printf("Enter an integer: ");
    fflush(stdin);  fflush(stdout);
    scanf("%d", &N);
    
    if(N<0)
        printf("Error!!! factorial of negative number doesn't exist.");
    else
    {
        int sum = N;

        while(--N)
            sum *= N;

        printf("factorial = %d", sum);
    }
}