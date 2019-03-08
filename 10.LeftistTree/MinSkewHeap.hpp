/**
*	@file : MinSkewHeap.hpp
*	@author : Lu Yin
*	@date : April 16, 2018
*/

using namespace std;
#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>
#include <math.h>

template <typename T>
MinSkewHeap<T>::MinSkewHeap()
{
    root=nullptr;
}
template <typename T>
MinSkewHeap<T>::~MinSkewHeap()
{
    while (root!=nullptr)
    {
        deletemin();
    }
}


template <typename T>
void MinSkewHeap<T>::buildheap(string name)
{
    ifstream inp;
    inp.open(name);
    int num;
    while(!inp.eof())
    {
        inp>>num;
        insert(num);
    }
    inp.close();
}

template <typename T>
void MinSkewHeap<T>::insert(T s_value)
{
    SkewNode<T>* newnode = new SkewNode<T> (s_value);
    if (root==nullptr)
    {
        root = newnode;
    }
    else
    {
        root=concate(root, newnode);
    }
}


template <typename T>
bool MinSkewHeap<T>::deletemin()
{
    if (root == nullptr)
    {
        return false;
    }
    else
    {
        SkewNode<T>* newroot = concate (root->getLeftChild(), root->getRightChild());
        delete root;
        root = newroot;
        return true;
    }
}

template <typename T>
T MinSkewHeap<T>::findmin()
{
    if(root==nullptr)
    {
        return -1;
    }
    else
    {
        return root->getValue();
    }
}

template <typename T>
SkewNode<T>* MinSkewHeap<T>::concate(SkewNode<T>* a, SkewNode<T>* b)
{
    if (a==nullptr)
    {
        return b;
    }
    else if (b==nullptr)
    {
        return a;
    }
    else if (a->getValue() > b->getValue())
    {
        swap(a,b);
    }
    SkewNode<T>* temp=a->getRightChild();
    a->setRightChild(a->getLeftChild());
    a->setLeftChild(concate(temp,b));
    return a;
}

template <typename T>
void MinSkewHeap<T>::Preorder()
{
    PreorderHelper(root);
}

template <typename T>
void MinSkewHeap<T>::PreorderHelper(SkewNode<T>* m_rootPtr)
{
    if (m_rootPtr!=nullptr)
    {
        cout<<m_rootPtr->getValue()<<" ";
        PreorderHelper(m_rootPtr->getLeftChild());
        PreorderHelper(m_rootPtr->getRightChild());
    }
    else
    {

    }
}

template <typename T>
void MinSkewHeap<T>::Inorder()
{
    InorderHelper(root);
}

template <typename T>
void MinSkewHeap<T>::InorderHelper(SkewNode<T>* m_rootPtr)
{
    if (m_rootPtr!=nullptr)
    {
        InorderHelper(m_rootPtr->getLeftChild());
        cout<<m_rootPtr->getValue()<<" ";
        InorderHelper(m_rootPtr->getRightChild());
    }
    else
    {

    }
}

template <typename T>
void MinSkewHeap<T>::levelorder()
{
    levelorderHelper(root);
    cout<<""<<endl;
}

template <typename T>
void MinSkewHeap<T>::levelorderHelper(SkewNode<T>* m_rootPtr)
{
    Queue<SkewNode<T>*> m;
    Queue<SkewNode<T>*> n;

    if (m_rootPtr!=nullptr)
    {
        m.enqueue(m_rootPtr);
        while (m.isEmpty()==false || n.isEmpty()==false)
        {
            while (m.isEmpty()==false)
            {
                if (m.PrintFront()->getLeftChild()!=nullptr)
                {
                    n.enqueue(m.PrintFront()->getLeftChild());
                }
                if (m.PrintFront()->getRightChild()!=nullptr)
                {
                    n.enqueue(m.PrintFront()->getRightChild());
                }
                cout<<m.peekFront()->getValue()<<" ";
            }
            cout<<" "<<endl;
            while (n.isEmpty()==false)
            {
                if (n.PrintFront()->getLeftChild()!=nullptr)
                {
                    m.enqueue(n.PrintFront()->getLeftChild());
                }
                if (n.PrintFront()->getRightChild()!=nullptr)
                {
                    m.enqueue(n.PrintFront()->getRightChild());
                }
                cout<<n.peekFront()->getValue()<<" ";
            }
            cout<<" "<<endl;
        }
    }
    else
    {

    }
}
