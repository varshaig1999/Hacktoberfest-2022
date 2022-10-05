#include <stdio.h>

int main() // typecasting larger datatype will get precedence its of two type implicit and explicit
{
    int a = 20;                                         // int a,b
    int b = 5;                                          //float c;
                                                        //printf("Enter two values")''
    printf("Addition of a and b is %d\n", a + b);       //scanf("%d%f", &a &b)
    printf("Subtraction of a and b is %d\n", a - b);    //c = (float)a/b; --> explicit typecasting
    printf("Multiplication of a and b is %d\n", a * b); // if you changed b to a float value then implicit typecasting occur
    printf("Division of a by b is %d\n", a / b);        // means program automatically display result in float value
    printf("Modulo division of a and b is %d\n", a % b);

    return 0;
}