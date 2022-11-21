#include <stdio.h>

typedef struct SComplexNumber
{
    float real;
    float img;
} complex;

complex add(complex N1, complex N2);

void main()
{
    complex N1, N2, Sum;
    printf("Enter 1st complex number: \n");
    printf("Enter real: ");
    scanf("%f", &N1.real);
    printf("Enter imaginary: ");
    scanf("%f", &N1.img);
    printf("Enter 2st complex number: \n");
    printf("Enter real: ");
    scanf("%f", &N2.real);
    printf("Enter imaginary: ");
    scanf("%f", &N2.img);

    Sum = add(N1, N2);
    printf("Sum = %.1f + %.1fi", Sum.real, Sum.img);
}


complex add(complex N1, complex N2)
{
    complex Sum;
    Sum.real = N1.real + N2.real;
    Sum.img = N1.img + N2.img;

    return Sum;
}