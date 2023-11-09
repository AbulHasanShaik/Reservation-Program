/*
Name: Abul Hasan Shaik
Course: CSC 300 (Data Structures)
Assignment: Program 3
Date: 02/13/2023
Class Overview:  The class name is Reservstion and as its private members it has 3 variables with  data types (string, int, int)
to read the name, start date and number of days from the user. As public members there is one  constructor and destructor.
 There are 6 public member functions which are:
enqueue: This function inserts a value at the rear of the queue, dequeue: It removes the data at the front of the queue,
isFull: isFull returns true if the queue is full otherwise false , isEmpty: It returns true if the queue is empty, other wise false
, displayQueue: This function prints the items in the queue which is waiting to be processed,
and clear: clears sets the front and rear indicates  and sets numItems to 0.
*/
#include <iostream>
#include <iomanip>
#include <string>
#include "Reservations.h"

using namespace std;

const int SIZE = 5;
const int MAX_VALUES = 31;  //  number of days in December

//Declaring enumerated data type for the Menu.
enum MENU{ADD = 1, PROCESS = 2, DISPLAYQ = 3, DECEMBER = 4, EXIT = 5};

//Declaring enumerated data type for the Status of the reservation.
enum STATUS {AVAILABLE, BOOKED, NOTAVAILABLE};
const int NUM_STATUS = 3;
const string cat_type[NUM_STATUS] = {"AVAILABLE","BOOKED","NOT AVAILABLE"};

struct monthDays
{
    string personName;
    STATUS Status;
};

//Function Prototypes
int printMenu();
void addRequest(Reservations &items, monthDays array[]);
void processRequest(Reservations &items, monthDays array[]);
void printQueue(Reservations &items, monthDays array[]);
void printrentalStatus(Reservations &items, monthDays array[]);

int main()
{
    int userInput;
    Reservations items(MAX_VALUES);
    monthDays  vacation[MAX_VALUES] = {"", AVAILABLE};

    // Rentals NOT AVAILABLE form 23rd to 27th because the owner wants to use them.
    for(int i = 22; i <=26; i++)
    {
        vacation[i].Status = NOTAVAILABLE;
        vacation[i].personName = "Owner";
    }

    do {

        userInput = printMenu();

        if (userInput == ADD) //Get the info from the user
        {
            addRequest(items, vacation);
        }

        else if (userInput == PROCESS) //Check if the requested reservation can be designated or not.
        {
            processRequest(items, vacation);
        }

        else if (userInput == DISPLAYQ) //Prints the items in the queue waiting to be processed.
        {
            printQueue(items, vacation);
        }
        else if (userInput == DECEMBER) //Print the Calender of the month December and the reservation status with names
        {
            printrentalStatus(items, vacation);
        }

    } while (userInput != EXIT);


    return 0;
}


//This function prints the menu.
int printMenu()
{
    int selectChoice;
    cout << endl;

    // ...<present the user with a menu>...
    cout << "Press 1 " << left << "To add a request." << endl;
    cout << "Press 2 " << left << "To process the next request." << endl;
    cout << "Press 3 " << left << "To print the queue." << endl;
    cout << "Press 4 " << left << "To print the rental's status for the days in the month." << endl;
    cout << "Press 5 " << left << "To EXIT the program." << endl;
    cout << "\nEnter the option you would like to choose: ";
    cin >> selectChoice;
        if(selectChoice < 1 || selectChoice > 5)
        {
            cout << "Invalid Input!!" << endl;
        }

    cin.ignore();

    cout << "\n";

    return selectChoice;
}

//This function read the name, start day, and end day from the user, it validates start day and end day to make sure that they stay with the range 1 to 31.
//If the queue is full, it prints a message to the user telling them to “Try again later”
void addRequest(Reservations &items, monthDays array[])
{
    string usersName;
    int startDay;
    int endDays;

    cout << "Enter the name here: ";
    getline(cin, usersName);
    cout << endl;

    cout << "Enter the start day here(1-31): ";
    cin >> startDay;
        if(startDay < 1 || startDay > 31)
        {
            cout << "Invalid Input!!" << endl;
        }
    cout << endl;

    cout << "Enter the number of days here(1-31): ";
    cin >> endDays;
        if(endDays < 1 || endDays > 31)
        {
            cout << "Invalid Input!!" << endl;
        }

    cin.ignore();
    cout << endl;

    items.enqueue(usersName, startDay, endDays);

    return;

}
// This function removes an item from the queue, update the status of the days requested if the entire timespan requested is available by marking the status as booked and copying the name into the name field for the array of structures.
//Then, prints a message saying whether the reservation was accepted or denied.  If denied, display which days requested were not available.
void processRequest(Reservations &items, monthDays array[])
{
    string usersName;
    int startDay;
    int endDays;
    STATUS Status;
    bool flag;

    cout << "Processing the next request...\n";

    items.dequeue(usersName, startDay, endDays);


    flag = true;
    for (int i = startDay; i <= (endDays+startDay); i++)    //Adding the start date and the number of days
    {
        if (array[i].Status != AVAILABLE)
        {
            flag = false;
            cout << "Day " << i << " is not available.\n";
        }
    }

    if (flag)
    {
        cout << "Reservation accepted.\n";
        for (int i = startDay; i <= (endDays+startDay); i++)     //Adding the start date and the number of days
        {
            array[i-1].Status = BOOKED;
            array[i-1].personName = usersName;
        }
    }
    else
    {
        cout << "Reservation denied.\n";
    }



    return;
}

//This function prints the reservation requests with the name, start date and the number of days.
void printQueue(Reservations &items, monthDays array[])
{
    cout << setw(20) << "Name:"
    <<setw(20)<< "Start Date: "
    << setw(20) << "Number of days: " << endl;
    cout << left << "---------------------------------------------------------------------" << endl;
    items.displayQueue();   //Calling the displayQueue function

    return;
}

//This function prints the rental’s status for the days in the month and displays the Name of the person who booked it.
void printrentalStatus(Reservations &items, monthDays array[])
{
    cout << setw(15) << "Date: "
    << setw(20) << "Name:"
    << setw(20) << "Reservation Status: \n";
    cout << left << "---------------------------------------------------------------------" << endl;

   for(int i = 0; i < MAX_VALUES; i++)
    {
        cout<< setw(25) << i+1;
        cout << setw(25) << array[i].personName  << cat_type[array[i].Status]  << endl;

    }

    return;
}
