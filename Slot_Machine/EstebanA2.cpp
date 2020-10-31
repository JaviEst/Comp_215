/* File name: EstebanA2.cpp
 * Javier Esteban de Celis
 * September 21st 2018
*/

#include <iostream>
#include "EstebanA2.h"

using namespace std;

const short aValue = 40;
const short bValue = 62;
const short cValue = 72;
const short dValue = 87;
const short eValue = 92;
const short fValue = 101;


//------- CLASS reel ---------------------------------------------------------------
char reel::spinReel()
/*
PRE:  None
POST: Gets a random number between 0 and 100 and returns a letter based on the range of the game
*/
{
    long num = (rand() % 100);

    if (num < aValue) {
        return ('a');
    }
    else if (num > aValue && num < bValue) {
        return ('b');
    }
    else if (num > bValue && num < cValue) {
        return ('c');
    }
    else if (num > cValue && num < dValue) {
        return ('d');
    }
    else if (num > dValue && num < eValue) {
        return ('e');
    }
    else if (num > eValue && num < fValue) {
        return ('f');
    }
}
//----------------------------------------------------------------------------------



//------- CLASS slotMachine --------------------------------------------------------
void slotMachine::askFund()
/*
PRE:  None
POST: fund has a new value (input from user)
*/
{
    cout << "How many coins do you want to enter into the slot machine?" << endl;
    cin >> this->fund;
}

void slotMachine::setBet()
/*
PRE:  None
POST: bet has a new value (input from user)
*/
{
    cout << "How many coins do you want to use?" << endl;
    cin >> this->numCoinsUsed;
}

void slotMachine::updateFund()
/*
PRE:  None
POST: update the fund / Fund equals to fund minus the bet
*/
{
    this->fund = this->fund - this->numCoinsUsed;
}


void slotMachine::spin()
/*
PRE:  numReels has a number between 3 and 5 including both and symbols array exists
POST: calls the spinReel method from the base class. The symbols obtained from the spin are held by the symbols array
*/
{
    for (int i = 0; i < numReels; i++)
    {
        symbols[i] = reel::spinReel();
    }

}

bool slotMachine::checkArray()
/*
PRE:  None
POST: checks the elements of the array are equal
*/
{
    bool check = true;

    for(int i = 0; i < numReels - 1; i++)
    {
        if(symbols[i] != symbols[i + 1])
            check = false;
    }

    return check;
}

void slotMachine::checkReels(short val)
/*
PRE:  val assigned
POST: updated the coins gained if you win the bet
*/
{
    short two = 2;
    short three = 3;
    if (numReels == 3)
    {
        this->wonCoins = this->numCoinsUsed * val;
    }
    else if (numReels == 4)
    {
        this->wonCoins = this->numCoinsUsed * (two*val);
    }
    else if (numReels == 5)
    {
        this->wonCoins = this->numCoinsUsed * (three*val);
    }
}

void slotMachine::checkWin()
/*
PRE:  None
POST: checks if you win the bet
*/
{
    bool check;

    check = checkArray();

    if(check)
    {
        if (this->symbols[0] == 'a')
        {
            checkReels(2);
        }
        else if (this->symbols[0] == 'b')
        {
            checkReels(4);
        }
        else if (this->symbols[0] == 'c')
        {
            checkReels(3);
        }
        else if (this->symbols[0] == 'd')
        {
            checkReels(5);
        }
        else if (this->symbols[0] == 'e')
        {
            checkReels(15);
        }
       else if (this->symbols[0] == 'f')
        {
            checkReels(8);
        }
    }
    else
    {
        if (this->fund == 0)
        {
            this->gameSituation = false;
        }
    }
}

void slotMachine::updateFundWin()
/*
PRE:  None
POST: updates the total fund if you win the bet
*/
{
    this->fund = this->fund + this->wonCoins;
}


void slotMachine::displaySymbols()
/*
PRE:  symbols array exists
POST: displays the symbols that you got from spinning the reel
*/
{
    for (int i = 0; i < this->numReels; i++)
        cout << symbols[i];

    cout << endl;
}

