#include <stdio.h>

void main()
{
    char operator;
    float x, y, res;

    printf("Enter an operator either + or - or * or /: ");
    fflush(stdin);  fflush(stdout);
    scanf("%c", &operator);

    
    printf("Enter two operands: ");
    fflush(stdin);  fflush(stdout);
    scanf("%f%f", &x, &y);
    
    switch (operator)
    {
        case '+':
            printf("%.2f + %.2f = %.2f", x, y, x+y);
            break;
        case '-':
            printf("%.2f - %.2f = %.2f", x, y, x-y);
            break;
        case '*':
            printf("%.2f * %.2f = %.2f", x, y, x*y);
            break;
        case '/':
            printf("%.2f / %.2f = %.2f", x, y, x/y);
            break;
        default:
            printf("Error operator is not correct");
            break;
    }


}