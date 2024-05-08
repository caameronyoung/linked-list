//LinkedList.h
//cameron young; c3330431; seng1120 assignment
//LinkedList.h is made to store the class definitions of the LinkedList.cpp for functionality where required

#ifndef LINKEDLIST_H //macro guard
#define LINKEDLIST_H
#include <iostream>
#include "Student.h"
#include "Node.h"
using namespace std;

class LinkedList //defines the class LinkedList
{
	public: //the public members and methods of the LinkedList class
		typedef Node::value_type value_type; //typedef statement

		LinkedList(); //default constructor
		~LinkedList(); //destructor

		Node* getCurrent(); //returns the pointer for the current node being accessed

		void addToHead(value_type s); //sets the head node to have the data in the 'node' parameter
		Node* getHead(); //returns the pointer for the head node
		void removeFromHead(); //removes the data from the head node
		void addToTail(value_type s); //sets the tail node to have the data in the 'node' parameter
		Node* getTail(); //returns the pointer for the tail node
		void removeFromTail(); //removes the data from the tail node 

		int count(string name); //counts the amount of people with the same name in the LinkedList

		int getLength(); //method to return the length of the list as the number of nodes 
		void remove(string name); //method to remove the node that stores this name. 

		//overloading
		void operator += (LinkedList& listTwo);//overloads the += operator to concatenate two lists together. 
		void operator -= (LinkedList& listTwo); //overloads the -= operator to remove elements from a combined list. 

	private: //the private members of the LinkedList class.
		Node* head; //this pointer directs the program to the head Node of the list
		Node* tail; //this pointer directs the program to the tail node of the list 
		Node* current; //this pointer directs the program to the current node of the list, which is not necessarily the head or tail
		int length;
};

std::ostream& operator <<(ostream& out, LinkedList& list); //the method to overload the << operator to print lists

#endif
