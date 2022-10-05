#include <stdio.h>

int main()
{
    int a = 4, b = 3;
    scanf("%d, %d", &a, &b);
    printf("The numbers before swapping are %d,%d", a, b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("The numbers after swapping are %d, %d\n", a, b);
    return 0;
}