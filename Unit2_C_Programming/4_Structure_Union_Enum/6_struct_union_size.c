#include <stdio.h>

union job   
{
    char name[32];
    float salary;
    int worker_no;
}u;

struct job1   
{
    char name[32];
    float salary;
    int worker_no;
}s;

void main(){
    printf("Size of Union = %d\n", sizeof(u));
    printf("Size of Struct = %d\n", sizeof(s));
}
