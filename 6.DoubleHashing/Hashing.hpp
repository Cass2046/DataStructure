/*
/ @file: Hashing.hpp
/ @author: Lu Yin
/ @date: March 10, 2018
*/

#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>

using namespace std;

template <typename T>
Hashing<T>::Hashing(int size)
{
    table_size=size;
    table=new List<T> [table_size];
}

template <typename T>
Hashing<T>::~Hashing() //desructor
{
    for (int i=0; i<table_size; i++)
    {
        if (table[i].isEmpty()==false)
        {
            table[i].removeFront();
        }
        
    }
    delete[] table;
}

template <typename T>
int Hashing<T>::Hash(T value) //use %(mod) as the hash func
{
  int m_index_num = value % table_size;
  return m_index_num;
}

template <typename T>
bool Hashing<T>::Find(T value) //whather the value is found before any implementation.
{
    if (table[Hash(value)].isFoundB4Imp(value)==true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
void Hashing<T>::Insert(T value) 
{
    table[Hash(value)].AddFront(value);
}

template <typename T> 
void Hashing<T>::Delete(T value)  //delete a target value
{
    table[Hash(value)].EraseNow(value);
}

template <typename T>
void Hashing<T>::Print() 
{
  for (int i=0; i<table_size; i++)
  {     
    if (table[i].isEmpty() == false)
    {
        cout<<i<<": ";
        table[i].printList();
    }
  }
}
