#include <stdio.h>

int main()
{
    int principal_value;
    float rate;
    int time;

    printf("Enter the pricipal value\n");
    scanf("%d", &principal_value);

    printf("Enter the value of rate\n");
    scanf("%f", &rate);

    printf("Enter the value of time\n");
    scanf("%d", &time);

    printf("The value of simple interest is %f", principal_value * rate * time / 100);

    return 0;
}