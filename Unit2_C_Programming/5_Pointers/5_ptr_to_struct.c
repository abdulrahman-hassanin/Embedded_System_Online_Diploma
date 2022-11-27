#include <stdio.h>

struct SEmpolyee
{
    char name[50];
    int id;
};

void main()
{
    // 280-26-99

    struct SEmpolyee emp1 = {"john", 101}, emp2={"Alex", 102}, emp3={"Tayolr", 103};
    struct SEmpolyee (*arr[]) = {&emp1, &emp2, &emp3};
    struct SEmpolyee (*(*pt)[3]) = &arr;

    printf("Emplyee Name: %s \n", (**(*pt+1)).name);

    printf("------------------Explanation-----------\n");
    printf("(**(*pt+1)).name\n");
    printf("= (**(*&arr+1)).name     as pt=&arr\n");
    printf("= (**(arr+1)).name       from rule *&pt=pt\n");
    printf("= (*arr[1]).name         from rule *(pt+i)=pt[i]\n"); 
    printf("= (*&emp2).name          from rule arr[1]=&emp2\n"); 
    printf("= emp2.name = Alex       from rule *&pt=pt\n"); 
    printf("\n\n");

    printf("Employee ID: %d\n", (*(*pt+1))->id);
    printf("------------------Explanation-----------\n");
    printf("(*(*pt+1))->id\n");
    printf("(*(*pt+1)).id           from rule -> = (*).\n");
    printf("= emo2.id = 102 \n");
    printf("\n\n");

}