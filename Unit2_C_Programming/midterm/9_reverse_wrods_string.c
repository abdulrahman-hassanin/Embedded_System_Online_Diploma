#include <stdio.h>
#include <string.h>

void reverse_words(char str[], int len)
{
    char rev[50];
    int k=0;
    for(int i=len-1; i>=0; i--) {
        if(str[i] == ' ') {
            for(int j=i+1; str[j]!=' ' && j<len; j++){
                rev[k] = str[j];
                k++;
            }
            rev[k] = ' ';
            k++;
        }
        else if(i==0) {
            for(int j=i; str[j]!=' ' && j<len; j++){
                rev[k] = str[j];
                k++;
            }
        }
    }

    for(int i=0; i<len; i++)
        printf("%c", rev[i]);
}

void main()
{
    char str[50];
    puts("enter string:");
    gets(str);
    puts("the rversed words");
    reverse_words(str, strlen(str));
}