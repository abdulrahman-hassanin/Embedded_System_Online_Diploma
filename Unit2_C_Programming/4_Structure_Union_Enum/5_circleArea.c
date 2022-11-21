#include <stdio.h>

#define PI 3.1315
#define area(r) ((PI) * (r) * (r))

void main()
{
    int radius;
    float areaa;
    printf("Enter radius: ");
    scanf("%d", &radius);
    areaa = area(radius);
    printf("Area = %.2f", areaa);
}