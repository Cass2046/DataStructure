/**
*	@file : List.h
*	@author : Lu Yin
*	@date : Jan 30, 2018
*   @pre: 
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

    /* remove node at the front*/
    bool removeFront();

    /* Add the node to the front*/
    void AddFront(T value);

    /* Get the length of the list L
    /  helping with isEmpty*/
    int getLength();

    /* Find the target value in the list L
    /  return true if found
    /  return faluse if not found
    */
    bool isFoundB4Imp(T value);

    /*
    /insert x to the hash table when it is not found.(no duplicated value)
    /Insertion must be done at the beginning of the chain.
    */
    Node<T>* insert(Node<T>*m_L, T value);

    /* Insert the value, by calling the resursive function insert(Node<T>*m_L, T value) */
    void InsertNow(T value);

    /*Should return true if L is empty.*/
    bool isEmpty();

     /* Remove x from L if found; else, return message. */
    Node<T>* erase(Node<T>*m_L, T value);

     /* call recursive erase func*/
    void EraseNow(T value);

    /* Print out all the elements of the list separated by a space. */
    void print(Node<T>*m_L);

    /* Help with print*/
    void printList();

    /* Search for x in L and return the pointer pointing at the node containing x.
    /if x not found, return a NULL pointer.
    */
    Node<T>* find(Node<T>*m_L, T value);

    private:
    Node<T>* m_front;  //the head of the list
    int m_length;      //the length of the list

};
#include "List.hpp"
#endif
