/**
*	@file : MaxMinHeap.h
*	@author :Lu Yin
*	@date : March 30, 2018
*	@brief: A header file for MaxMinHeap class.
*/

#ifndef MaxMinHeap_H
#define MaxMinHeap_H
#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>
using namespace std;

template <typename T>
class MaxMinHeap
{
    public:
    MaxMinHeap(int size);
    MaxMinHeap(string name, int size);
    ~MaxMinHeap();

    // /** @pre the index of the element.
    // *   @post none.
    // *   @return true if it is min level, otherwise return false.
    // */
    bool isMinlevel(int index);

    /** @pre none.
    *   @post find the maximum element in the subtree.
    *   @return the index of the maximum element.
    */
    int getMaxchild(int index);

    /** @pre the none.
    *   @post find the maximum element in the subtree.
    *   @return the index of the minimum element.
    */
    int getMinchild(int index);

    /** @pre none.
    *   @post build the MaxMin heap by inserting elements into an initially empty heap.
    *   @return none.
    */
    void buildheap(); 

    /** @pre none.
    *   @post help with buildheap with swap in max and min level.
    *   @return none.
    */
    void helpbuild(int root);

    /** @pre none.
    *   @post insert an element into the Max 5-Heap.
    *   @return none.
    */
    void insert(T value);

    /** @pre none.
    *   @post insert x into the Max 5-Heap.
    *   @return none.
    */
    bool deletemin();

    /** @pre none.
    *   @post print a minimum value from the Max 5-Heap.
    *   @return true if found.
    */
    T findmin();

    /** @pre none.
    *   @post print a maximum value from the Max 5-Heap.
    *   @return none.
    */
    T findmax();

    /** @pre none.
    *   @post delete the maximum value from the Max 5-Heap.
    *   @return none.
    */
    bool deletemax();

    /** @pre none.
    *   @post  - should print out all the elements of the Max 5-Heap using level order traversal.
    *   @return none.
    */
    void levelorder();

    private:
    int max_size;
    T* max_a; //array
    int max_Item; //how many items now
        
};
#include "MaxMinHeap.hpp"
#endif