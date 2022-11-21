#include <stdio.h>

void primeNumbers(int a, int b)
{
    int i, flag, n;
    for(int n=a; n<=b; n++) {
        int flag = 0;
        for(i=2; i<=n/2; i++) {
            if(n%i == 0){
                flag = 1;
                break;
            }
        }
        if(!flag)
            printf("%d ", n);
    }
}
int main()
{
    int a, b;
    printf("Enter two numbers: ");
    fflush(stdin);  fflush(stdout);
    scanf("%d%d", &a, &b);
    primeNumbers(a, b);
}