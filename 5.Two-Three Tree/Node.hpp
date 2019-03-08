/**
*	@file : Node.hpp
*	@author : Lu Yin
*	@date : Feb 19, 2018
*	@brief A method file for template Node class
*/

#include "Node.h"
#include <string>
#include <cstddef>

using namespace std;

template <typename T>
Node<T>::Node(bool tag, int minSecond, int minThird)  //interior
{
  tag_leaf=tag;
  m_minSecond=minSecond;
  m_minThird=minThird;
}

template <typename T>
Node<T>::Node(bool tag, int item)  //leaf
{
 tag_leaf=tag;
 key=item;
}

template <typename T>
Node<T>::Node() //constructor
{
  tag_leaf=true;
  key=-1;
  first=nullptr;
  second=nullptr;
  third=nullptr;
  interior_parent=nullptr;
  m_minSecond=-1;
  m_minThird=-1;
}

template <typename T>
Node<T>::~Node() //destructor
{

}

template <typename T>
void Node<T>::setTag(bool tag)
{
  if (tag==true)
  {
    tag_leaf=true;
  }
  else
  {
    tag_leaf=false;
  }
}

template <typename T>
bool Node<T>::getTag()
{
  return tag_leaf;
}

template <typename T>
void Node<T>::setItem(int value)
{
  key=value;
}

template <typename T>
T Node<T>::getItem()
{
  return key;
}

template <typename T>
void Node<T>::setminSecond(T minSecond)
{
   m_minSecond = minSecond;
}

template <typename T>
T Node<T>::getminSecond()
{
  return m_minSecond;
}

template <typename T>
void Node<T>::setminThird(T minThird)
{
  m_minThird = minThird;
}

template <typename T>
T Node<T>::getminThird()
{
  return m_minThird;
}

template <typename T>
void Node<T>::setparent(Node<T>* parent)
{
  interior_parent=parent;
}

template <typename T>
Node<T>* Node<T>::getparent()
{
  return interior_parent;
}

template <typename T>
void Node<T>::setfirstChild(Node<T>* firstChild)
{
  first=firstChild;
  if(first!=nullptr)
  {
    first->setparent(this);
  }
}

template <typename T>
Node<T>* Node<T>::getfirstChild()
{
  return first;
}

template <typename T>
void Node<T>::setsecondChild(Node<T>* secondChild)
{
  second=secondChild;
  if(second!=nullptr)
  {
    second->setparent(this);
  }
}

template <typename T>
Node<T>* Node<T>::getsecondChild()
{
  return second;
}

template <typename T>
void Node<T>::setthirdChild(Node<T>* thirdChild)
{
  third=thirdChild;
  if (thirdChild == nullptr)
  {
    m_minThird=-1;
  }
  else
  {
    third->setparent(this);
  }
}

template <typename T>
Node<T>* Node<T>::getthirdChild()
{
  return third;
}

