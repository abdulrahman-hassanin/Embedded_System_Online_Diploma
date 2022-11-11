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
    printf("Enter element to be searched: ");
    fflush(stdin);      fflush(stdout);
    scanf("%d", &element);
    
    // search
    int found = 0;
    for(int i=0; i<n+1; i++)
        if(data[i] == element){
            found = 1;
            loc = i+1;
            break;
        }

    if(found)   
        printf("Number found at the location = %d", loc);
    else
        printf("Not found");
}