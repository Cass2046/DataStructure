/*
/ @file: DoubleH.h
/ @author: Lu Yin
/ @date: March 10, 2018
*/

#ifndef DOUBLEH_H
#define DOUBLEH_H
#include "Bucket.h"

template <typename T>
class DoubleH
{
    public:

    DoubleH(int q_m, int q_p, int q_k);

    ~DoubleH();

    /** @pre the value is vaild T. 
    *   @post find a bucket without any collision by double hashing
    *   @return the number of bucket
    */
    int Hash(T value);
   
    /** @pre the value is vaild T. 
    *   @post Search through the hash table.
    *   @return true if the value is found otherwise return false.
    */
    bool Find(T value);

    /** @pre the value is a valid T.
    *   @post One new element the hash table, no duplicated elements
    *   @return true if insert successfully, otherwise return false.
    */
    bool Insert(T value);

    /** @pre the value is exist in the hash table
    *   @post the target element has been reomved from the bucket
    *   @return true if delete successfully, otherwise return false.
    */
    bool Remove(T value); 

    /** @pre the value is a valid T.
    *   @post print the whole element in the hash table
    *   @return none.
    */
    void Print();


    /** @pre the value is a double.
    *   @post load the factor that elements over size of the hash table
    *   @return the factor.
    */
    double loadFactor();

    private:

    Bucket <T>* Dtable;
    int m;
    int k;
    int p;
    int elements;
};
#include "DoubleH.hpp"
#endif