/**
*	@file : List.h
*	@author : Lu Yin
*	@date : Jan 22, 2018
*/

#ifndef LIST_H
#define LIST_H

#include "Node.h"

using namespace std;
template <typename T>
class List
{
    public:
    //constructor
    List();

    //destructor
    ~List();

    /* Get the length of the list L
    /  helping with isEmpty
    */
    int getLength();

    /* Find the target value in the list L
    /  return true if found
    /  return faluse if not found
    */
    bool isFoundB4Imp(T value);

    /*
    Insert x into the list L.
    Insertion should be done at the end of the list.
    */
    void insert(ListL, T value);

    /*Should return true if L is empty.*/
    bool isEmpty();

    /* Remove x from L if found; else, return message. */
    bool erase(ListL, value);

    /* Print out all the elements of the list separated by a space. */
    void print(Node<T>*m_L);

    /* Help with print*/
    void List<T>::printList();

    /* Search for x in L and return the pointer pointing at the node containing x.
    /if x not found, return a NULL pointer.
    */
    Node<T>* find(ListL, T value);


    private:
    Node<T>* m_front;
    int m_length;

};
#include "List.hpp"
#endif
