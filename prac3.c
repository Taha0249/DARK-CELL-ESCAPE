#include <stdio.h>

int main(){
    int x;
    printf("Enter the number: ");
    scanf("%d", &x);

    if(x%10 == 0){
        printf("0");
    }else if(x%5 == 0){
        printf("1");
    }else{
        printf("-1");
    }

    return 0;
}
