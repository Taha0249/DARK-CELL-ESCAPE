#include <stdio.h>

int main(){
    int num;
    int ans = 0;
    printf("Enter a number: ");
    scanf("%d", &num);

    for(int i=2; i*i<=num; i++){
        if(num%i == 0){
            ans=1;
            break;
        }
    }

    if(ans == 0){
        printf("number is prime");
    }else{

        printf("Numeber is not prime");
    }
    return 0;
}