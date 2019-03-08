/**
*	@file : MinMaxHeap.hpp
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
MinMaxHeap<T>::MinMaxHeap(int size)
{
    min_size=size;
    min_a=new T[size];
    min_Item=0;
}

template <typename T>
MinMaxHeap<T>::MinMaxHeap(string name, int size)
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
        min_a[min_Item+1]=numb;
        min_Item++;
    }
    inp.close();
    buildheap();
}

template <typename T>
MinMaxHeap<T>::~MinMaxHeap()
{
    delete[] min_a;
}

template <typename T>
bool MinMaxHeap<T>::isMinlevel(int index)
{
    int i=log2(index);
    if(i%2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
int MinMaxHeap<T>::getMinchild(int index) //index=parent
{
    int leftchild = 2*index;
    int rightchild=leftchild+1;
    if (leftchild>min_Item)
    {
        return index;
    }
    else if (rightchild>min_Item) //no rightchild
    {
        if (min_a[leftchild] < min_a[index])
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
        if (min_a[rightchild] < min_a[leftchild])
        {
            if (min_a[rightchild] < min_a[index])
            {
                return rightchild;
            }
            else if (min_a[rightchild] == min_a[index])
            {
                return index;
            }
            else //>
            {
                return index;
            }
        }
        else if (min_a[leftchild] < min_a[rightchild])
        { 
            if (min_a[leftchild] < min_a[index])
            {
                return leftchild;
            }
            else if (min_a[leftchild] == min_a[index])
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
            if (min_a[leftchild]>min_a[index])
            {
                return index;
            }
            else if (min_a[leftchild] == min_a[index])
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
int MinMaxHeap<T>::getMaxchild(int index)
{
    int leftchild = 2*index;
    int rightchild=leftchild+1;
    if (min_Item<leftchild)  //no children
    {
        return index;
    }
    else if (min_Item<rightchild)  //no right child
    {
        if (min_a[leftchild] > min_a[index])
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
        if (min_a[rightchild] > min_a[leftchild])
        {
            if (min_a[rightchild] > min_a[index])
            {
                return rightchild;
            }
            else //> or ==
            {
                return index;
            }
        }
        else if (min_a[leftchild] > min_a[rightchild])
        { 
            if (min_a[leftchild] > min_a[index])
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
            if (min_a[leftchild] > min_a[index])
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
void MinMaxHeap<T>::buildheap()
{
    int p=min_Item/2;
    for (int i=p; i>0; i--)
    {
        helpbuild(i);
    }
}

template <typename T>
void MinMaxHeap<T>::helpbuild(int root)
{
    int gchild = root*4;
    if (gchild<=min_Item)  //it has grandchild
    {
        if(isMinlevel(root)==true)  //min level
        {
            if (min_a[root] > min_a[gchild] || min_a[root] > min_a[gchild+1] || min_a[root] > min_a[gchild+2] || min_a[root] > min_a[gchild+3])
            {
                //find the minimum grandchild
                int smallerchild=gchild;
                for (int i=gchild+1; i<=gchild+3 && i<=min_Item; i++)
                {
                    if (min_a[i] < min_a[smallerchild])
                    {        
                        smallerchild = i;
                    }
                }
                swap(min_a[root], min_a[smallerchild]);
                int parent=smallerchild/2;
                //maxlevel
                if (min_a[smallerchild]>min_a[parent])
                {
                    swap(min_a[smallerchild], min_a[parent]);
                }
                helpbuild(smallerchild);
            }
        }
        else   //max level
        {
            if (root < min_a[gchild] || root < min_a[gchild+1] || root < min_a[gchild+2] || root < min_a[gchild+3])
            {
                int greaterchild=gchild;
                for (int i=gchild+1; i<=gchild+3; i++)
                {
                    if (min_a[i] > min_a[greaterchild])
                    {
                        greaterchild = i;
                    }
                }
                swap(min_a[root], min_a[greaterchild]);
                int parent=greaterchild/2;
                if (min_a[greaterchild]<min_a[parent])  //minlevel
                {
                    swap(min_a[greaterchild], min_a[parent]);
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
                swap(min_a[root], min_a[getMinchild(root)]);
            }
        }
        else  //max level
        {
            if (getMaxchild(root)!=root)
            {
                swap(min_a[root], min_a[getMaxchild(root)]);
            }
        }
    }

}
template <typename T>
void MinMaxHeap<T>::insert(T value)
{
    if (min_Item==0)
    {
        min_a[1]=value;
    }
    else if (min_Item==1)
    {
        min_a[2]=value;
        if (min_a[2]<min_a[1])
        {
            swap(min_a[1], min_a[2]);
        }
    }
    else
    {
        min_a[min_Item+1]=value;
        int child = min_Item+1;  //Index of child
        int parent = child/2;    //index of parent
        int grandparent;
        bool allright=false;

        if (min_a[child] < min_a[parent])
        {
            if (isMinlevel(parent) == true) //child = max-level, parent = min-level
            {
                swap (min_a[parent], min_a[child]);
                child=parent;
                parent=child/2;
                grandparent=parent/2;
                while (grandparent>0 && allright==false)
                {
                    if (min_a[child] < min_a[grandparent])
                    {
                        swap (min_a[child], min_a[grandparent]);
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
                    if (min_a[child] < min_a[grandparent]) //child < grandparent
                    {
                        swap (min_a[child], min_a[grandparent]);
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
        else //min_a[child] < min_a[parent]
        {
            if (isMinlevel(parent) == false) //child = min-level, parent = max-level
            {
                swap (min_a[parent], min_a[child]);
                child = parent;
                parent = child/2;
                grandparent = parent/2;
                while (grandparent>0 && allright==false)
                {
                    if (min_a[child] > min_a[grandparent])  //min-level
                    {
                        swap(min_a[child], min_a[grandparent]);
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
                    if (min_a[child] > min_a[grandparent]) //child > grandparent
                    {
                        swap (min_a[child], min_a[grandparent]);
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
    min_Item++;
}

template <typename T>
bool MinMaxHeap<T>::deletemin()
{
    if (min_Item==0)
    {
        return false;
    }
    else
    {
        min_a[1]=min_a[min_Item];
        min_Item--;
        
        //cout<<min_Item<<endl;
        T* temp = new T[min_size];
        for (int i=1; i<=min_Item; i++)
        {
            temp[i]=min_a[i];
        }
        delete[] min_a;
        min_a = temp;
        //swap
        helpbuild(1);
        return true;
    }
}

template <typename T>
T MinMaxHeap<T>::findmin()
{
    if (min_Item == 0)
    {
        return -1;
    }
    else
    {
        return min_a[1];
    }
}

template <typename T>
T MinMaxHeap<T>::findmax()
{
    if(min_Item==0)
    {
        return -1;
    }
    else if(min_Item==1)
    {
        return min_a[1];
    }
    else  //item>=2
    {
        if (min_Item == 2)
        {
            return min_a[2];
        }
        else if (min_a[2]>=min_a[3])
        {
            return min_a[2];
        }
        else
        {
            return min_a[3];
        }
    }
}
    

template <typename T>
bool MinMaxHeap<T>::deletemax()
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
        if (min_a[2] >= min_a[3])
        {
            min_a[2]=min_a[min_Item];
            min_a[min_Item]=0;
            min_Item--; 
            helpbuild(2);
        }
        else
        {
            min_a[3]=min_a[min_Item];
            min_a[min_Item]=0;
            min_Item--; 
            helpbuild(3);
        }
        return true;
    }
}

template <typename T>
void MinMaxHeap<T>::levelorder()
{
    int c = 1;
    int b = 2;
    int times = 1;
    for (int i=1; i<=min_Item; i++)
    {
        cout<<min_a[i]<<" ";
        if(i==c)
        {
            cout<<""<<endl;
            times = b*times;
            c = times + i;
        }
        else if(i%2!=0 && i!=min_Item)
        {
            cout<<" - ";
        }
    }
    cout<<""<<endl;
}