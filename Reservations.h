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
#ifndef RESERVATIONS_H
#define RESERVATIONS_H
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Reservations
{
private:

    struct queueNode
    {
        string name;    //Name of the user
        int start_day;  //Start date
        int end_day;    //Number of days
    };

    queueNode *queueArray;
    int queueSize;
    int front;
    int rear;
    int numItems;



public:

	//Constructor
	Reservations(int);

	////Copy Constructor
	//Reservations(const Reservations&);

	//Destructor
	~Reservations();

	//Queue Operations
	bool enqueue(string, int, int );
	bool dequeue(string &, int &, int &);
	bool isEmpty() const;
	bool isFull() const;
    void displayQueue() const;     //displayQueue
	void clear();

};
#endif // RESERVATIONS_H
