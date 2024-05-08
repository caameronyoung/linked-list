//Node.h
//Cameron young, 3330431, seng1120 assignment1
//the node.h class holds the declarations of the required methods frmo the node.cpp 
//so that the LinkedList is able to function as intended
#ifndef NODE_H //macroguard
#define NODE_H
#include <iostream>
using namespace std;
#include "Student.h"

class Node
{
	public://pubilc member variables/methods of the node class
		typedef Student value_type;//typedef statement

		Node(); //default constructor
		Node(value_type s);//constructor if and only if data is passed in at the same time the list is created
		~Node();//destructor method

		value_type getData();//method to return the value_type (Student) data to the  node that calls it
		const value_type getData() const; //method to return the data as a constant in case it is used in a method that could potentially change its value

		void setNext(Node* node); //method to change the next pointer in the list
		void setPrev(Node* node); //method to change the prev pointer in the list
		Node* getNext(); //method to return the pointer of the next node
		Node* getPrev(); //method to return the pointer of the previous node

	private://private variables of the node class
		value_type data;
		Node* next;
		Node* prev; 
};

#endif