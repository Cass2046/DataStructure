/**
*	@file : List.h
*	@author : Lu Yin
*	@date : March 10, 2018
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
    List();
    ~List();

    /** @pre none. 
    *   @post remove node at the front
    *   @return true if it removed, otherwise retrun false.
    */
    bool removeFront();

    /** @pre none. 
    *   @post Add the node to the front
    *   @return none.
    */
    void AddFront(T value);

    /** @pre none. 
    *   @post Get the length of the list L
    *   @return length.
    */
    int getLength();

    /** @pre none. 
    *   @post find the element
    *   @return true if it found, otherwise retrun false
    */
    bool isFoundB4Imp(T value);

    /** @pre vaild node. 
    *   @post insert x to the hash table when it is not found.(no duplicated value)
    *   @return new list of node.
    */
    Node<T>* insert(Node<T>*m_L, T value);

    /** @pre none. 
    *   @post Insert the value, by calling the resursive function insert
    *   @return new node.
    */ 
    void InsertNow(T value);

    /** @pre none. 
    *   @post none.
    *   @return true if L is empty otherwise return false.
    */
    bool isEmpty();

    /** @pre none. 
    *   @post Remove x from L if found; else, return message.
    *   @return the node after erase.
    */
    Node<T>* erase(Node<T>*m_L, T value);

    
    /** @pre none. 
    *   @post call recursive erase func
    *   @return none.
    */
    void EraseNow(T value);

    /** @pre none. 
    *   @post Print out all the elements of the list separated by a space.
    *   @return none.
    */
    void print(Node<T>*m_L);

    /** @pre none. 
    *   @post help with print
    *   @return none
    */
    void printList();

    /** @pre none. 
    *   @post earch for x in L and return the pointer pointing at the node 
    *   @return if found return the node, if x not found, return a NULL pointer.
    */
    Node<T>* find(Node<T>*m_L, T value);

    private:
    Node<T>* m_front;  //the head of the list
    int m_length;      //the length of the list

};
#include "List.hpp"
#endif
