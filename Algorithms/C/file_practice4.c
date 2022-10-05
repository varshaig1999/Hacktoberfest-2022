#include <stdio.h>

int main()
{
    int salary;
    char name;

    FILE *ptr1;
    FILE *ptr2;
    ptr1 = fopen("file_practice4.txt", "w");
    ptr2 = fopen("file_practice4.txt", "w");
    fscanf(ptr1, "%d", &name);
    fscanf(ptr2, "%d", &salary);

    printf("Enter Your Name\n");
    scanf("%s", &name);
    printf("Now Enter Your Salary\n");
    scanf("%d", &salary);
    return 0;
}