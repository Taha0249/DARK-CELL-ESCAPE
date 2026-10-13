#include <stdio.h>

int main(){
    int a=10, b=20, greater;

    greater = (a>b)? a: b;

    printf("The greatest number amongst two is: %d", greater);
    return 0;
}