/**
*	@file : BinaryNode.hpp
*	@author : Lu Yin
*	@date : Feb 12, 2018
*	@brief A method file for template BinaryNode class
*/

#include "BinaryNode.h"
#include <string>
#include <cstddef>

using namespace std;

template <typename T>
BinaryNode<T>::BinaryNode()
{
    Item=nullptr;
    leftPtr=nullptr;
    rightPtr=nullptr;
}

template <typename T>
BinaryNode<T>::~BinaryNode()
{
    leftPtr=nullptr;
    rightPtr=nullptr;
}

template <typename T>
BinaryNode<T>::BinaryNode(const T& value)
{
    Item=value;
    leftPtr=nullptr;
    rightPtr=nullptr;

}

template <typename T>
BinaryNode<T>::BinaryNode(const T& value, 
               BinaryNode<T>* leftChildPtr, 
               BinaryNode<T>* rightChildPtr)
{
    Item=value;
    leftPtr=leftChildPtr;
    rightPtr=rightChildPtr;
}

template <typename T>
bool BinaryNode<T>::isLeaf() const
{
    if ((leftPtr == nullptr) && (rightPtr == nullptr))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
void BinaryNode<T>::setItem(const T& value)
{
    Item=value;
}

template <typename T>
T BinaryNode<T>::getItem() const
{
    return Item;
}

template <typename T>
void BinaryNode<T>::setleftPtr(BinaryNode<T>* leftChildPtr)
{
    leftPtr=leftChildPtr;
}

template <typename T>
void BinaryNode<T>::setrightPtr(BinaryNode<T>* rightChildPtr)
{
    rightPtr=rightChildPtr;
}

template <typename T>
BinaryNode<T>*BinaryNode<T>::getleftChildPtr() const
{
    return leftPtr;
}

template <typename T>
BinaryNode<T>*BinaryNode<T>::getrightChildPtr() const
{
    return rightPtr;
}
