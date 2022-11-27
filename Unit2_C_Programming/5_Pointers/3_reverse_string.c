#include <stdio.h>

void main()
{
    char str[50];
    char revStr[50];
    char* strPtr = str;
    char* revStrPtr = revStr;

    printf("Enter a string: ");
    scanf("%s", str);

    int i =  -1;
    while (*strPtr)
    {
        strPtr++;
        i++;
    }
    
    while(i>=0) {
        strPtr--;
        *revStrPtr = *strPtr;
        revStrPtr++;
        i--;
    }

    *revStrPtr = '\0';
    printf("%s", revStr);
}