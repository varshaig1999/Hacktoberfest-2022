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
    // int code = 095;
    // char name = 'Phaham';
    struct employee e1;
    e1.code = 95; //  . is a member operator to initialize the structure.
    e1.salary = 10000;
    // e1.name = Phaham;  won't work we have to use strcpy to perform this action
    strcpy(e1.name, "Phaham");
    printf("%d\n", e1.code);
    printf("%.3f\n", e1.salary);
    printf("%s\n", e1.name);

    //structures can hold- dissimiliar data while arrays and strings can hold only similat data
    return 0;
}