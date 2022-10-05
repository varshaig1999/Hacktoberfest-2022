# include<stdio.h>

int main(){
    int n;
    int i,fact = 1;
    printf("Enter the value of number\n");
    scanf("%d", &n);
    for (i=1; i<=n; i++){
        fact = fact * i;
    }
    printf("The factorial of %d is %d\n", n, fact);
    return 0;
}