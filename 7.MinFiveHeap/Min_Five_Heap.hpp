/**
*	@file : Min_Five_Heap.hpp
*	@author : Lu Yin
*	@date : March 12, 2018
*/

using namespace std;
#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>
template <typename T>
Min_Five_Heap<T>::Min_Five_Heap(int size)
{
    min_size=size;
    min_a=new T[size];
    min_Item=0;
}

template <typename T>
Min_Five_Heap<T>::Min_Five_Heap(string name, int size)
{
    min_size=size;
    min_a=new T[size];
    min_Item=0;
    ifstream inp;
    inp.open(name);
    int numb;
    while (!inp.eof())
    {
        inp>>numb;
        min_a[min_Item]=numb;
        min_Item++;
    }
    inp.close();
    buildheap();
}

template <typename T>
Min_Five_Heap<T>::~Min_Five_Heap()
{
    delete[] min_a;
}

template <typename T>
void Min_Five_Heap<T>::buildheap()
{
    int lastIndex=min_Item-1;
    int ParentIndex=(lastIndex-1)/5;
    while(ParentIndex>=0)
    {
        int smallchild = 5*ParentIndex+1;
        bool ischange = false;
        while(ischange==false && smallchild < min_Item)
        {
            int childIndex = smallchild+1;
            for(int i=1; i<5 && childIndex<min_Item ;i++)
            {
                if(min_a[smallchild] > min_a[childIndex])
                {
                    smallchild = childIndex;
                }
                childIndex++;
            }
            if(min_a[smallchild] < min_a[ParentIndex])  
            {
                swap(min_a[smallchild], min_a[ParentIndex]);
                ParentIndex = smallchild;
                smallchild = 5*ParentIndex+1;
            }
            else
            {
                ischange = true;
            }
        }
        ParentIndex--;
    }
}

template <typename T>
void Min_Five_Heap<T>::insert(T value)
{
    if(min_Item >= min_size)
    {
        //enlarge the size
        min_size=min_size*2;
        T* temp = new T[min_size];
        for(int i=0; i < min_Item; i++)
        {
            temp[i]=min_a[i];               
        }
        delete[] min_a;
        min_a = temp;
        min_a[min_Item] = value;
    }
    else
    {
        min_a[min_Item] = value;
    }
    int childIndex = min_Item;
    int parentIndex=0;
    bool change = false;
    while(childIndex > 0 && change==false)
    {
        parentIndex = (childIndex-1)/5;
        if(value < min_a[parentIndex])
        {
            swap(min_a[parentIndex],min_a[childIndex]);
            childIndex = parentIndex;
        }
        else
        {
            change = true;
        }
    }
    min_Item++;
}

template <typename T>
bool Min_Five_Heap<T>::deletemin()
{
    if (min_Item==0)
    {
        return false;
    }
    else
    {
        min_a[0]=min_a[min_Item-1];
        min_Item--;
        cout<<min_Item<<endl;
        T* temp = new T[min_size];
        for (int i=0; i<min_Item; i++)
        {
            temp[i]=min_a[i];
        }
        delete[] min_a;
        min_a = temp;

        //swap
        int smallchild = 1;
        int ParentIndex = 0;
        bool ischange = false;
        while(ischange==false && smallchild < min_Item)
        {
            int childIndex = smallchild+1;
            for(int i=1; i<5 && childIndex<min_Item ;i++)
            {
                if(min_a[smallchild] > min_a[childIndex])
                {
                    smallchild = childIndex;
                }
                childIndex++;
            }
            if(min_a[smallchild] < min_a[ParentIndex])
            {
                swap(min_a[smallchild], min_a[ParentIndex]);
                ParentIndex = smallchild;
                smallchild = 5*ParentIndex+1;
            }
            else
            {
                ischange = true;
            }
        }
        return true;
    }
}

template <typename T>
T Min_Five_Heap<T>::findmin()
{
    if (min_Item == 0)
    {
        return -1;
    }
    else
    {
        return min_a[0];
    }
}

template <typename T>
T Min_Five_Heap<T>::findmax()
{
    if(min_Item==0)
    {
        return -1;
    }
    else if(min_Item==1)
    {
        return min_a[0];
    }
    else
    {
        int lastIndex = min_Item-1;
        int firstIndex = (lastIndex-1)/5+1;
        int bigIndex = firstIndex;
        firstIndex++;
        for(int i = firstIndex; i<min_Item; i++)
        {
            if(min_a[bigIndex] < min_a[i])
            {
                bigIndex = i;
            }
        }
        return min_a[bigIndex];
    }
}
    

template <typename T>
bool Min_Five_Heap<T>::deletemax()
{
    if(min_Item==0)
    {
        return false;
    }
    else if(min_Item==1)
    {
        min_a[0] = -1;
        min_Item--;
        return true;
    }
    else
    {
        int lastIndex = min_Item-1;
        int firstIndex = (lastIndex-1)/5+1;
        int bigIndex = firstIndex;
        firstIndex++;
        for(int i = firstIndex; i < min_Item; i++)
        {
            if(min_a[bigIndex] < min_a[i])  //>
            {
                bigIndex = i;
            }
        }
        min_a[bigIndex]=min_a[min_Item-1];
        min_Item--;
        T* temp = new T[min_size];
        for (int i=0; i<min_Item; i++)
        {
            temp[i]=min_a[i];
        }
        delete[] min_a;
        min_a = temp;
        return true;
    }
}

template <typename T>
void Min_Five_Heap<T>::levelorder()
{
    int c = 0;
    int b = 5;
    int times = 1;
    for (int i=0; i<min_Item; i++)
    {
        cout<<min_a[i]<<" ";
        if(i==c)
        {
            cout<<""<<endl;
            c = b*times + i;
            times = b*times;
            //cout<<"-";
        }
        else if(i%5==0&& i!=min_Item-1)
        {
            cout<<"- ";
        }
    }
    cout<<""<<endl;
}