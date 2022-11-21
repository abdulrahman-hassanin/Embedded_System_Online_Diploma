#include<stdio.h>

int sum_numbers(int n){
    static int sum = 0;
    if(n!=0)
        sum = n + sum_numbers(n-1);
    return sum;
}

int main()
{
    int num;
    printf("Enter Number: ");
    fflush(stdin);  fflush(stdout);
    scanf("%d", &num);
    int res = sum_numbers(num);
    printf("sum of range from 1 to %d = %d", num, res);
}