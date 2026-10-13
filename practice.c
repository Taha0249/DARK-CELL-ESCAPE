#include <stdio.h>

int main(){
    int st, end;
    printf("Enter two number: ");
    scanf("%d %d", &st, &end);

    for (int i=st; i<=end; i++){
        int condition = 1;
        for (int j=2; j*j<=i; j++){
            if(i%j == 0) {
                condition = 0;
                break;
            }
        }
        if (condition == 1) printf("%d ", i);
    }

    return 0;
}