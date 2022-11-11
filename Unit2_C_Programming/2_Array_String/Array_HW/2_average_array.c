#include <stdio.h>

void main()
{
    const int SIZE = 100;
    int n;
    float data[SIZE];
    printf("Enter number of data: ");
    fflush(stdin);      fflush(stdout);
    scanf("%d", &n);
    while (n>100 || n<1)
    {
        printf("ERROR! Number should be in range of 1 and 100");
        printf("Enter number of data: ");
        fflush(stdin);      fflush(stdout);
        scanf("%d", &n);
    }

    float sum = 0;
    for(int i=0; i<n; i++){
        printf("%d Enter number: ", i+1);
        fflush(stdin);      fflush(stdout);
        scanf("%f", &data[i]);
        sum += data[i];
    }

    float avr = sum / n;
    printf("Average = %.2f", avr);
    
}