/*
/ @file: DoubleH.hpp
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
DoubleH<T>::DoubleH()
{
    m=53;
    k=10;
    p=13;
    // m=11;
    // k=4;
    // p=5;
    elements=0;

    Dtable = new Bucket<T> [m];
}

template <typename T>
DoubleH<T>::~DoubleH() //desructor
{
    delete[] Dtable;
}

template <typename T>
int DoubleH<T>::Hash(T value)
{
    int bucket = value % m;
    int x=value;
    
    int h1 = p - (x % p);
    int z1;
    
    for (int i=0; i<k; i++)
    {
        z1 = (bucket + i * h1) % m;
        if (Dtable[z1].getValue() == -1)
        { 
            return z1;
        }
    }
    return -1;
}

template <typename T>
bool DoubleH<T>::Find(T value) //whather the value is found before any implementation.
{
    int x=value;
    int bucket = value % m;;
    int h1 = p - (x % p);
    int z1;
    
    for (int i=0; i<k; i++)
    {
        z1 = (bucket + i * h1) % m;
        if (Dtable[z1].getValue() != value)
        {
            if (Dtable[z1].getFlag() == false && Dtable[z1].getValue() == -1)
            {
               return false;  //the bucket is not occupied, the value doesn't exist.
            }
        }
        else
        {
            return true;                   //value is found and removed
        }
    }    
    return false;
}

template <typename T>
bool DoubleH<T>::Insert(T value)
{
   
    if (Find(value) == false)
    {
        if (Hash(value) != -1) //the bucket is empty
        {  
            Dtable[Hash(value)].setValue(value);
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
    //     Dtable[Hash(value)].setValue(value);
    //     elements++;
    //     return true;
    // }
    // else
    // {
    //     return false;
    // }

    
}

template <typename T> 
bool DoubleH<T>::Remove(T value)  //delete a target value
{
    int x=value;
    int bucket = value % m;;
    int h1 = p - (x % p);
    int z1;
    
    for (int i=0; i<k; i++)
    {
        z1 = (bucket + i * h1) % m;
        if (Dtable[z1].getValue() != value)
        {
            if (Dtable[z1].getFlag() == false && Dtable[z1].getValue() == -1)
            {
               return false;  //the bucket is not occupied, the value doesn't exist.
            }
        }
        else
        {
            Dtable[z1].setValue(-1);
            Dtable[z1].setFlag(true);
            elements--;
            return true;                   //value is found and removed
        }
    }    
    return false;
}

template <typename T>
void DoubleH<T>::Print() 
{
  for (int i=0; i<m; i++)
  {
     //cout<<Qtable[i].getValue()<<endl;
      if (Dtable[i].getValue() != -1)
      {
        cout<<i<<": "<<Dtable[i].getValue()<<endl;
      }
  }
}


template <typename T>
double DoubleH<T>::loadFactor() 
{ 
    double x = (double)elements/m;
    //cout<<"!!!number ele is: "<<elements<<endl;
    return x;

}