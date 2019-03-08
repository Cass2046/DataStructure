/**
*	@file : Min_Five_Heap.h
*	@author :Lu Yin
*	@date : April 8, 2018
*	@brief: A header file for Min_Five_Heap class.
*/

#ifndef MIN_FIVE_HEAP_H
#define MIN_FIVE_HEAP_H

#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>

using namespace std;

template <typename T>
class Min_Five_Heap
{
    public:
    Min_Five_Heap(int size);
    Min_Five_Heap(string name, int size);
    ~Min_Five_Heap();

    /** @pre none.
    *   @post build the Min heap using bottom up approach.
    *   @return none.
    */
    void buildheap();

    /** @pre none.
    *   @post insert an element into the Min 5-Heap.
    *   @return none.
    */
    void insert(T value);
    /** @pre none.
    *   @post insert an element into the Min 5-Heap.
    *   @return none.
    */
    void insertNoBuild(T value);

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
#include "Min_Five_Heap.hpp"
#endif
