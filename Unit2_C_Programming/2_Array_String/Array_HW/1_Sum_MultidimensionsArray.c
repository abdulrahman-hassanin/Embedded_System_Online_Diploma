#include <stdio.h>

void main()
{
    const int SIZE = 2;
    float arr1[SIZE][SIZE], arr2[SIZE][SIZE], SUM[SIZE][SIZE];

    printf("Enter the Elements of the 1st matrix:\n");
    for(int i=0; i<SIZE; i++)
        for(int j=0; j<SIZE; j++){
            printf("Enter a%d%d: ", i+1, j+1);
            fflush(stdin);  fflush(stdout);
            scanf("%f", &arr1[i][j]);
        }

    printf("Enter the Elements of the 2nd matrix:\n");
    for(int i=0; i<SIZE; i++)
        for(int j=0; j<SIZE; j++){
            printf("Enter a%d%d: ", i+1, j+1);
            fflush(stdin);  fflush(stdout);
            scanf("%f", &arr2[i][j]);
        }

    for(int i=0; i<SIZE; i++)
        for(int j=0; j<SIZE; j++)
            SUM[i][j] = arr1[i][j] + arr1[i][j];
            
    printf("Sum of matrix:\n");
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++)
            printf("%f\t", SUM[i][j]);
        printf("\n");
    }
}