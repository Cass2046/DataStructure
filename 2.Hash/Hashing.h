/*
/ @file: Hashing.h
/ @author: Lu Yin
/ @date: Jan 30, 2018
*/

#ifndef HASHING_H
#define HASHING_H

template <typename T>
class Hashing
{
    public:

    //constructor
    Hashing(int size);
    //desructor
    ~Hashing();

    /**  @post None.
    *   @return the number of bucket
    */
    int Hash(T value);
   
    /**  @post None.
    *   @return true if the value is found, false otherwise.
    */
    bool Find(T value);

    /** @pre the value is a valid T.
    *   @post One new element added to the front of the bucket
    *   @return none.
    */
    void Insert(T value);

    /** @pre the value is a valid T.
    *   @post the target element has been reomved from the bucket
    *   @return none.
    */
    void Delete(T value); 

   /** @pre the value is a valid T.
    *   @post print the whole element in the hash table
    *   @return none.
    */
    void Print();

    private:
    List <T>* table;
    int table_size;
};
#include "Hashing.hpp"
#endif