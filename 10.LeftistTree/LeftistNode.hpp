/**
*	@file : LeftistNode.hpp
*	@author : Lu Yin
*	@date : April 16, 2018
*/

#include <string>
#include <fstream>
#include <iostream>
#include <limits>
#include <cstddef>

//constructor
template <typename T>
LeftistNode<T>::LeftistNode(T t_value)  
{
  value=t_value;
  leftchild=nullptr;
  rightchild=nullptr;
  rank=1;
}

//destructor
template <typename T>
LeftistNode<T>::~LeftistNode()  
{

}

template <typename T>
void LeftistNode<T>::setValue(T t_value)  
{
  value = t_value;
}


template <typename T>
T LeftistNode<T>::getValue()  
{
  return value;
}

template <typename T>
void LeftistNode<T>::setLeftChild(LeftistNode<T>* t_leftchild) 
{
  leftchild = t_leftchild;
}

template <typename T>
LeftistNode<T>* LeftistNode<T>::getLeftChild()
{
  return leftchild;
}

template <typename T>
void LeftistNode<T>::setRightChild(LeftistNode<T>* t_rightchild) 
{
  rightchild = t_rightchild;
}

template <typename T>
LeftistNode<T>* LeftistNode<T>::getRightChild()
{
  return rightchild;
}

template <typename T>
void LeftistNode<T>::setRank(int t_rank)
{
  rank = t_rank;
}

template <typename T>
T LeftistNode<T>::getRank()
{
  return rank;
}