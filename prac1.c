#include <stdio.h>

int main(){
    int a;
    char ch;
    float fl;

    printf("Enter your first number \n");
    scanf("%d", &a);
    printf("Your first number is %d\n", a);

    printf("Enter a character \n");
    scanf(" %c", &ch);
    printf("Your character is %c \n", ch);

    printf("Enter a decimal value\n");
    scanf("%f", &fl);
    printf("The entered value is %f\n", fl);


    return 0;
}