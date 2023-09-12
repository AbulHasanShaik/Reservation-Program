#include <iostream>
#include <iomanip>
#include <string>
#include "Tornado.h"  // To include the Tornado class file


const int NUM_CATEG = 7;
const string cat_type[NUM_CATEG] = {"TBD","F0","F1","F2","F3","F4","F5"};


//Function Prototypes
int printMenu();
int printData(Tornado storm[],int NUM_ITEMS);
int editData(Tornado storm[],int NUM_ITEMS );
int updateDamage(Tornado storm[],int NUM_ITEMS);


const int NUM_ITEMS = 5;
int main()
{
    Tornado storm[NUM_ITEMS] = {
                                Tornado("McCurtain", F2, 450000),
                                Tornado("Red River", F3, 1410750),
                                Tornado("Camp County", F2,750250),
                                Tornado("Cass County",TBD, 295000),
                                Tornado()
                                };

    double totalDamage; //To hold the total damage value
    double editDamage; // To hold the users new damage
    int userInput2; //To hold the userInputs as integer


    do {

    userInput2 = printMenu();

    if(userInput2 == 1) //Print all items in the array
    {
        userInput2 = printData(storm, NUM_ITEMS);
    }

    else if(userInput2 == 2) //Allow the user to edit a specific item form the array
    {
        userInput2 = editData(storm, NUM_ITEMS);

    }

    else if(userInput2 == 3) //Allows the user to update damages of all items and also shows the current damage of the item.
    {
       userInput2 = updateDamage(storm, NUM_ITEMS);

    }

    }while(userInput2!=4);



    return 0;
}

//Functions
int printMenu() //Prints the menu
{
    int selectChoice;
    cout << endl;

    // ...<present the user with a menu>...
    cout << "Press 1 " << left << "To print the information for all items." << endl;
    cout << "Press 2 " << left << "To edit a particular item." << endl;
    cout << "Press 3 " << left << "To update the damage for all array items ." << endl;
    cout << "Press 4 "  << left << "To EXIT the program" << endl;
    cout << "\nEnter the option you would like to choose: " ;
    cin >> selectChoice;

     cout << "\n" ;

     return selectChoice;
}

//Function to print the data
int printData(Tornado storm[],int NUM_ITEMS)
{
    double totalDamage;

    cout << setw(14) << "City Name:"
     << setw(8) << "Category: " << setw(8)
     << setw(16) << "Damage Caused: \n";
    cout << "-------------------------------------\n";

    totalDamage = 0;
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        cout << setw(19) << storm[i].getLocation();
        cout << setw(12) << cat_type[storm[i].getCategory()];
        cout << setw(20)<< setprecision(8) << storm[i].getDamage() << endl;
        totalDamage += storm[i].getDamage();
    }
    cout << setw(20)<< setprecision(8) << "\nThe total damage is: " << totalDamage << endl;
    cout << "\n";

        return 0;
}

//Function  to edit the data
int editData(Tornado storm[],int NUM_ITEMS )
{
    string locationName; //String of characters to store the location
    double editDamage; // To hold the users new damage
    int cat;
    Category category;
    int userInput;

    for (int i = 0; i < NUM_ITEMS; i++)
    {
        cout << i+1 << ". "  << setw(19) << storm[i].getLocation();
        cout << setw(12) << cat_type[storm[i].getCategory()];
        cout << setw(20)<< setprecision(8) << storm[i].getDamage() << endl;
    }
    cout << "\n";


    cout << "Enter the item you would like to edit from 1-5: ";
    cin >> userInput;
    cout << "\n";


    cout << "Current data inside the item is the following\n";
    cout << setw(19) << storm[userInput-1].getLocation();
    cout << setw(12) << cat_type[storm[userInput-1].getCategory()];
    cout << setw(20)<< setprecision(8) << storm[userInput-1].getDamage() << endl;
    cout << "\n";

    cout <<"Enter the new location: ";
//            getline(cin, locationName);
    cin >> locationName;
    storm[userInput-1].setLocation(locationName);

    cout <<"Enter the new ER Rating (0 through 5, -1 for TBD): ";
//            getline(cin, locationName);
    cin >> cat;
    if (cat >= 0 && cat <=5)
    category = static_cast <Category> (cat+1);
    else
        category = TBD;

    storm[userInput-1].setCategory(category);

    cout <<"Enter the new damage: ";
    cin >> editDamage;
    storm[userInput-1].setDamage(editDamage);



}

//Function that updates all damages of the items in the array
int updateDamage(Tornado storm[],int NUM_ITEMS)
{
    double editDamage;

    for (int i = 0; i < NUM_ITEMS; i++)
    {
        cout << "The current damage of " << storm[i].getLocation() << " is: " << storm[i].getDamage();
        cout << "\nEnter the new damage here:";
        cin >> editDamage;
        storm[i].setDamage(editDamage);
        cout <<"\n";
    }

}




