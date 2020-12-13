/*
 * Name: Smith Stackhouse
 * Date Submitted: 1/31/2020
 * Lab Section: 003
 * Assignment Name: Lab 1: Linked List Based Stacks and Queues
 */

#pragma once

#include <iostream>
#include <string>
#include "Node.h"
#include "ListStack.h"
#include "ListQueue.h"
using namespace std;

//This class represents a linked list of node objects
//Do not modify anything in the class interface
template <class T>
class List
{

 private:
  Node<T> * start; //pointer to the first node in this list
  int mySize;  //size (or length) of this list

 public:
  List();
  ~List();
  int size();
  bool empty();
  void insertStart(T);
  void insertEnd(T);
  void insertAt(T, int);
  void removeStart();
  void removeEnd();
  void removeAt(int);
  T getFirst();
  T getLast();
  T getAt(int);
  int find(T);

  //Print the name and this list's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name)
  {
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";
    Node<T> * iterator = start;
    while(iterator != nullptr)
    {
      cout << iterator->value << ' ';
      iterator = iterator->next;
    }
    cout << endl;
  }

}; //end of class interface (you may modify the code below)









//Implement all of the functions below
//Construct an empty list by initializig this list's instance variables
template <class T>
List<T>::List()
{
    mySize = 0;
    start = nullptr;
}

//Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List()
{
    while(mySize != 0)
    {
        removeStart();
    }
}

//Return the size of this list
template <class T>
int List<T>::size()
{
    return mySize;
}

//Return true if this list is empty
//Otherwise, return false
template <class T>
bool List<T>::empty()
{
    if(start == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Create a new node with value, and insert that new node
//into this list at start
template <class T>
void List<T>::insertStart(T value)
{
    Node<T> * newNode = new Node<T>(value);

    if(mySize == 0)
    {
      start = newNode;
      newNode->next = nullptr;
    }
    else
    {
      newNode->next = start;
      start = newNode;
    }
    mySize = mySize + 1;
}


//Create a new node with value, and insert that new node
//into this list at end
template <class T>
void List<T>::insertEnd(T value)
{

    Node<T> * newNode = new Node<T>(value);
    Node<T> * tempNode = start;
    if(mySize == 0)
    {
      start = newNode;
    }
    else if(mySize == 1)
    {
      start->next = newNode;
    }
    else
    {
      while(tempNode->next != nullptr)
      {
        tempNode = tempNode->next;
      }
      tempNode->next = newNode;
      newNode->next = nullptr;
    }
    mySize = mySize + 1;
}


//Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j)
{
    Node<T> * newNode = new Node<T>(value);
    Node<T> * iterator = new Node<T>(value);
    iterator = start;
    if(j == 0)
    {
      insertStart(value);
    }
    else
    {
      if(j == 0)
      {
        newNode->next = start;
        start = newNode;
      }
      else
      {
        for(int i = 0; i < j-1; i++)
        {
          iterator = iterator->next;
        }
        newNode->next = iterator->next;
        iterator->next = newNode;
      }
      mySize = mySize + 1;
    }
}



//Remove node at start
//Make no other changes to list
template <class T>
void List<T>::removeStart()
{
    start = start->next;
    mySize = mySize - 1;
}



//Remove node at end
//Make no other changes to list
template <class T>
void List<T>::removeEnd()
{
  Node<T> * iterator = new Node<T>(0);
  iterator = start;
  if(empty() == false)
  {
    if(mySize == 1)
    {
      removeStart();
    }
    else if(mySize == 2)
    {
      start->next = nullptr;
      mySize = mySize - 1;
    }
    else
    {
      for(int i = 0; i < mySize-2; i++)
      {
        iterator = iterator->next;
      }
      iterator->next = nullptr;
      mySize = mySize - 1;
    }
  }
}



//Remove node at position j
//Make no other changes to list
template <class T>
void List<T>::removeAt(int j)
{
  Node<T> * iterator = new Node<T>(0);
  iterator = start;
  int temp = 0;

  if(empty() == false)
  {
    if(j == 0)
    {
      removeStart();
    }
    else if(j == mySize - 1)
    {
      removeEnd();
    }
    else
    {
      while(temp+1 != j)
      {
        iterator = iterator->next;
        temp = temp + 1;
      }
      iterator->next = iterator->next->next;
      mySize = mySize - 1;
    }
  }
}


//Return the value of the first node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst()
{
  if(empty())
  {
    return T();
  }
  else
  {
    return start->value;
  }
}


//Return the value of the last node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast()
{
  Node<T> * iterator = new Node<T>(0);
  iterator = start;
  if(empty())
  {
    return T();
  }
  else
  {
    while(iterator->next != nullptr)
    {
      iterator = iterator->next;
    }
    return iterator->value;
  }
}


//Return the value of the node at position j in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j)
{
  Node<T> * iterator = new Node<T>(0);
  iterator = start;
  int temp = 0;

  if(empty())
  {
    return T();
  }
  else
  {
    if(j == 0)
    {
      return getFirst();
    }
    else if(j == mySize - 1)
    {
      return getLast();
    }
    else
    {
      while(temp != j)
      {
        iterator = iterator->next;
        temp = temp + 1;
      }
      return iterator->value;
    }
  }
}


//Return the position of the (first) node whose value is equal to the key
//Otherwise, return -1
template <class T>
int List<T>::find(T key)
{
  Node<T> * iterator = new Node<T>(0);
  iterator = start;

  for(int i = 0; i < mySize; i++)
  {
    if(iterator->value != key)
    {
      iterator = iterator->next;
    }
    else
    {
      return i;
    }
  }
  return -1;
}
