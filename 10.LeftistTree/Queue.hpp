/*
*	@file :Queue.hpp
*	@author :Lu Yin
*	@date : April 16, 2018
*	@brief Run methods for StarTrekShip class
*/
#include "Queue.h"
#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>

template <typename T>
Queue<T>::Queue()   //An empty list is created.
{
  q_front=nullptr;    //null pointer
  q_length=0;         //initilize a length
}

template <typename T>
Queue<T>::~Queue()
{
  while (q_front!=nullptr)
  {
    dequeue();
  }
}

template <typename T>
bool Queue<T>::isEmpty() const
{
  //returns true if the stack is empty, false otherwise
	if (q_front == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Entry added to back of queue, throws exception should enqueue fail
// Note: The interface allows for an exception to be thrown, 
// but doesn't obligate an implementation
// like LinkedList's add back
template <typename T>
void Queue<T>::enqueue(const T value)
{
    Node<T>*cur = q_front;
    Node<T>*temp = cur;
    Node<T>*n = new Node<T> ();

    //empty list
    if(q_length == 0)
    {
      n->setItem(value);
      q_front = n;
      q_length++;
      temp=nullptr;
      cur=nullptr;
    }
    else //if (q_length !=0)
    {
      while(cur != nullptr)
      {
        temp=cur;
        cur=cur->getNext();   //point to the next node
      }
      temp->setNext(n);
      n->setItem(value);
      q_length++;
      temp=nullptr;
      cur=nullptr;
    }  
}

// assumes the queue is not empty, front of the front is removed
// throws PreconditionViolationException if attempted on an empty queue. 
// Does not return a value in this case.
// like LinkedList's remove front
template <typename T>
bool Queue<T>::dequeue()
{
  Node<T>* cur=q_front;
  if (q_front != nullptr)  //empty list
  {
    q_front=q_front->getNext();
    delete cur;    //delete value
    cur=nullptr;   //delete pointer
    q_length--;
    return true;
  }
  else
  {
    return false;
  }
}

// assumes the queue is not empty, returns the value at the front of the queue
template <typename T>
T Queue<T>::peekFront()
{
  T front;
  Node<T>*p=q_front; //find the front
  if (p!=nullptr)
  {
    front=p->getItem();
    dequeue();
    return front;
  }
  else
  {
    return nullptr;
  }
}

template <typename T>
T Queue<T>::PrintFront()
{
  if (q_front!=nullptr)
  {
    return q_front->getItem();
  }
  else
  {
    return nullptr;
  }
}