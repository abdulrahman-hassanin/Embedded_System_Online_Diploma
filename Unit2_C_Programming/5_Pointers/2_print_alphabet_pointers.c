#include <stdio.h>

void main()
{
    char alpha[27];
    char* ptr;
    ptr = alpha;
    printf("The alphabets are:\n");
    for(int i=0; i<26; i++)
    {
        *ptr = 'A' + i;
        printf("%c ", *ptr);
        ptr++;
    }
    
}