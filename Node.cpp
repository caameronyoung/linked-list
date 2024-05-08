//Node.cpp
//Cameron young, 3330431, seng1120 assignment one
//this file is made to store the methods of the node class
#include "Node.h"


//pre-condition: a node is created with no data passed into it (ie, the default constructor)
//post-condition: a new node is created with default values. 
Node::Node()
{
	Node* next = NULL;
	Node* prev = NULL;
}

//pre-condition: a LinkedList passes in data for a node (ie, not the default constructor)
//post-condition: a new node is created that stores the data given
Node::Node(value_type s)//nodes exist to store the data in an ordered format
{
	this->data = s; //stores the value_type (Student) in a variable called data
	Node* next = NULL; //creates the pointer to the next node, null because nothing has been initialised yet
	Node* prev = NULL; //creates the pointer to the previous node, null because nothing has been initialised yet.
}

//pre-condition: the destructor is called
//post-condition: the data in the node is created to be null so that pointers arent de-referenced, but the data still turns nulled
Node::~Node() {}

//pre-condition: the node tries to return the data
//post-condition: the data this node stores is returned
Node::value_type Node::getData() //value_type means this returns a student - as Student IS the data type being stored in the Node/s
{
	return this->data;
}

const Node::value_type Node::getData() const
{
	return this->data;
}

//pre-condition: the program tries to set the pointer for the next node
//post-condition: the program sets the pointer for the next node
void Node::setNext(Node* node)
{
	this->next = node;
}

//pre-condition: the program tries to set the pointer for the previous node
//post-condition: the program sets the pointer for the previous node
void Node::setPrev(Node* node)
{
	this->prev = node;
}

//pre-condition: the program looks for the pointer to the next node in the LinkedList
//post-condition: the program returns the pointer
Node* Node::getNext()
{
	return this->next;
}

//pre-condition: the program looks for the pointer to the prev node in the LinkedList
//post-condition: the program returns the pointer
Node* Node::getPrev()
{
	return this->prev;
}


