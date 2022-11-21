#include <stdio.h>

int uniqueNumber(int arr[], int size)
{
    int res = arr[0];
    for(int i=1; i<size; i++)
        res = res ^ arr[i];
    return res;
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

    int res = uniqueNumber(a, size);
    printf("unique number: %d", res);
}