void slotMachine::displayWinnings()
/*
PRE:  wonCoins is defined
POST: displays the coins gained if any
*/
{
    cout << "Coins Gained: " << this->wonCoins << endl;
}

void slotMachine::displayFund()
/*
PRE:  None
POST: displays the total fund
*/
{
    cout << "Fund: " << this->fund << endl;
}

bool slotMachine::cashOut()
/*
PRE:  None
POST: asks the user if they want to cash out. Sets gameSituation to true or false depending of the response
*/
{
    string decision;

    cout << "Do you want to Cash out?" << endl;
    cin >> decision;

    if (decision[0] == 'Y' || decision[0] == 'y')
    {
        this->gameSituation = false;
    }
    else
    {
        cout << "Let's keep playing!" << endl;

        this->gameSituation = true;
    }
}

bool slotMachine::gameCondition()
/*
PRE:  None
POST: returns true if the fund is greater than 0 and if the user doesn't want to cash out
      return false if the fund is equal or less than 0 and if the user wants to cash out
*/
{
    if (this->fund == 0 || this->fund < 0 || this->gameSituation == false)
    {
        cout << "Your final Final Fund is: " << this->fund << endl;
        cout << "THANK YOU FOR PLAYING WITH US!!" << endl;

        return false;
    }
    else
    {
        return true;
    }
}
//----------------------------------------------------------------------------------



//------- CLASS threeReels ---------------------------------------------------------
threeReels::threeReels()
/*
PRE:  None
POST: sets numReels to 3
*/
{
    this->numReels = 3;
}

void threeReels::displayTable()
/*
PRE:  None
POST: Displays slot machine play tables for 3 reels
*/
{
    cout << "Symbol" << "   " << "Bet x" << endl;
    cout << "---------------" << endl;
    cout << "| aaa " << " | " << " 2x  |" << endl;
    cout << "| bbb " << " | " << " 4x  |" << endl;
    cout << "| ccc " << " | " << " 3x  |" << endl;
    cout << "| ddd " << " | " << " 5x  |" << endl;
    cout << "| eee " << " | " << " 15x |" << endl;
    cout << "| fff " << " | " << " 8x  |" << endl;
    cout << "---------------" << endl;



}
//----------------------------------------------------------------------------------



//------- CLASS fourReels ----------------------------------------------------------
fourReels::fourReels()
/*
PRE:  None
POST: sets numReels to 4
*/
{
    this->numReels = 4;
}

void fourReels::displayTable()
/*
PRE:  None
POST: Displays slot machine play tables for 4 reels
*/
{
    cout << "Symbol" << "   " << "Bet x" << endl;
    cout << "---------------" << endl;
    cout << "| aaaa " << " | " << " 4x  |" << endl;
    cout << "| bbbb " << " | " << " 8x  |" << endl;
    cout << "| cccc " << " | " << " 6x  |" << endl;
    cout << "| dddd " << " | " << " 10x |" << endl;
    cout << "| eeee " << " | " << " 30x |" << endl;
    cout << "| ffff " << " | " << " 16x |" << endl;
    cout << "---------------" << endl;
}
//----------------------------------------------------------------------------------



//------- CLASS fiveReels ----------------------------------------------------------
fiveReels::fiveReels()
/*
PRE:  None
POST: sets numReels to 5
*/
{
    this->numReels = 5;
}

void fiveReels::displayTable()
/*
PRE:  None
POST: Displays slot machine play tables for 5 reels
*/
{
    cout << "Symbol" << "   " << "Bet x" << endl;
    cout << "----------------" << endl;
    cout << "| aaaaa " << " | " << " 6x  |" << endl;
    cout << "| bbbbb " << " | " << " 12x |" << endl;
    cout << "| ccccc " << " | " << " 9x  |" << endl;
    cout << "| ddddd " << " | " << " 15x |" << endl;
    cout << "| eeeee " << " | " << " 45x |" << endl;
    cout << "| fffff " << " | " << " 24x |" << endl;
    cout << "----------------" << endl;
}
//----------------------------------------------------------------------------------
