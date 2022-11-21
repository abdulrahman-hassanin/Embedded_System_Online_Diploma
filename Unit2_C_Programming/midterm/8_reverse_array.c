#include<stdio.h>

void reverse_array(int a[], int size)
{
    int b[10];
    for(int i=0; i<size; i++)
        b[i] = a[size-1-i];

    for(int i=0; i<size; i++)
        a[i] = b[i];
}

void main()
{
    int size;
    int a[50];
    printf("Enter length of the array: ");
    fflush(stdin);  fflush(stdout);
    scanf("%d", &size);
    
    printf("Enter the array: ");
    fflush(stdin);  fflush(stdout);
    for(int i=0; i<size; i++)
        scanf("%d", &a[i]);

    reverse_array(a, size);
    printf("The reversed array:\n");
    for(int i=0; i<size; i++)
        printf("%d ",a[i]);
}