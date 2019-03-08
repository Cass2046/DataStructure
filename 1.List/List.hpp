/**
*	@file : List.hpp
*	@author : Lu Yin
*	@date : Jan 22, 2018
*/

#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>

using namespace std;

template <typename T>
List<T>::List()      //create an empty list
{
    m_length=0;
    m_front=nullptr;
}

template <typename T>
List<T>::~List()    //delete the whole list at the end.
{

}

template <typename T>
int List<T>::getLength() //return the number of elements in the list L.
{
    return m_length;
}

template <typename T>
bool List<T>::isFoundB4Imp(T value) //recursively
{
    if (find(m_front, value)->getItem() == value) //if the value is already exist in the list
    {
        return true; 
    }
    else
    {
        return false;
    }
}

template <typename T>
void List<T>::insert(Node<T>*m_L, T value) //insert recursively
{
    // if (isFoundB4Imp(value) == false)
    // {
        if (m_front == nullptr)
        {
            Node<T>*new_node = nullptr;  //create a new node and set the value
            new_node->setItem(value);
            m_front=new_node;
        }
        else
        {
            m_front=m_front->getNext(); //go through the whole list and find the last node
            insert(m_front, value);
        }     
        m_length++;
    // }

    // Node<T>*cur=m_front;
    // Node<T>*temp=nullptr;
    // Node<T>*a = new Node<T> ();
    // if (isEmpty() == true) //insert to an empty list.
    // {
    //     a->setItem(value);
    //     m_length=a;
    //     cout<<value+" is inserted to the list"<<endl;
    // }
    // else
    // {
    //     while (cur!= nullptr) //go through the whole list until find out the element.
    //     {
    //         temp=cur;
    //         cur=cur->getNext();
    //     }
    //     temp->setNext(a);
    //     temp->setItem(value);
    //     m_length++;
    //     delete cur;
    //     cur=nullptr;
    //     delete temp;
    //     temp=nullptr;
    //     cout<<value+" is inserted at the end of the list"<<endl;
    // }
}

template <typename T>
bool List<T>::isEmpty()
{
    if (m_length == 0)   //return true is the list is empty/
    {
        return true;
    }
    else                //return false is the list is not empty.
    {
        return false;
    }
}

template <typename T>
bool List<T>::erase(Node<T>*m_L, value)  //recursively
{
    // if (isFoundB4Imp(value) == true) //the value is found in the list
    // {
        if (m_front->getItem() == value)
        {
            delete m_front;
            m_front=nullptr;
        }
        else
        {
            m_front=m_front->getNext();
            erase(m_front, value);
        }
        m_length--;
    // }
}

template <typename T>
void List<T>::print(Node<T>*m_L)
{
    if (m_front == nullptr)
    {
        cout<<" ."<<endl;
    } 
    else
    {
        cout<<m_front+", "<<end;
        m_front=m_front->getNext();
        print(m_front);
    }
    // if (isEmpty()==true)  //cannot print out an empty list
    // {
    //     cout<<"The list is empty."<<endl;
    // }
    // else
    // {
    //     cout<<"List: ";
    //     Node<T>*cur=m_front;
    //     Node<T>*temp=m_front;
    //     while (cur != nullptr)
    //     {
    //         temp = cur;
    //         cout<<temp->getItem()<<endl;
    //         cur = cur->getNext();
    //     }
    // }
}

template <typename T>
void List<T>::printList()
{
    print(m_front);
}

template <typename T>
Node<T>* List<T>::find(ListL, T value)
{
    if (m_front == nullptr)
    {
        return nullptr;
    }
    else if (m_front->getItem() == value)
    {
        return m_front;
    }
    else
    {
        m_front=m_front->getNext();
    }
    // //if the list is empty
    // if (isEmpty() == true)
    // {
    //     return nullptr;
    // }
    // //none-empty list
    // else
    // {
    //     int f;
    //     bool isFound=false;
    //     cout<<"Enter the number to be found: "<<endl;
    //     cin>>f;
    //     Node<T>*cur=m_front;

    //     while(isFound==false && cur!=nullptr)
    //     {
    //         if (cur->getItem()!=value) //the number is found
    //         {
    //             cur=cur->getNext();
    //             if (cur==nullptr)
    //             {
    //                 cout<<value+" is not in the list."<<endl;
    //             }
    //         }
    //         else //the number cannot be found
    //         {
    //             isFound=true;
    //             return cur;
    //             cout<<value+" is in the list. "<<endl;
    //         }
    //     }
    // }
}
