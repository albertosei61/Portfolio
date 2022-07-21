//Albert Osei
// CSE 112 Week 2
// Drink Machine


#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

const int NUM_DRINKS = 5;

struct DrinkData
{
 string name;
 double price;
 int num;
};





void transaction (DrinkData m[], int menuChoice) //Handles the transaction
{

    double moneyamt;

    if (m[menuChoice].num == 0)
    {
        cout << "That drink is sold out.";
        return;
    }


    cout << "Enter the amount of money you have: ";
    cin >> moneyamt;

    if (moneyamt >= m[menuChoice].price)
    {
      cout << "Thump, thump, thump, splat!" << endl;
      cout << "Enjoy your drink!" << endl;

      cout << "Change: " << (moneyamt - m[menuChoice].price) << endl;
      cout << "Your change, " << (moneyamt - m[menuChoice].price) << " has just dropped into the dispenser.";


      m[menuChoice].num --;

      cout << "There are " << m[menuChoice].num << " drinks left in the machine.";

    }
}


int getChoice(DrinkData m[])   // Get user choices
{

    int menuChoice;

    cout << endl;

    for (int i = 0; i < NUM_DRINKS; i++)
    {
        cout << "    " << (i+1) << ") " << m[i].name;
        cout << m[i].price << "(" << m[i].num << ") remaining" << endl;
    }

    cout << "   " << (NUM_DRINKS + 1) << ")  Leave the drink machine";

    cout << "    Choose one: ";
    cin >> menuChoice;

    while (menuChoice < 1 || menuChoice > 6)
    {
        cout << "Bad Choice.  Choose a number 1-5: ";
        cin >> menuChoice;
    }

    menuChoice = menuChoice - 1;
    return menuChoice;
}




int main()
{
    int menuChoice;

    DrinkData machine[NUM_DRINKS] = {
                        {"Cola     ", 0.75, 20},
                        {"Root Beer", 0.75, 20},
                        {"Lemon-Lime", 0.75, 20},
                        {"Grape Soda", 0.80, 20},
                        {"Cream Soda", 0.80, 20}
 };

 cout << fixed << showpoint << setprecision(2);

 menuChoice = getChoice(machine);
 while (menuChoice != 5)
 {
     transaction(machine, menuChoice);
     menuChoice = getChoice(machine);
 }



}
