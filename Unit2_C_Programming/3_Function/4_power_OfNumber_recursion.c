#include <stdio.h>

int power(int num, int pow){
    if(pow == 1)    return num;
    return num * power(num, pow-1);
}

void main()
{
    int num, pow;
    printf("Enter the number: ");
    fflush(stdin);  fflush(stdout);
    scanf("%d", &num);


    printf("Enter the power: ");
    fflush(stdin);  fflush(stdout);
    scanf("%d", &pow);

    int res = power(num, pow);
    printf("%d ^ %d = %d", num, pow, res);
}
