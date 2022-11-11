#include <stdio.h>

void main()
{
    const int SIZE = 100;
    int n;
    int data[SIZE];
    printf("Enter no of elements: ");
    fflush(stdin);      fflush(stdout);
    scanf("%d", &n);

    for(int i=0; i<n; i++)
        scanf("%d", &data[i]);
    
    int element, loc;
    printf("Enter element to be inserted: ");
    fflush(stdin);      fflush(stdout);
    scanf("%d", &element);
    printf("Enter the location: ");
    fflush(stdin);      fflush(stdout);
    scanf("%d", &loc);

    // shift array in the location
    for(int i=SIZE; i>=loc; i--)    
        data[i] = data[i-1];

    // insert the elemts
    data[loc-1] = element;

    // display the arrayy
    for(int i=0; i<n+1; i++)
        printf("%d ", data[i]);


    
}