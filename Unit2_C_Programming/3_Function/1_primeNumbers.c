#include <stdio.h>

void primeNumbers(int a, int b);

void main()
{
    int a, b;
    printf("Enter the intervals: ");
    fflush(stdin);  fflush(stdout);
    scanf("%d%d", &a, &b);

    printf("Prime Numbers: \n");
    primeNumbers(a, b);
}


void primeNumbers(int a, int b){
    int flag;
    for(int n=a; n<=b; n++) {
        flag = 0;
        for(int i=2; i<=n/2; i++) {
            if(n%i==0) {
                flag = 1;
                break;
            }
        }

        if(!flag)
            printf("%d ", n);
    }
}