#include <stdio.h>
#include <string.h>
struct employee
{
    int code;
    float salary;
    char name[15];
};
int main()
{
    struct employee facebook[100];

    facebook[0].code = 100;
    facebook[0].salary = 1000.50;
    strcpy(facebook[0].name, "Phaham");

    facebook[1].code = 101;
    facebook[1].salary = 600.50;
    strcpy(facebook[0].name, "Aj");

    facebook[2].code = 102;
    facebook[2].salary = 400.50;
    strcpy(facebook[0].name, "Sm");

    printf("Done");

    return 0;
}