#include "score.h"
#include "gameScreens.h"

#include <stdlib.h>
#include <stdio.h>

int rps() {
    int player_score;
    int computer_score;

    read_scores(&player_score, &computer_score);
    enter_menu(&player_score, &computer_score);
    write_scores(&player_score, &computer_score);
    //free(scores);
    return 0;
}

int main()
{
    rps();
    return 0;
}