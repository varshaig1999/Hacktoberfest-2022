#include <stdio.h>

int main()
{
    int marks;
    printf("Enter Marks obtained in  Subject: ");
    scanf("%d", &marks);
    printf("\nGrade = ");
    if (marks >= 75 && marks <= 100)
        printf("O");
    else if (marks >= 60 && marks < 75)
        printf("A");
    else if (marks >= 50 && marks < 60)
        printf("B");
    else if (marks >= 40 && marks < 50)
        printf("C ");
    else if (marks >= 0 && marks < 40)
        printf("D");

    else
        printf("Invalid!");
    return 0;
}