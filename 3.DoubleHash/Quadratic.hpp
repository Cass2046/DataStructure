/*
/ @file: Quadratic.hpp
/ @author: Lu Yin
/ @date: Feb 5, 2018
*/

#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>

#include "Bucket.h"

using namespace std;

template <typename T>
Quadratic<T>::Quadratic()
{
    // m=11;
    // k=4;
    m=53;
    k=10;
    
    elements=0;
    Qtable = new Bucket<T> [m];
}

template <typename T>
Quadratic<T>::~Quadratic() //desructor
{
    delete[] Qtable;
}

template <typename T>
int Quadratic<T>::Hash(T value)
{
    int bucket;
    int x;
    bucket = value % m;
    for (int i=0; i<k; i++)
    {
        x = (bucket + i*i) % m;
        if (Qtable[x].getValue() == -1)
        {
            return x;
        }
    }
    return -1;
}

template <typename T>
bool Quadratic<T>::Find(T value) //whather the value is found before any implementation.
{
    bool isFound = false;
    for (int i=0; i<m; i++)
    {
        if (Qtable[i].getValue()==value)
        {
            isFound = true;
        }
    }
    return isFound;

}

template <typename T>
bool Quadratic<T>::Insert(T value)
{
    if (Find(value) == false)
    {
        if (Qtable[Hash(value)].getValue()==-1) //the bucket is empty
        {  
            Qtable[Hash(value)].setValue(value);
            elements++;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }

    // if (Hash(value)!=-1)
    // {
    //     Qtable[Hash(value)].setValue(value);
    //         elements++;
    //         return true;
    // }
    // else
    // {
    //     return false;
    // }

    
}

template <typename T> 
bool Quadratic<T>::Remove(T value)  //delete a target value
{
    int x;
    int bucket;
    bucket = value % m;
    for (int i=0; i<=k; i++)
    {
        x = (bucket + i*i) % m;
        if (Qtable[x].getValue() != value)
        {
            if ( Qtable[x].getFlag() == false && Qtable[x].getValue() == -1)
            {
               return false;  //the bucket is not occupied, the value doesn't exist.
            }
        }
        else
        {
            Qtable[x].setValue(-1);
            Qtable[x].setFlag(true);
            elements--;
            return true;                                //value is found and removed
        }
    }
    return false;
}

template <typename T>
void Quadratic<T>::Print() 
{
  for (int i=0; i<m; i++)
  {
     //cout<<Qtable[i].getValue()<<endl;
      if (Qtable[i].getValue() != -1)
      {
        cout<<i<<": "<<Qtable[i].getValue()<<endl;
      }
  }
}

template <typename T>
double Quadratic<T>::loadFactor() 
{
    double x = (double)elements/m;
    //cout<<"!!!number ele is: "<<elements<<endl;

    return x;
     
}