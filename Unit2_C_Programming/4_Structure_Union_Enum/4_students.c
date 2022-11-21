#include <stdio.h>

struct student{
    char name[50];
    int roll;
    float marks;
};

void main()
{
    struct student s[10];
    printf("Enter information of studnets: \n");
    
    for(int i=0; i<10; i++){
        printf("Enter information of studnet %d: \n", i+1);
        printf("Enter Name: ");
        scanf("%s", s[i].name);
        printf("Enter roll: ");
        scanf("%d", &s[i].roll);
        printf("Enter marks: ");
        scanf("%f", &s[i].marks);
    }

    printf("Displaying information of studnets: \n");
    
    for(int i=0; i<10; i++){
        printf("Displaying information of studnet %d: \n", i+1);
        printf("Name: %s\n", s[i].name);
        printf("Roll: %d\n", s[i].roll);
        printf("Marks: %.2f\n", s[i].marks);
    }
}