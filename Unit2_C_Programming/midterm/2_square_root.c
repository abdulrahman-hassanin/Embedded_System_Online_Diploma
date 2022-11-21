#include <stdio.h>

double sqr_root(int num){
    if(num == 0 || num == 1)
        return num;
    
    double temp, sqrt;
    sqrt = num / 2;
    temp = 0;
    while(sqrt != temp)
    {
        temp = sqrt;
        sqrt = (num/temp + temp) / 2;
    }

    return sqrt;
}

int main()
{
    int num;
    printf("Enter number: ");
    fflush(stdin);  fflush(stdout);
    scanf("%d", &num);
    double sqr = sqr_root(num);
    printf("square root = %lf", sqr);
}