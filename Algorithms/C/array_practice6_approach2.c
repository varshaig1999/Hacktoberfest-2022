// Create an array of size 3 X 10 containing multiplication tables of the nummbers 2, 7 and 9 respectively.
void printTable(int *multable, int num, int n)
{
    printf("The multiplication table of %d is :\n", num);
    for (int i = 0; i < n; i++) //This is Approach 2 with using function.
    {
        multable[i] = num * (i + 1);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%dX%d = %d\n", num, i + 1, multable[i]);
    }
    printf("********************************************************\n\n");
}
#include <stdio.h>

int main()
{
    int multable[3][10];
    printTable(multable[0], 2, 10);
    printTable(multable[1], 7, 10);
    printTable(multable[2], 9, 10);
    return 0;
}