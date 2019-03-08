/*
/ @file: Bucket.h
/ @author: Lu Yin
/ @date: Feb 5, 2018
*/

#ifndef BUCKET_H
#define BUCKET_H

template <typename T>
class Bucket
{
    public:
    Bucket();
    ~Bucket();

    /** @pre the value is value T.
    *   @post One new element get from the bucket
    *   @return the value.
    */
    T getValue();

    /** @pre the value is a valid T.
    *   @post Set the value to the bucket
    *   @return none.
    */
    void setValue(T value);

    /** @pre the value is bool.
    *   @post none
    *   @return true if the busket is occupied before, otherwise return false.
    */
    bool getFlag();

    /** @pre the value is bool.
    *   @post Set the flag to the bucket
    *   @return none.
    */
    void setFlag(bool occupied);
    

    private:
    T m_value;
    bool occupiedB4;
};
#include "Bucket.hpp"
#endif