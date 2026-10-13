#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void display_map(char print_map[][10],int *health, int *energy);
void reset_map(char print_map[][10]);
void place_wall_enemy(char real_map [][10]);
void update_flash(char real_map[][10], char print_map[][10], int *st_r, int *st_c);
void up (char print_map[][10], int *st_r, int *energy);
void down (char print_map[][10], int *st_r, int *energy);
void left (char print_map[][10], int *st_c, int *energy);
void right (char print_map[][10], int *st_c, int *energy);

int main(){

    char real_map[10][10] = {
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}
    };
    real_map[0][0] = 'S';  //start
    real_map[9][9] = 'X';  //end
    
    char print_map[10][10] = {
        {'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
        {'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
        {'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
        {'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
        {'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
        {'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
        {'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
        {'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
        {'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'},
        {'?', '?', '?', '?', '?', '?', '?', '?', '?', '?'}
    };
    int health = 3, energy = 25;

    place_wall_enemy(real_map);

    int st_r=0, st_c=0;
    printf("WELCOME to BB!");
    printf("\nYour player is currently at Start (S), depicted by P\n");
    printf("Your target is to reach X. E depicts enemy, # depicts walls, be careful\nBest of LUCK\n");
    while (energy >= 0 && health >= 0){

        reset_map(print_map);
        update_flash(real_map, print_map, &st_r, &st_c);
        display_map(print_map, &health, &energy);

        char move;
        printf("Enter your next move: \nPress W, A, S, D for up, left, down and right respectively \n");
        scanf(" %c", &move);
        char move_upper = toupper(move);

        switch(move_upper) {
            case 'W': 
            if(st_r == 0){
                printf("Boundry reached!\n");
                energy--;
                break;
            }
            if(real_map[st_r-1][st_c] == '#' || real_map[st_r-1][st_c] == 'E'){
                printf("Ouch!! Thats a wrong step. Be Carefull!\n");
                if(real_map[st_r-1][st_c] == '#') energy -- ;
                else health --, energy-- ;
                break;
            }
            up(print_map, &st_r, &energy);
            break;
            case 'A':
            if(st_c == 0){
                printf("Boundry reached!\n");
                energy--;
                break;
            }
            if(real_map[st_r][st_c-1] == '#' || real_map[st_r][st_c-1] == 'E'){
                printf("Ouch!! Thats a wrong step. Be Carefull!\n");
                if(real_map[st_r][st_c-1] == '#') energy -- ;
                else health --, energy-- ;
                break;
            }
            left(print_map, &st_c, &energy);
            break;
            case 'S':
            if(st_r == 9){
                printf("Boundry reached!\n");
                energy--;
                break;
            }
            if(real_map[st_r+1][st_c] == '#' || real_map[st_r+1][st_c] == 'E'){
                printf("Ouch!! Thats a wrong step. Be Carefull!\n");
                if(real_map[st_r+1][st_c] == '#') energy -- ;
                else health --, energy-- ;
                break;
            }
            down(print_map, &st_r, &energy);
            break;
            case 'D': 
            if(st_c == 9){
                printf("Boundry reached!\n");
                energy--;
                break;
            }
            if(real_map[st_r][st_c+1] == '#' || real_map[st_r][st_c+1] == 'E'){
                printf("Ouch!! Thats a wrong step. Be Carefull!\n");
                if(real_map[st_r][st_c+1] == '#') energy -- ;
                else health --, energy--;
                break;
            }
            right(print_map, &st_c, &energy);
            break;
        }
        
        if(real_map[st_r][st_c] == 'X') {
            printf("CONGRATULATIONS!!! YOU WON THIS LEVEL!!!");
        break;
        }
        if(health == 0 || energy == 0){
            if (real_map[st_r][st_c] != 'X'){
                printf("You lost. Try Again!!!");
                break;
            }
        }
    }

    return 0;
}

void display_map (char print_map[][10], int *health, int *energy){
    printf("=============================================\n");
    printf("YOUR HEALTH IS: %d/3 ||  YOUR ENERGY IS %d/25\n", *health, *energy);
    printf("=============================================\n");
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            printf("%c ", print_map[i][j]);
        }
    printf("\n");
    }   
    printf("=============================================\n"); 
}

void place_wall_enemy(char real_map[][10]){
    int placed1 = 0;
    srand (time(NULL));
    while (placed1<10){   //Placing walls
        int r1 =  rand() % 10;
        int c1 = rand() % 10;
        if (real_map[r1][c1] == '.'){
            real_map[r1][c1] = '#';
            placed1 ++ ;
        }
    }
    int placed2 = 0;
    while (placed2<10){    //Placing enemies
        int r2 =  rand() % 10;
        int c2 = rand() % 10;
        if (real_map[r2][c2] == '.'){
            real_map[r2][c2] = 'E';
            placed2 ++ ;
        }
    }   
}

void down (char print_map[][10], int *st_r, int *energy){
    if(*st_r == 9){
        printf("Wrong move\n");
    }else{
        (*st_r)++;
    }
    (*energy) -- ;
}

void up (char print_map[][10], int *st_r, int *energy){
    if(*st_r == 0){
        printf("Wrong move\n");
    }else{
        (*st_r)--;
    }
    (*energy) -- ;
}

void right (char print_map[][10], int *st_c, int *energy){
    if(*st_c == 9){
        printf("Wrong move\n");
    }else{
        (*st_c)++;
    }
    (*energy) -- ;
}

void left (char print_map[][10], int *st_c, int *energy){
    if(*st_c == 0){
        printf("Wrong move\n");
    }else{
        (*st_c)--;
    }
    (*energy) -- ;
}

void reset_map(char print_map[][10]){
    for (int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            print_map[i][j] = '?';
        }
    }
}

void update_flash(char real_map[][10], char print_map[][10], int *st_r, int *st_c){
    
    for (int i=-1; i<=1; i++){
        for (int j=-1; j<=1; j++){
            int r = *st_r + i;
            int c = *st_c + j;

            if(r>=0 && r<10 && c>=0 && c<10){
                print_map[r][c] = real_map[r][c];
            }
        }
    }
    print_map [9][9] = 'X';
    print_map [*st_r][*st_c] = 'P';
}

