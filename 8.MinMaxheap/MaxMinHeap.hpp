/**
*	@file : MaxMinHeap.hpp
*	@author : Lu Yin
*	@date : March 30, 2018
*/

using namespace std;
#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>
#include <math.h>

template <typename T>
MaxMinHeap<T>::MaxMinHeap(int size)
{
    max_size=size;
    max_a=new T[size];
    max_Item=0;
}
template <typename T>
MaxMinHeap<T>::MaxMinHeap(string name, int size)
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
        max_a[max_Item+1]=numb;
        max_Item++;
    }
    inp.close();
    buildheap();
}
template <typename T>
MaxMinHeap<T>::~MaxMinHeap()
{
    delete[] max_a;
}

template <typename T>
bool MaxMinHeap<T>::isMinlevel(int index)
{
    int i=log2(index);
    if(i%2 != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
int MaxMinHeap<T>::getMinchild(int index) //index=parent
{
    int leftchild = 2*index;
    int rightchild=leftchild+1;
    if (leftchild>max_Item)
    {
        return index;
    }
    else if (rightchild>max_Item) //no rightchild
    {
        if (max_a[leftchild] < max_a[index])
        {
            return leftchild;
        }
        else
        {
            return index;
        }
    }
    else //there are rightchild & leftchild
    {
        if (max_a[rightchild] < max_a[leftchild])
        {
            if (max_a[rightchild] < max_a[index])
            {
                return rightchild;
            }
            else if (max_a[rightchild] == max_a[index])
            {
                return index;
            }
            else //>
            {
                return index;
            }
        }
        else if (max_a[leftchild] < max_a[rightchild])
        { 
            if (max_a[leftchild] < max_a[index])
            {
                return leftchild;
            }
            else if (max_a[leftchild] == max_a[index])
            {
                return index;
            }
            else //>
            {
                return index;
            }
        }
        else //=
        {
            if (max_a[leftchild]>max_a[index])
            {
                return index;
            }
            else if (max_a[leftchild] == max_a[index])
            {
                return index;
            }
            else
            {
                return leftchild;
            }
        }
    }
}

template <typename T>
int MaxMinHeap<T>::getMaxchild(int index)
{
    int leftchild = 2*index;
    int rightchild=leftchild+1;
    if (max_Item<leftchild)  //no children
    {
        return index;
    }
    else if (max_Item<rightchild)  //no right child
    {
        if (max_a[leftchild] > max_a[index])
        {
            return leftchild;
        }
        else
        {
            return index;
        }
    }
    else //both children
    {
        if (max_a[rightchild] > max_a[leftchild])
        {
            if (max_a[rightchild] > max_a[index])
            {
                return rightchild;
            }
            else //> or ==
            {
                return index;
            }
        }
        else if (max_a[leftchild] > max_a[rightchild])
        { 
            if (max_a[leftchild] > max_a[index])
            {
                return leftchild;
            }
            else //>
            {
                return index;
            }
        }
        else //=
        {
            if (max_a[leftchild] > max_a[index])
            {
                return leftchild;
            }
            else
            {
                return index;
            }
        }
    }
}

template <typename T>
void MaxMinHeap<T>::buildheap()
{
    int p=max_Item/2;
    for (int i=p; i>0; i--)
    {
        helpbuild(i);
    }
}

template <typename T>
void MaxMinHeap<T>::helpbuild(int root)
{
    int gchild = root*4;
    if (gchild<=max_Item)  //it has grandchild
    {
        if(isMinlevel(root)==true)  //min level
        {

            if (max_a[root] > max_a[gchild] || max_a[root] > max_a[gchild+1] || max_a[root] > max_a[gchild+2] || max_a[root] > max_a[gchild+3])
            {
                //find the minimum grandchild
                int smallerchild=gchild;
                for (int i=gchild+1; i<=gchild+3 && i<= max_Item; i++)
                {
                    if (max_a[i] < max_a[smallerchild])
                    {        
                        smallerchild = i;
                    }
                }
                swap(max_a[root], max_a[smallerchild]);
                int parent=smallerchild/2;
                //maxlevel
                if (max_a[smallerchild]>max_a[parent])
                {
                    swap(max_a[smallerchild], max_a[parent]);
                }
                helpbuild(smallerchild);
            }
        }
        else   //max level
        {
            if (root < max_a[gchild] || root < max_a[gchild+1] || root < max_a[gchild+2] || root < max_a[gchild+3])
            {
                int greaterchild=gchild;
                for (int i=gchild+1; i<=gchild+3; i++)
                {
                    if (max_a[i] > max_a[greaterchild])
                    {
                        greaterchild = i;
                    }
                }
                swap(max_a[root], max_a[greaterchild]);
                int parent=greaterchild/2;
                if (max_a[greaterchild]<max_a[parent])  //minlevel
                {
                    swap(max_a[greaterchild], max_a[parent]);
                }
                helpbuild(greaterchild);
            }
        }
    }
    else  //no grandchild
    {
        if(isMinlevel(root)==true)  //min-level
        {
            if (getMinchild(root)!=root)
            {
                swap(max_a[root], max_a[getMinchild(root)]);
            }
        }
        else  //max level
        {
            if (getMaxchild(root)!=root)
            {
                swap(max_a[root], max_a[getMaxchild(root)]);
            }
        }
    }
}

template <typename T>
void MaxMinHeap<T>::insert(T value)
{
    if (max_Item==0)
    {
        max_a[1]=value;
    }
    else if (max_Item==1)
    {
        max_a[2]=value;
        if (max_a[2]>max_a[1])
        {
            swap(max_a[1], max_a[2]);
        }
    }
     else
    {
        max_a[max_Item+1]=value;
        int child = max_Item+1;  //Index of child
        int parent = child/2;    //index of parent
        int grandparent;
        bool allright=false;
        if (max_a[child] < max_a[parent])
        {
            if (isMinlevel(parent) == true) //child = max-level, parent = min-level
            {
                swap (max_a[parent], max_a[child]);
                child=parent;
                parent=child/2;
                grandparent=parent/2;
                while (grandparent>0 && allright==false)
                {
                    if (max_a[child] < max_a[grandparent])//min level
                    {
                        swap (max_a[child], max_a[grandparent]);
                        child=grandparent;
                        grandparent=child/4;
                    }
                    else
                    {
                        allright=true;
                    }
                }
            }
            //child < parent(max-level),only check minLevels
            else
            {
                grandparent=child/4;
                while (grandparent>0 && allright==false) 
                {
                    if (max_a[child] < max_a[grandparent]) //min child < grandparent
                    {
                        swap (max_a[child], max_a[grandparent]);
                        child=grandparent;
                        grandparent=child/4;
                    }
                    else
                    {
                        allright=true;
                    }
                }
            }
        }     
        else //min_a[child] > min_a[parent]
        {
            if (isMinlevel(parent) == false) //child = min-level, parent = max-level
            {
                swap (max_a[parent], max_a[child]);
                child = parent;
                parent = child/2;
                grandparent = parent/2;
                while (grandparent>0 && allright==false)
                {
                    if (max_a[child] > max_a[grandparent])  //max-level
                    {
                        swap(max_a[child], max_a[grandparent]);
                        child=grandparent;
                        grandparent=child/4;
                    }
                    else
                    {
                        allright=true;
                    }
                }
            }
            else  //child = max-level, parent = min-level
            {
                grandparent=child/4;
                while (grandparent>0 && allright==false) 
                {
                    if (max_a[child] > max_a[grandparent]) //max child > grandparent
                    {
                        swap (max_a[child], max_a[grandparent]);
                        child=grandparent;
                        grandparent=child/4;
                    }
                    else
                    {
                        allright=true;
                    }
                }
            }
        }
    }
    max_Item++;
}


template <typename T>
bool MaxMinHeap<T>::deletemin()
{
    if(max_Item==0)
    {
        return false;
    }
    else if (max_Item==1)
    {
        max_a[1]=-1;
        max_Item--;
        return true;
    }
    else
    {
        if (max_a[2] <= max_a[3])
        {
            max_a[2]=max_a[max_Item];
            max_a[max_Item]=0;
            max_Item--; 
            helpbuild(2);
        }
        else
        {
            max_a[3]=max_a[max_Item];
            max_a[max_Item]=0;
            max_Item--; 
            helpbuild(3);
        }
        return true;
    }
}

template <typename T>
T MaxMinHeap<T>::findmin()
{
    if(max_Item==0)
    {
        return -1;
    }
    else if(max_Item==1)
    {
        return max_a[1];
    }
    else
    {
        if (max_Item == 2)
        {
            return max_a[2];
        }
        else if (max_a[2] <= max_a[3])
        {
            return max_a[2];
        }
        else
        {
            return max_a[3];
        }
    }
}

template <typename T>
T MaxMinHeap<T>::findmax()
{
    if (max_Item == 0)
    {
        return -1;
    }
    else
    {
        return max_a[1];
    }
}


template <typename T>
bool MaxMinHeap<T>::deletemax()
{
    if (max_Item==0)
    {
        return false;
    }
    else
    {
        max_a[1]=max_a[max_Item];
        max_Item--;
        
        //cout<<max_Item<<endl;
        T* temp = new T[max_size];
        for (int i=1; i<=max_Item; i++)
        {
            temp[i]=max_a[i];
        }
        delete[] max_a;
        max_a = temp;
        //swap
        helpbuild(1);
        return true;
    }
}


template <typename T>
void MaxMinHeap<T>::levelorder()
{
    int c = 1;
    int b = 2;
    int times = 1;
    for (int i=1; i<=max_Item; i++)
    {
        cout<<max_a[i]<<" ";
        if(i==c)
        {
            cout<<""<<endl;
            times = b*times;
            c = times + i;
        }
        else if(i%2!=0 && i!=max_Item)
        {
            cout<<" - ";
        }
    }
    cout<<""<<endl;
}