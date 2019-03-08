/**
*	@file : MinLeftistHeap.h
*	@author :Lu Yin
*	@date : April 16, 2018
*	@brief: A header file for MinLeftistHeap class.
*/

#ifndef MINLEFTISTHEAP_H
#define MINLEFTISTHEAP_H

#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>

#include "LeftistNode.h"
#include "Queue.h"

using namespace std;

template <typename T>
class MinLeftistHeap
{
    public:
    MinLeftistHeap();
    ~MinLeftistHeap();

    /** @pre none.
    *   @post build the leftist heap by inserting.
    *   @return none.
    */
    void buildheap(string name);

    /** @pre none.
    *   @post insert an element into the Heap using the concate function.
    *   @return none.
    */
    void insert(T m_value);

    /** @pre none.
    *   @post delete the smallest value from the Min leftist Heap and use the concate function to merge the remaining two sub trees.
    *   @return true is delete success, otherwise return false.
    */
    bool deletemin();  

    /** @pre none.
    *   @post print a minimum value from the Min leftist Heap.
    *   @return the minimum element which is the value of its root.
    */
    T findmin();

    /** @pre none.
    *   @post Merge two Min leftist heaps.
    *   @return none.
    */
    LeftistNode<T>* concate(LeftistNode<T>* a, LeftistNode<T>* b);

    /** @pre none.
    *   @post adjust rank.
    *   @return none.
    */
    void adrank(LeftistNode<T>* m_root);
    
    /** @pre none.
    *   @post print out all the elements of the Min leftist Heap using preorder traversal.
    *   @return none.
    */
    void Preorder();
    
    /** @pre none.
    *   @post help with preorder function.
    *   @return none.
    */
    void PreorderHelper(LeftistNode<T>* m_rootPtr);

    /** @pre none.
    *   @post print out all the elements of the Min leftist Heap using inorder traversal.
    *   @return none.
    */
    void Inorder();

    /** @pre none.
    *   @post help with inorder function.
    *   @return none.
    */
    void InorderHelper(LeftistNode<T>* m_rootPtr);

    /** @pre none.
    *   @post print out all the elements of the Min leftist Heap using level order traversal.
    *   @return none.
    */
    void levelorder();

    /** @pre none.
    *   @post help with levelorder function.
    *   @return none.
    */
    void levelorderHelper(LeftistNode<T>* m_rootPtr);

    private:
    LeftistNode<T>* root; 
    
};
#include "MinLeftistHeap.hpp"
#endif
