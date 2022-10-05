// Create an array of size 3 X 10 containing multiplication tables of the nummbers 2, 7 and 9 respectively.
#include <stdio.h>

int main()
{
    int multable[3][10];
    printf("The multiplication table of 2 is :\n");
    for (int i = 0; i < 10; i++) //This is Approach 1 without using function.
    {
        multable[0][i] = 2 * (i + 1);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("2X%d = %d\n", i + 1, multable[0][i]);
    }
    printf("********************************************************\n");

    printf("The multiplication table of 7 is :\n");
    for (int i = 0; i < 10; i++)
    {
        multable[0][i] = 7 * (i + 1);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("7X%d = %d\n", i + 1, multable[0][i]);
    }
    printf("********************************************************\n");

    printf("The multiplication table of 9 is :\n");
    for (int i = 0; i < 10; i++)
    {
        multable[0][i] = 9 * (i + 1);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("9X%d = %d\n", i + 1, multable[0][i]);
    }
    printf("********************************************************\n");
    return 0;
}