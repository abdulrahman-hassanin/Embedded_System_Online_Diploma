#include <stdio.h>

struct SDistance{
    int feet;
    float inch;
};

void main()
{
    struct SDistance D1, D2, Sum;
    printf("Enter information for 1st distance: \n");
    printf("Enter feet: ");
    scanf("%d", &D1.feet);
    printf("Enter inch: ");
    scanf("%f", &D1.inch);
    printf("Enter information for 2nd distance: \n");
    printf("Enter feet: ");
    scanf("%d", &D2.feet);
    printf("Enter inch: ");
    scanf("%f", &D2.inch);

    Sum.feet = D1.feet + D2.feet;
    Sum.inch = D1.inch + D2.inch;

    // If inch is greater than 12, change it to feet
    if(Sum.inch > 12.0){
        Sum.inch -= 12;
        ++Sum.feet;
    }
    
    printf("\nSum of Distance = %d\' - %.2f\'' ", Sum.feet, Sum.inch);
}