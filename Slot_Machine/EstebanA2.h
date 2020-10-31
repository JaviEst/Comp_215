/* File name: EstebanA2.h
 * Javier Esteban de Celis
 * September 21st 2018
 *
 * Description: This is designed to play a slot machine game. You can play 3, 4, or 5 reels.
 *
 * Input:   1- The amount of reels you want to use (3, 4 , or 5).
 *          2- The total amount of coins you want to deposit in the slot machine.
 *          3- The amount you want to bet.
 *          4- Decision to cash out.
 *
 * Output:  1- Displays slot machine play tables for 3, 4 or 5 reels.
 *          2- Displays the symbols after spin.
 *          3- Displays the amount of coins gained if any.
 *          4- Displays the total fund.
 *          5- Displays a final message if the fund is 0 or less than zero or if the user decides to cash out.
 */


#include <iostream>

using namespace std;


class reel
{
    public:
        char spinReel();            // Spin method
};


class slotMachine:public reel
{
    public:
        void askFund();                     // Ask for the total funs
        void setBet();                      // Ask for the bet

        void updateFund();                  // Updates the fund
        void updateFundWin();               // Updates the fund if you win

        bool checkArray();                  // Checks all elements of the array are equal
        void checkWin();                    // Checks if you won

        void spin();                        // Calls the actual spin method from the base class

        virtual void displayTable() {}
        void displaySymbols();              // Displays the symbols
        void displayWinnings();             // Displays the amount gained
        void displayFund();                 // Displays the total amount of coins

        bool cashOut();                     // Method to ask the user if he/she wants to cash out

        void checkReels(short val);         // Checks the number of reels being used to help to update the fund

        bool gameCondition();               // Checks the game condition


    protected:
        short fund = 0;                     // Total amount of coins
        short numCoinsUsed = 0;             // Amount of coins bet
        short wonCoins = 0;                 // Amount of coins you won after a bet if any
        short numReels = 0;                 // Amount of reels used (3 - 5)
        char symbols [5] = {'\0'};          // Array to hold the chars after spin the reel
        bool gameSituation = true;          // Bool to check if the game condition is good
};


class threeReels:public slotMachine
{
    public:
        threeReels();                   // CTOR
        void displayTable();            // display method
};

class fourReels:public slotMachine
{
    public:
        fourReels();                    // CTOR
        void displayTable();            // display method
};

class fiveReels:public slotMachine
{
    public:
        fiveReels();                    // CTOR
        void displayTable();            // display method
};