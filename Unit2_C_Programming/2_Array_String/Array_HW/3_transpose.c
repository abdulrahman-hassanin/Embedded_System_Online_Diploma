#include <stdio.h>

void main()
{
    const int SIZE = 100;
    int r, c;
    int data[SIZE][SIZE];
    printf("Enter rows and columns of the matrix: ");
    fflush(stdin);      fflush(stdout);
    scanf("%d%d", &r, &c);
    while ((r>100 || r<1) && (c>100 || c<1))
    {
        printf("ERROR! Number should be in range of 1 and 100");
        printf("Enter rows and columns of the matrix: ");
        fflush(stdin);      fflush(stdout);
        scanf("%d%d", &r, &c);
    }

    printf("Enter elements of the matrix:\n");
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++){
            printf("Enter elements of a%d%d: ", i+1, j+1);
            fflush(stdin);      fflush(stdout);
            scanf("%d", &data[i][j]);
        }

    printf("Entered matrix:\n");
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++)
            printf("%d\t", data[i][j]);
        printf("\n");
    }

    printf("Transpose of matrix:\n");
    for(int i=0; i<c; i++){
        for(int j=0; j<r; j++)
            printf("%d\t", data[j][i]);
        printf("\n");
    }

    
}