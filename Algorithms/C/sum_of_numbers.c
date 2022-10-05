# include<stdio.h>

int main(){
    int n;
    int i, sum;
    printf("Enter value of n upto which you want sum of numbers\n");
    scanf("%d", &n);
    for(i=0; i<=n; i++){
         sum +=i;
    }
    printf("The value of sum is %d\n", n*(n+1)/2); 
    return 0;
}