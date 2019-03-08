/**
*	@file : Max_Five_Heap.hpp
*	@author : Lu Yin
*	@date : April 10, 2018
*/

using namespace std;
#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>
template <typename T>
Max_Five_Heap<T>::Max_Five_Heap(int size)
{
    max_size=size;
    max_a=new T[size];
    max_Item=0;
}
template <typename T>
Max_Five_Heap<T>::Max_Five_Heap(string name, int size)
{
    max_size=size;
    max_a=new T[size];
    max_Item=0;
    ifstream inp;
    inp.open(name);//open file
    int numb;
    while (!inp.eof())
    {
        inp>>numb;
        max_a[max_Item]=numb;
        max_Item++;
    }
    inp.close();
    buildheap();
}
template <typename T>
Max_Five_Heap<T>::~Max_Five_Heap()
{
    delete[] max_a;
}

template <typename T>
void Max_Five_Heap<T>::buildheap()
{
    int lastIndex = max_Item-1;
    int ParentIndex = (lastIndex-1)/5;
    while(ParentIndex>=0)
    {
        int bigchild = 5*ParentIndex+1;
        bool ischange = false;
        while(ischange==false && bigchild < max_Item)
        {
            int childIndex = bigchild+1;
            for(int i=1; i<5 && childIndex<max_Item ;i++)
            {
                if(max_a[bigchild] < max_a[childIndex])
                {
                    bigchild = childIndex;
                }
                childIndex++;
            }
            if(max_a[bigchild] > max_a[ParentIndex])
            {
                swap(max_a[bigchild], max_a[ParentIndex]);
                ParentIndex = bigchild;
                bigchild = 5*ParentIndex+1;
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
void Max_Five_Heap<T>::insert(T value)
{
    if(max_Item >= max_size)
    {
        //enlarge the size
        max_size=max_size*2;
        T* temp = new T[max_size];
        for(int i=0; i < max_Item; i++)
        {
            temp[i]=max_a[i];               
        }
        delete[] max_a;
        max_a = temp;
        max_a[max_Item] = value;
    }
    else
    {
        max_a[max_Item] = value;
    }
    int childIndex = max_Item;
    int parentIndex=0;
    bool change = false;
    while(childIndex > 0 && change==false)
    {
        parentIndex = (childIndex-1)/5;
        if(value>max_a[parentIndex])
        {
            swap(max_a[parentIndex],max_a[childIndex]);
            childIndex = parentIndex;
        }
        else
        {
            change = true;
        }
    }
    max_Item++;
}
template <typename T>
void Max_Five_Heap<T>::insertNoBuild(T value)
{
    max_a[max_Item] = value;
    max_Item++;
}
template <typename T>
bool Max_Five_Heap<T>::deletemin()
{
    if(max_Item==0)
    {
        return false;
    }
    else if(max_Item==1)
    {
        max_a[0] = -1;
        max_Item--;
        return true;
    }
    else
    {
        int lastIndex = max_Item-1;
        int firstIndex = (lastIndex-1)/5+1;
        int smallIndex = firstIndex;
        firstIndex++;
        for(int i = firstIndex; i<max_Item;i++)
        {
            if(max_a[smallIndex] > max_a[i])
            {
                smallIndex = i;
            }
        }
        max_a[smallIndex]=max_a[max_Item-1];
        max_Item--;
        max_a[max_Item]=-1;
        // T* temp = new T[max_size];
        // for (int i=0; i<max_Item; i++)
        // {
        //     temp[i]=max_a[i];
        // }
        // delete[] max_a;
        // max_a = temp;
        return true;
    }
}

template <typename T>
T Max_Five_Heap<T>::findmin()
{
    if(max_Item==0)
    {
        //cout<<"Empty"<<endl;
        return -1;
    }
    else if(max_Item==1)
    {
        return max_a[0];
    }
    else
    {
        int lastIndex = max_Item-1;
        int firstIndex = (lastIndex-1)/5+1;
        int smallIndex = firstIndex;
        firstIndex++;
        for(int i = firstIndex; i<max_Item; i++)
        {
            if(max_a[smallIndex] > max_a[i])
            {
                smallIndex = i;
            }
        }
        return max_a[smallIndex];
    }
}

template <typename T>
T Max_Five_Heap<T>::findmax()
{
    if (max_Item == 0)
    {
        //cout<<"Empty"<<endl;
        return -1;
    }
    else
    {
        return max_a[0];
    }
}


template <typename T>
bool Max_Five_Heap<T>::deletemax()
{
    if (max_Item==0)
    {
        //cout<<"Empty array"<<endl;
        return false;
    }
    else
    {
        max_a[0]=max_a[max_Item-1];
        max_Item--;
        max_a[max_Item]=-1;
        //T* temp = new T[max_size];
        //for (int i=0; i<max_Item; i++)
        //{
        //     temp[i]=max_a[i];
        // }
        //delete[] max_a;
        //max_a = temp;

        //swap
        int bigchild = 1;
        int ParentIndex = 0;
        bool ischange = false;
        while(ischange==false && bigchild < max_Item)
        {
            int childIndex = bigchild+1;
            for(int i=1; i<5 && childIndex<max_Item ;i++)
            {
                if(max_a[bigchild] < max_a[childIndex])
                {
                    bigchild = childIndex;
                }
                childIndex++;
            }

            if(max_a[bigchild] > max_a[ParentIndex])
            {
                swap(max_a[bigchild], max_a[ParentIndex]);
                ParentIndex = bigchild;
                bigchild = 5*ParentIndex+1;
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
void Max_Five_Heap<T>::levelorder()
{
    int c = 0;
    int b = 5;
    int times = 1;
    for (int i=0; i<max_Item; i++)
    {
        cout<<max_a[i]<<" ";
        if(i==c)
        {
            cout<<""<<endl;
            c = b*times + i;
            times = b*times;
        }
    }
    cout<<""<<endl;
}