/*
*	@file :Queue.h
*	@author :Lu Yin
*	@date : April 16, 2018
*	@brief A header file for Template Queue class
*/

#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

template <typename T>
class Queue
{
  public:
  //constructor
  Queue();

  //destructor
  ~Queue();

  /** @pre none.
  *   @post none.
  *   @return true is it is empty, otherwise return false.
  */
  bool isEmpty() const;

  /** @pre none.
  *   @post add a new value to the back.
  *   @return none.
  */
  void enqueue(const T value);

  /** @pre none.
  *   @post remove the element at the back.
  *   @return none.
  */
  bool dequeue();

  /** @pre the value is T.
  *   @post remove the element at the front.
  *   @return none.
  */
  T peekFront();

  /** @pre the value is T.
  *   @post print the element at the front.
  *   @return none.
  */
  T PrintFront();


  private:
  Node<T>* q_front;
  int q_length;

};
#include "Queue.hpp"
#endif
