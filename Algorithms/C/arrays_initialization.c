#include <stdio.h>

int main()
{
    int a[] = {13, 15, 45};
    printf("The value of a[0] is %d\n", a[0]); //1 integer occupies space of 4 byte but it depends on the architecture of system
    printf("The value of a[1] is %d\n", a[1]); //means it may vary and if you are storing three integers then total space covered will be 12 bytes.
    printf("The value of a[2] is %d\n", a[2]); // you can also find address of next integer if address of starting integer known You just have to
    return 0;                                  // to add 4 to get next address and again 4 to previous one to get next address.
}
// 1 character occupies space of 1 byte.