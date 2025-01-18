#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define init 0.5;

void main(){
    float bet = init;
    float totalBet = bet;
    int winProb = (int)round(10);
    float incLoss = 125.0;
    float multiplier = 7;
    float win = 0;
    // Counters
    int wins = 0, loss = 0;
    int limit = 5000;
    // Seed the rnadom number generator
    srand(time(0));
    for (int i=0; i<limit; i++){
        int random = (rand() % 100) + 1;
        printf("Dice Value: %d\n",random);
        if(random >= 100-winProb){
            printf("Bet = %f\n", bet);
            win = win + (bet * multiplier);
            printf("Win. Winning = %f\n\n", win);
            bet = init;
            totalBet += bet;
            wins+=1;
        }
        else {
            printf("Bet = %f\n", bet);
            win = win - bet;
            printf("Loss. Winning = %f\n\n", win);
            bet = bet + (bet*(incLoss/100));
            totalBet += bet;
            loss+=1;
        }
    }
    printf("\nAmount Wagered = %f, Total Winnings = %f, No of wins = %d No of loss = %d", totalBet, win, wins, loss);
}