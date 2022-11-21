#include <stdio.h>

int sum_digits(int num)
{
    int sum = 0;
    int d;
    while(num > 0)
    {
        d = num % 10;
        sum += d;
        num /= 10;
    }
    return sum;
}

int main()
{
    int num;
    printf("Enter number: ");
    fflush(stdin);  fflush(stdout);
    scanf("%d", &num);
    int digits = sum_digits(num);
    printf("sum of digits = %d", digits);
}