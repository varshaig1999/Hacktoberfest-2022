# include<stdio.h>

int main(){
    int i=34;
    int *j = &i;   //j will now store address of i.  pointer to a pointer is used to store address of that
    printf("The value of i is %d\n", i);     //which already stores address of another variable.
    printf("The value of i is %d\n", *j);    // we use ** for pointer to pointer
    printf("The address of i is %u\n", &i);  //        *** for pointer to pointer to pointer and so on.....
    printf("The address of i is %u\n", j);   // here if another variable k stores address of j then we use
    printf("The address of j is %u\n", &j);  // pointer  to pointer.
    printf("The value of j is %u\n", *(&j));
    return 0;
}