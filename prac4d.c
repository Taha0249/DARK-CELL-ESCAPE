#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int guess, i;
    srand(time(0));
    int num = rand()%100 +1;

    for (i=0; i<5; i++){
        printf("Enter your guess: \n");
        scanf("%d", &guess);

        if (guess == num){
            printf("Correct, you won!!!\n");
            break;
        }else if(guess < num){
            printf("Your guess is low\n");
        }else{
            printf("Your guess is high\n");
        }
    }

    if(i == 5 && num!=guess) printf("You lost, the number was: %d", num);
    return 0;
}