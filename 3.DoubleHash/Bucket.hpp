/*
/ @file: Bucket.hpp
/ @author: Lu Yin
/ @date: Feb 5, 2018
*/

#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>

//constructor
template <typename T>
Bucket<T>::Bucket()  
{
  m_value = -1;
  occupiedB4 = false;
}

//destructor
template <typename T>
Bucket<T>::~Bucket()  
{
  
}

template <typename T>
T Bucket<T>::getValue()  
{
  return m_value;
}

template <typename T>
void Bucket<T>::setValue(T value)  
{
  m_value=value;
}

template <typename T>
bool Bucket<T>::getFlag()  
{
  return occupiedB4;
}

template <typename T>
void Bucket<T>::setFlag(bool occupied)  
{
  occupiedB4 = occupied;
}