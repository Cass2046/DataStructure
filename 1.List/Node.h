/**
*	@file : Node.h
*	@author : Lu Yin
*	@date : Jan 22, 2018
*/
#ifndef Node_H
#define Node_H

template <typename T>
class Node
{
  public:
    //constructor
    Node();
    //donstructor
    ~Node();
    
    void setItem(T value);
    T getItem();
    void setNext(Node<T>* n_next);
    Node<T>* getNext();
   
  private:
  T n_value;
  Node<T>* n_next;  //point to the next one

  };
  #include "Node.hpp"
  #endif
