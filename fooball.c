#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct e {
    int touchdown;
    int field_goal;
    int safety;
    int touchdown_twopoint;
    int touchdown_onepoint;
} FootballResult;



void print_combo(FootballResult fbr){
    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3PT FG, %d Safety\n", fbr.touchdown_twopoint, fbr.touchdown_onepoint, fbr.touchdown, fbr.field_goal, fbr.safety);
}

void recursive_print_combinations(int score, int start, FootballResult fbr){

    if (score == 0){
        print_combo(fbr);
        return;
    }

    if (score < 0){
        return;
    }

    for (int type = start; type < 5; type++) {
        int points = 0;
        FootballResult next = fbr;

        switch (type) {
            case 0:
                points = 8;
                next.touchdown_twopoint++;
                break;

            case 1:
                points = 7;
                next.touchdown_onepoint++;
                break;

            case 2:
                points = 6;
                next.touchdown++;
                break;

            case 3:
                points = 3;
                next.field_goal++;
                break;

            case 4:
                points = 2;
                next.safety++;
                break;
        }

        recursive_print_combinations(
            score - points,
            type,
            next
        );
    }
}



int main(){
    int pos = 0;
    printf("Enter the NFL scores (Enter 1 to stop): ");
    while (scanf("%d", &pos) == 1 && pos != 1){
        //okay ahhh per mutations suck really really bad
        //but we'll do it
        //so the way to calculat epotential permutations is to get the 
        //integer division of possibilities right?
        //like lets say there's 14 points
        //it would be 14 / 7 2
        //so then we could like
        //recursively evaluate for some larger values?
        //seems difficult but we could do like branching
        //let's try that
        FootballResult fbr = {0, 0, 0, 0, 0};
        recursive_print_combinations(pos, 0, fbr);

        printf("Enter the NFL scores (Enter 1 to stop): ");
    }

    return 0;
}
