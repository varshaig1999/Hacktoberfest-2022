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
    struct employee e1;
    struct employee *ptr;

    ptr = &e1;
    // (*ptr).code = 101;
    ptr->code = 101; //← you can also write this,           -> this is arrow operator.
    printf("%d", e1.code);
}