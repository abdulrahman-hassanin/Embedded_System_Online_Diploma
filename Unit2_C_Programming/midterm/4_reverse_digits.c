#include <stdio.h>

int reverseDigits(int num)
{
    static int rev_num = 0;
    int rem;
    if(num != 0)
    {
        rem = num%10;
        rev_num = rev_num*10 + rem;
        reverseDigits(num /= 10);
    }else{
        return 0;
    }
    return rev_num;
}

int main()
{
    int a;
    printf("Enter number: ");
    fflush(stdin);  fflush(stdout);
    scanf("%d", &a);
    int revNum = reverseDigits(a);
    printf("reverse number = %d", revNum);
}