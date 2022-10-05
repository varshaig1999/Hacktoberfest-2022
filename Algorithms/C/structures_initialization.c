#include <stdio.h>
#include <string.h>
struct employee
{             // One way to initialize structure is by using memeber operator .
    int code; // another way is given here
    float salary;
    char name[15]; // stored as a contiguous memeory allocation.
};
int main()
{
    struct employee Phaham = {100, 1000.50, "Phaham"};
    printf("Code is: %d \n", Phaham.code);
    printf("Salary is: %.3f \n", Phaham.salary);
    printf("Name is: %s \n", Phaham.name);

    return 0;
}