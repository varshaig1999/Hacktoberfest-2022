# include<stdio.h>

int main(){                      
    int a=3;
    printf("%d %d %d", a, ++a, a++);   // result is due to compiler takes this code from right to left.
    return 0;
}