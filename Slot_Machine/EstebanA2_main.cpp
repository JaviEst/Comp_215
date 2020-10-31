/* File name: EstebanA2_main.cpp
 * Javier Esteban de Celis
 * September 21st 2018
*/

#include <iostream>
#include "EstebanA2.cpp"

using namespace std;


int main()
{
    srand(time(nullptr));                   // Seed the random numbers

    short reelsVal = 0;                     // Variable to hold the num of reels the user wants to use
    bool keepPlaying;                       // Variable to hold the condition of the game

    cout << "How many reels do you want to use (3, 4 or 5)? " << endl;
    cin >> reelsVal;

    slotMachine* S;

    // If and else if statement to determine what type of object the user needs
    if (reelsVal == 3)
    {
        threeReels T;
        S = &T;
    }
    else if (reelsVal == 4)
    {
        fourReels D;
        S = &D;
    }
    else if (reelsVal == 5)
    {
        fiveReels P;
        S = &P;
    }


    S->displayTable();
    S->askFund();

    keepPlaying = S->gameCondition();

    while (keepPlaying)
    {
        S->setBet();
        S->updateFund();
        S->spin();
        S->checkWin();
        S->updateFundWin();
        S->displaySymbols();
        S->displayWinnings();
        S->displayFund();
        S->cashOut();
        keepPlaying = S->gameCondition();
    }


    return 0;
}

