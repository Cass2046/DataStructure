/**
*	@file :Node.hpp
*	@author :Lu Yin
*	@date : Jan 22, 2018
*/

#include <string>
#include <fstream>
#include <iostream>
#include <limits>
#include <cstddef>

//constructor
template <typename T>
Node<T>::Node()  
{
  n_next=nullptr;
}

//destructor
template <typename T>
Node<T>::~Node()  
{

}

// get and set Methods
template <typename T>
void Node<T>::setItem(T value)
{
  n_value = value;
}

template <typename T>
T Node<T>::getItem()
{
  return n_value;
}

template <typename T>
void Node<T>::setNext(Node<T>* next)
{
  n_next = next;
}

template <typename T>
Node<T>* Node<T>::getNext()
{
  return n_next;
}



