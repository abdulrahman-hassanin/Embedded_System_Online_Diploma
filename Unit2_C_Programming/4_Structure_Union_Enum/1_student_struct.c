#include <stdio.h>

struct student{
    char name[50];
    int roll;
    float marks;
};

void main()
{
    struct student s;
    printf("Enter information of studnet: \n");
    printf("Enter Name: ");
    scanf("%s", s.name);
    printf("Enter roll: ");
    scanf("%d", &s.roll);
    printf("Enter marks: ");
    scanf("%f", &s.marks);

    printf("Displaying information of studnet: \n");
    printf("Name: %s\n", s.name);
    printf("Roll: %d\n", s.roll);
    printf("Marks: %.2f\n", s.marks);
}