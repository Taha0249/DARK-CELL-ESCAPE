#include <stdio.h>

int main(){

    for (char ch1='A'; ch1<='D'; ch1++){
        for (char ch2='A'; ch2<=ch1; ch2++){
            printf("%c ", ch2);
        }
        printf("\n");
    }

    return 0;
}