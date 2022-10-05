# include<stdio.h>

int main(){
    int n=45, prime=0,i;
    for(i=2;i<n;i++){
        if (n%i==0){
            prime = i;
            break;
        }
    }
    if (prime==i){
        printf("This is a not prime number");
    }
    else{
        printf("This is a prime number");
    }
    return 0;
}