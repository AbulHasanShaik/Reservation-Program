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


//***************************************************************
// constructor
//Pass in the queue size.
// Create array dynamically to use as the queue.
// Initialize member variables.
//***************************************************************
Reservations::Reservations(int size)
{

	if (size > 0)
	{
		queueArray = new queueNode[size];
		queueSize = size;
	}
	else
	{
		queueArray = nullptr;
		queueSize = 0;
		cout << "Error: Invalid size!\n";
	}

	front = rear = -1;
	numItems = 0;

	return;
}

////**************************************************************
//// Copy constructor                                        *
////**************************************************************
//Reservations::Reservations(const Reservations & obj)
//{
//	//Allocate the queue array.
//	queueArray = new int[obj.queueSize];
//
//	//Copy the other objects attributes.
//	queueSize = obj.front;
//	front = obj.rear;
//	rear = obj.rear;
//	numItems = obj.numItems;
//
//	//Copy the other object's queue array.
//	for(int count = 0; count < obj.queueSize; count++)
//
//}

//**************************************************************
// Destructor                                      *
//**************************************************************
Reservations::~Reservations()
{
	delete[]queueArray;
	queueArray = nullptr;
	queueSize = 0;
	front = rear = -1;
	numItems = 0;
}

//**************************************************************
// enqueue adds to the rear
//and increment wrap before storing
//**************************************************************
bool Reservations::enqueue(string username, int start, int endday)
{
	bool rc;

	if (isFull())
	{
		rc = false;
		cout << "The queue is full try again later\n";
	}
	else
	{
		//% queueSize to wrap back around to the front
		rear = (rear + 1) % queueSize;	//move, with wrap
		queueArray[rear].name = username;
		queueArray[rear].start_day = start;
		queueArray[rear].end_day = endday;
		numItems++;
		rc = true;
	}

	return rc;
}

//**************************************************************
//dequeue removes an item from the front of the queue
// increment before removing
//**************************************************************
bool Reservations::dequeue(string &username, int &start, int& endday)
{
	bool rc;
	if (isEmpty())
	{
		rc = false;
        cout << "Make a reservation before trying to process request\n";
	}
	else
	{
		front = (front + 1) % queueSize;

		username = queueArray[front].name;
		start = queueArray[front].start_day;
		endday = queueArray[front].end_day;
		numItems--;
		rc = true;
	}
	return rc;
}

// isEmpty returns true if the queue is empty, otherwise false.*
bool Reservations::isEmpty() const
{
	bool rc;

	if (numItems == 0)
	{
		rc = true;
	}
	else
	{
		rc = false;
	}

	return rc;
}

// isFull returns true if the queue is full, otherwise false.  *
bool Reservations::isFull() const
{
	bool rc;

	if (numItems == queueSize)
	{
		rc = true;
	}
	else
	{
		rc = false;
	}

	return rc;
}

//Print the Queue
void Reservations::displayQueue() const
{
    int loc = front+1;

    for(int i = 0; i < numItems; i++)
    {
    cout << setw(25)<< queueArray[loc].name;
    cout << setw(25)<< queueArray[loc].start_day;
    cout << setw(25)<< queueArray[loc].end_day;
    loc = (loc +1) % queueSize;

    cout << endl;
    }

    cout << endl;
}
