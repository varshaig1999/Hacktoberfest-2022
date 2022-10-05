# include<stdio.h>
float force(float mass);
int main(){
    float m;
    printf("Enter mass in kg\n");
    scanf("%f",&m);
    printf("The value of force in newton is %f\n", force(m));    //use decimal number before f to grt up to
                                                                // which decimal place you want your answer 
    
    return 0;
}
float force(float mass){
    float result= mass*9.8;
    return result;
}