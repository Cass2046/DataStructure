/**
*	@file : List.hpp
*	@author : Lu Yin
*	@date : March 10, 2018
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
    while(isEmpty()==false)
    {
        removeFront();
    }
}

template <typename T>
bool List<T>::removeFront() //delete the node at the front
{
    Node<T>*cur=nullptr;
    bool isRemoved = false;
    if(isEmpty()==false)
    {
        cur=m_front;
        m_front=m_front->getNext();
        delete cur;
        m_length--;
        isRemoved=true;
    }
    return (isRemoved);
}

template <typename T>
int List<T>::getLength() //return the number of elements in the list L.
{
    return m_length;
}

template <typename T>
bool List<T>::isFoundB4Imp(T value) //find the number before any implementation
{
    if(find(m_front, value)==nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
}

template <typename T>
void List<T>::AddFront(T value)
{
    if (isFoundB4Imp(value) == false)
    {
        Node<T>*new_node = new Node<T>();  //create a new node and set the value
        new_node->setItem(value);
        if (m_front == nullptr)
        {
            m_front=new_node;  
        }
        else
        {
            new_node->setNext(m_front);
            m_front=new_node;
        }
        m_length++;
    }
    else
    {
        
    }
    
}

template <typename T>
Node<T>* List<T>::insert(Node<T>*m_L, T value) //insert recursively
{

    if (m_front == nullptr)  //insert value to an empty list
    {
        Node<T>*new_node = new Node<T>();  //create a new node and set the value
        new_node->setItem(value);
        m_front=new_node;
        return m_front;
    }
    else if (m_L != nullptr)
    {
        Node<T>*cur=m_L; //go through the whole list and find the last node
        Node<T>*new_node = new Node<T>();
        new_node=insert(m_L->getNext(), value);
        cur->setNext(new_node);
        return cur;
    }
    else
    {
        Node<T>*new_node = new Node<T>();  //create a new node and set the value
        new_node->setItem(value);
        m_L=new_node;
        return m_L;
    }
}

template <typename T>
void List<T>::InsertNow(T value) //call the recursive insert func
{
    if (isFoundB4Imp(value) == false)
    {
        Node<T>* new_list = insert(m_front, value);
        m_length++;
        m_front=new_list;
    }
    else
    {
        
    }

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
Node<T>* List<T>::erase(Node<T>*m_L, T value)  //delete value in the list recursively
{
    if (m_front->getItem() == value) //if the first number is the one to delete
    {
        Node<T>*new_node=m_L;
        new_node = new_node -> getNext();
        delete m_L;
        m_L=nullptr;
        return new_node;
    }
    else if(m_L->getItem() != value) // if the number to be deleted is among other numbers
    {
        Node<T>*cur=m_L;
        cur = cur -> getNext();
        Node<T>*new_node = new Node<T>();
        new_node = erase(m_L->getNext(), value);
        m_L->setNext(new_node);
        return m_L;
    }
    else
    {
        Node<T>*temp=m_L;
        temp=temp->getNext();
        delete m_L;
        m_L=nullptr;
        return temp;
    }
}

template <typename T>
void List<T>::EraseNow(T value)  //call recursive erase func
{
    if (isFoundB4Imp(value) == true)
    {
        Node<T>* new_list = erase(m_front, value);
        m_length--;
        m_front = new_list;
    }

}

template <typename T>
void List<T>::print(Node<T>*m_L)
{
    if (m_L == nullptr)
    {
        cout<<" "<<endl;
    }
    else
    {
        Node<T>*cur = m_L;
        cout<<cur->getItem()<<" ";
        print(cur->getNext());  
    }
}

template <typename T>
void List<T>::printList()
{
    print(m_front);
}

template <typename T>
Node<T>* List<T>::find(Node<T>*m_L, T value)
{
    if (m_L == nullptr)  //weather it is an empty list
    {
        return nullptr;
    }
    else if (m_L->getItem() == value) //weather the value exists.
    {
        return m_L;
    }
    else  //jump to the next node
    {
        return find(m_L->getNext(), value);
    }

}


