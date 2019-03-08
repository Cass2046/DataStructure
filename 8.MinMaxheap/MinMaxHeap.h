/**
*	@file : MinMaxHeap.h
*	@author :Lu Yin
*	@date : March 31, 2018
*	@brief: A header file for MinMaxHeap class.
*/

#ifndef MINMAXHEAP_H
#define MINMAXHEAP_H

#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>

using namespace std;

template <typename T>
class MinMaxHeap
{
    public:
    MinMaxHeap(int size);
    MinMaxHeap(string name, int size);
    ~MinMaxHeap();

    /** @pre the index of the element.
    *   @post none.
    *   @return true if it is min level, otherwise return false.
    */
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
    *   @post build the Min Man heap by inserting elements into an initially empty heap.
    *   @return none.
    */
    void buildheap();

    /** @pre none.
    *   @post help with buildheap with swap in max and min level.
    *   @return none.
    */
    void helpbuild(int root);

    /** @pre none.
    *   @post insert an element into the Min 5-Heap.
    *   @return none.
    */
    void insert(T value);

    /** @pre none.
    *   @post delete the smallest value from the Min 5-Heap.
    *   @return none.
    */
    bool deletemin();  

    /** @pre none.
    *   @post print a minimum value from the Min 5-Heap.
    *   @return the minimum element.
    */
    T findmin();

    /** @pre none.
    *   @post print a maximum value from the Min 5-Heap.
    *   @return the maximum element.
    */
    T findmax();
    
    /** @pre none.
    *   @post delete the maximum value from the Min 5-Heap.
    *   @return none.
    */
    bool deletemax();

    /** @pre none.
    *   @post  - should print out all the elements of the Min 5-Heap using level order traversal.
    *   @return none.
    */
    void levelorder();

    private:
    int min_size;
    T* min_a;  //array
    int min_Item;

};
#include "MinMaxHeap.hpp"
#endif
