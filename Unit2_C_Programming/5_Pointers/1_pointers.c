#include <stdio.h>

void main()
{
    int m;
    int* ab;

    m = 29;
    printf("Address of m: %x\n", &m);
    printf("Value of m: %d\n", m);

    ab = &m;
    printf("Now ab is assigned with address of m\n"); 
    printf("Adderss of pointer ab: %x\n", ab); 
    printf("Content of pointer ab: %d\n", *ab); 

    m = 34;
    printf("Value od m is assigned to 34 now.\n");
    printf("Adderss of pointer ab: %x\n", ab); 
    printf("Content of pointer ab: %d\n", *ab); 

    *ab = 7;
    printf("The pointer variable ab is assigned with the value 7 now.\n");
    printf("Address of m: %x\n", &m);
    printf("Value of m: %d\n", m);    
}