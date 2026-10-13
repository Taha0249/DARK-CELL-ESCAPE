#include <stdio.h>


int main(){

    int num=1;
    char ch='A';
    int n=4;

    for (int i=0; i<n; i++){
        for (int j=1; j<n-i; j++){
            printf(" ");
        }
        for (int k=0 ;k<=i; k++){
            printf("*");
        }
        for(int l=0; l<i; l++){
            printf("* ");
        }
        printf("\n");

    }

    return 0;
}