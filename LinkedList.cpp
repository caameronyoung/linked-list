//LinkedList.cpp
//cameron youngg, c330431, seng1120 
//this file stores the methods for the declared methods in the .h
#include "LinkedList.h"
#include "Node.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//post-condition: none
//pre-condition: the default attributes of the LInkedList are createed
LinkedList::LinkedList() //the default constructor for the LinkeddList class
{
	this->head = NULL;
	this->tail = NULL;
	this->current = head;
	this->length = 0;
}

//pre-condition: the destructor for the linkedlist class is called
//post-condition: the data in the linkedlist is removed. IE: all the data is removed from existing nodes 
LinkedList::~LinkedList() 
{
	while (head != NULL) //ie; while there is still something in the LinkedList
	{
		removeFromHead();
	}
}

//pre-condition: the program looks for the current node
//post-condition: the program returns the pointer for the current node
Node* LinkedList::getCurrent()
{
	return this->current;
}

//pre-condition: there is need to add something to the head of the node. Assumes the data passed in is correct
//post-condition: a new node is created that holds the passed in data and this node is pointed to by the head pointer. 
void LinkedList::addToHead(value_type s)
{
	if (head == NULL)
	{
		Node* node = new Node(s);
		head=node;
		tail = node;//0 nodes so the tail and head are equivalent.
		length += 1;
	}

	else //much harder to move pointers around if the head already points to a non-null value 
	{
		Node* node = new Node(s); //creates a new node to become the head
		head->setPrev(node); // sets the initial head's previous pointer to be that of the new node (as it is becoming the 2nd one in the list )
		node->setNext(head); //sets the new node's next pointer to be the initial head (now the 2nd node in the list)
		head=node; //sets the head pointer to point to the new node
		length += 1;
	}

}

//pre-condition: the program tries to find the pointer for the head node
//post-condition: the program retursn the pointer for the head node
Node* LinkedList::getHead()
{
	return this->head;
}

//pre-condition: the linkedlist tries to remove an object from the head
//post-condition: the head node is removed, and the current head's next node becomes the head.
void LinkedList::removeFromHead()
{
	Node* temp = new Node();
	temp = head; //stores the current head data and all its pointers
	head = head->getNext(); //the current head node just become the next node, because, if the head gets removed, the next one becomes the head 
	if (head != NULL) //assumes the new head node still has data in it, meaning there will be a previous pointer that points outside the list 
	{ 
		head->setPrev(NULL); //sets the head's previous pointer to be non-existant.
	}
	this->length -= 1;
	delete temp; //removes the data stored in temp, which was head's data
}


//pre-condition: the LinkedList tries to add a node to the tail end of the list
//post-condition: a new node is added to the end of the list - and - the pointers are adjusted accordingly
void LinkedList::addToTail(value_type s)
{
	if (getLength() > 0) //the list must have elements in it, otherwise you are really adding something to the head of the list 
	{
		Node* node = new Node(s); //what will become the tail node
		tail->setNext(node); //changes the pointer of tail to be the newly created node. 
		node->setPrev(tail); //sets the new tail's previous pointer to point at the old tail
		tail=node; //points the tail to the new node 
		length += 1;
	}
	else //note: this is much simpler as there are no pointers to adjust as there are NO elements in the list yet (list's length is 0)
	{
		Node* node = new Node(s); //a new node is created to store what will become the tail node
		tail=node; //the tail pointer now points to the new node
		head=tail; //the head pointer now points to the new node
		length += 1;
	}
}

//pre-condition: the program searches for the pointer to the tail of the node
//post-condition: the program returns the pointer of the tail node to the program
Node* LinkedList::getTail()
{
	return this->tail;
}

//pre-condition: the program tries to remove the tail-node at end of the list
//post-condition: the tail is removed and the current tail's prev node becomes the tail.
void LinkedList::removeFromTail()
{
	Node* temp = tail; //stores the current data in the tail
	tail = tail->getPrev(); //the current tail node becomes the previous node, because, if the tail is rmemoved, the previous node becomes the tail 
	if (tail != NULL) //assumes the new tail still has data in it, meaning there will be a next pointer that points outside the list 
	{
		tail->setNext(NULL); //sets the tail's next pointer to be non-existant 
	}
	this->length -= 1;
	delete temp; //removes the data stored in temp, which was the initial tail's data. 
}

