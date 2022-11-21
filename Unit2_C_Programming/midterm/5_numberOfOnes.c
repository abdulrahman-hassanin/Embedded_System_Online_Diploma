#include <stdio.h>

char onesBinary(int num)
{
    int count = 0;
    for(int i=0; i<32; i++)
        if(num & (1<<i))
            count++;
    return count;
}

int main()
{
    int a;
    printf("Enter number: ");
    fflush(stdin);  fflush(stdout);
    scanf("%d", &a);
    char ones = onesBinary(a);
    printf("number of ones = %d", ones);
}