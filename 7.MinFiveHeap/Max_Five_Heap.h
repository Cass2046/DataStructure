/**
*	@file : Max_Five_Heap.h
*	@author :Lu Yin
*	@date : March 12, 2018
*	@brief: A header file for Max_Five_Heap class.
*/

#ifndef MAX_FIVE_HEAP_H
#define MAX_FIVE_HEAP_H
#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>
using namespace std;
template <typename T>
class Max_Five_Heap
{
    public:
    Max_Five_Heap(int size);
    Max_Five_Heap(string name, int size);
    ~Max_Five_Heap();

    /** @pre none.
    *   @post build the Max heap using bottom up approach.
    *   @return none.
    */
    void buildheap(); 

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
#include "Max_Five_Heap.hpp"
#endif