/**
*	@file : Node.h
*	@author : Lu Yin
*	@date : April 16, 2018
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
    
    /** @pre the value is T.
    *   @post set value.
    *   @return none.
    */
    void setItem(T value);

    /** @pre the value is T.
    *   @post none.
    *   @return the value of element.
    */
    T getItem();

    /** @pre the value is T.
    *   @post set value to the next node.
    *   @return none.
    */
    void setNext(Node<T>* n_next);

    /** @pre the value is T.
    *   @post none.
    *   @return the value of the next element.
    */
    Node<T>* getNext();
   
    private:
    T n_value;
    Node<T>* n_next;  //point to the next one

  };
  #include "Node.hpp"
  #endif
