#include <stdio.h>

char isZero(char num, char bit){
    if(num & (1<<bit))
        return 0;
    return 1;
}

char maxNumberOfOnes(int num)
{
    char maxOnes = 0;
    char l, r;
    // find first zero
    for(char i=0; i<32; i++)
        if(isZero(num, i)) {
            r = i;
            break;
        }

    for(char j=r+1; j<32; j++)
        if(isZero(num, j)){
            l = j;
            char range = l - r -1;
            maxOnes = maxOnes > range ? maxOnes : range;
            r = l;
        }
        
    return maxOnes;
}

int main()
{
    int a;
    printf("Enter number: ");
    fflush(stdin);  fflush(stdout);
    scanf("%d", &a);
    char ones = maxNumberOfOnes(a);
    printf("max number of ones = %d", ones);
}