#include <stdio.h>

void main()
{
    int arr[15];
    int *revPtr = arr;
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);

    printf("Enter the %d elements\n", size);
    for(int i=0; i<size; i++) {
        printf("Enter the %d element: ", i+1);
        scanf("%d", &arr[i]);
        revPtr++;
    }

    revPtr--;    
    printf("the %d elements in reverse order\n", size);
    for(int i=size-1; i>=0; i--) {
        printf("Element %d : %d\n", i+1, *revPtr);
        revPtr--;
    }
}