/**
*	@file : MinSkewHeap.h
*	@author :Lu Yin
*	@date : April 16, 2018
*	@brief: A header file for MinSkewHeap class.
*/

#ifndef MINSKEWHEAP_H
#define MINSKEWHEAP_H

#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>

#include "SkewNode.h"
#include "Queue.h"
using namespace std;

template <typename T>
class MinSkewHeap
{
    public:
    MinSkewHeap();
    ~MinSkewHeap();

    /** @pre none.
    *   @post build the Min Skew heap by inserting elements into an initially empty heap.
    *   @return none.
    */
    void buildheap(string name);

    /** @pre none.
    *   @post insert an element into the Heap.
    *   @return none.
    */
    void insert(T s_value);

    /** @pre none.
    *   @post delete the smallest value from the Heap.
    *   @return none.
    */
    bool deletemin();  

    /** @pre none.
    *   @post print a minimum value from the Min Heap.
    *   @return the minimum element.
    */
    T findmin();

    /** @pre none.
    *   @post Merge two Min skew heaps.
    *   @return none.
    */
    SkewNode<T>* concate(SkewNode<T>* a, SkewNode<T>* b);

     /** @pre none.
    *   @post print out all the elements of the Heap using preorder traversal.
    *   @return none.
    */
    void Preorder();
    
    /** @pre none.
    *   @post help with preorder function.
    *   @return none.
    */
    void PreorderHelper(SkewNode<T>* m_rootPtr);
    
    /** @pre none.
    *   @post print out all the elements of the Heap using inorder traversal.
    *   @return none.
    */
    void Inorder();

    /** @pre none.
    *   @post help with inorder function.
    *   @return none.
    */
    void InorderHelper(SkewNode<T>* m_rootPtr);

    /** @pre none.
    *   @post print out all the elements of the Heap using level order traversal.
    *   @return none.
    */
    void levelorder();

    /** @pre none.
    *   @post help with levelorder function.
    *   @return none.
    */
    void levelorderHelper(SkewNode<T>* m_rootPtr);

    private:
    SkewNode<T>* root;

};
#include "MinSkewHeap.hpp"
#endif
