#include <stdio.h>
#include <string.h>
typedef struct employee // typedef used to create custom datatypes
{                       // typedef more commonly used with structures.
    int code;
    float salary;
    char name[15];
} emp;

void show(emp emp1)
{
    printf("The code of employee is: %d\n", emp1.code);
    printf("The Salary of employee is: %f\n", emp1.salary);
    printf("The name of employee is: %s\n", emp1.name);
}
int main()
{
    // declaring e1 and ptr
    emp e1;
    emp *ptr;

    //pointing ptr to e1
    ptr = &e1;
    // (*ptr).code = 101;

    // set number values for e1
    ptr->code = 101; //← you can also write this,           -> this is arrow operator.
    printf("%d", e1.code);
}