//pre-condition: the user searches the list for the amount of student's with the same name
//post-condition: a counter is returned that holds number of students with the same name.
int LinkedList::count(string name)
{
	int count = 0; //a dummy counter is initialised (dummy because it has no use outside this method)
	for (Node* current = head; current != NULL; current = current->getNext()) //spans across the entire list until the next node is a null
	{
		if ((current->getData().get_name()) == name) //if the returned name inside the node is the same as the passed in parameter
		{
			count += 1;
		}
	}
	return count;
}	

//pre-condition: the user wants to see the amount of nodes in the list
//post-condition: the number of nodes in the list is returned 
int LinkedList::getLength()
{
	return this->length;
}

//pre-condition: the user wants to remove a specific student from their LinkedList
//post-condition: the student is removed and pointers are adjusted accordingly 
void LinkedList::remove(string name) 
{
	for (Node* current = head; current != NULL; current = current->getNext()) //spans across all the existing nodes
	{

		if ((current->getData().get_name()) == name) //if the student to remove has the same name as the current student's name 
		{
			if (head == tail) //for the case where there is only one node in the entire list
			{
				head = NULL; //removes the pointer for the head (as the only node that exists is being removed)
				tail = NULL; //removes the pointer for the tail (as the only node that exists is being removed)
				delete current; //deletes the current pointer and node 
				length -= 1; 
				break;
			}

			else if (current == head) //if the name to remove is at the front of the list
			{
				current = current->getNext(); //sets the current pointer to point to the next node
				current->setPrev(NULL); //removes the previous node's pointer because the head has just been removed.. leaving it in would make a null ptr exception
				delete head; //removes the memory allocated to the initial head
				head = current; //head now points to the 2nd node in the list 
			}

			else if (current == tail) //for the case where the student is at the end of the list 
			{
				current = current->getPrev(); //sets the current node to be the 2nd last node in the list 
				current->setNext(NULL); //makes the next node (the tail) null
				delete tail; //deallocates the memory stored in tail
				tail = current; //sets the tail pointer to point to the second last node in the list (the new tail)
				length -= 1; 
				break;
			}
			else //for a case where the name is in the middle of the list
			{
				Node* temp = current; //stores the data and pointers in temp
				Node* tempPrev = current->getPrev(); //creates a temp node that stores the previous pointer of the node that is about to be deleted
				Node* tempNext = current->getNext(); //creates a temp node that stores the next pointer of the node that is about to be deleted 
				tempNext->setPrev(tempPrev);  //points the next node's previous pointer to be the temporary previous node
				tempPrev->setNext(tempNext); //points the previous node's next pointer to be the temporary next node 
				delete temp;
				current = tempNext;
			}
			length -= 1;
		}
	}
}

//pre-condition: two lists must exist
//post-condition: the second list (the one passed in) is concatenated to the tail-end of the first list 
void LinkedList::operator += (LinkedList& listTwo)
{
	for (Node* current = listTwo.getHead(); current != NULL; current = current->getNext()) //spans the entire second list from head to tail
	{
		value_type info = current->getData(); //returns a unique student each time the loop runs
		this->addToTail(info);
		//this->tail.addToTail(current); //adds the current node in the second list to the tail of the first list
		length += 1; //increases the length of the list by one. 
	}
}

//pre-condition: one list must have alread been added to another
//post-condition: the second list is removed from the tail of the first
void LinkedList::operator -= (LinkedList& listTwo)
{
	for (Node* current = listTwo.getHead(); current != NULL; current = current->getNext()) //spans the entire second list from head to tail
	{
		this->removeFromTail();
		//this->tail.removeFromTail(current); //removes the last node from the linked list until all of the second list has been removed.
		length -= 1; //decreases the length of the list by one
	}
}

std::ostream& operator <<(ostream& out, LinkedList& list)
{
	for (Node* current = list.getHead(); current != NULL; current = current->getNext()) //list.getCurrent()->getNext()
    {
		out << current->getData();//<< endl;
    }
	return out;
}







