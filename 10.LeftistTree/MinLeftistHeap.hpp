/**
*	@file : MaxLeftistHeap.hpp
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
MinLeftistHeap<T>::MinLeftistHeap()
{
    root=nullptr;
}
template <typename T>
MinLeftistHeap<T>::~MinLeftistHeap()
{
    while (root!=nullptr)
    {
        deletemin();
    }
}


template <typename T>
void MinLeftistHeap<T>::buildheap(string name)
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
void MinLeftistHeap<T>::insert(T m_value)
{
    LeftistNode<T>* newnode = new LeftistNode<T> (m_value);
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
bool MinLeftistHeap<T>::deletemin()
{
    if (root==nullptr)
    {
        return false;
    }
    else
    {
        LeftistNode<T>* newroot = concate (root->getLeftChild(), root->getRightChild());
        delete root;
        root = newroot;
        return true;
    }
}

template <typename T>
T MinLeftistHeap<T>::findmin()
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
LeftistNode<T>* MinLeftistHeap<T>::concate(LeftistNode<T>* a, LeftistNode<T>* b)
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
    a->setRightChild(concate(a->getRightChild(),b));
    adrank(a);
    if (a->getLeftChild()!=nullptr)
    {
        if (a->getLeftChild()->getRank() < a->getRightChild()->getRank())
        {
            //swap L & R child
            LeftistNode<T>* temp=a->getLeftChild();
            a->setLeftChild(a->getRightChild());
            a->setRightChild(temp);
            temp=nullptr;
        }
    }
    else
    {
        //swap L & R child
        LeftistNode<T>* temp=a->getLeftChild();
        a->setLeftChild(a->getRightChild());
        a->setRightChild(temp);
        temp=nullptr;
    }
    return a;
}

template <typename T>
void MinLeftistHeap<T>::adrank(LeftistNode<T>* m_root)
{
    if (m_root->getLeftChild()==nullptr || m_root->getRightChild()==nullptr)
    {
        m_root->setRank(1);
    }
    else
    {
        if (m_root->getLeftChild()->getRank()<m_root->getRightChild()->getRank())
        {
            m_root->setRank(m_root->getLeftChild()->getRank()+1);
        }   
        else
        {
            m_root->setRank(m_root->getRightChild()->getRank()+1);
        }
    }
}

template <typename T>
void MinLeftistHeap<T>::Preorder()
{
    PreorderHelper(root);
}

template <typename T>
void MinLeftistHeap<T>::PreorderHelper(LeftistNode<T>* m_rootPtr)
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
void MinLeftistHeap<T>::Inorder()
{
    InorderHelper(root);
}

template <typename T>
void MinLeftistHeap<T>::InorderHelper(LeftistNode<T>* m_rootPtr)
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
void MinLeftistHeap<T>::levelorder()
{
    levelorderHelper(root);
    cout<<""<<endl;
}

template <typename T>
void MinLeftistHeap<T>::levelorderHelper(LeftistNode<T>* m_rootPtr)
{
    Queue<LeftistNode<T>*> m;
    Queue<LeftistNode<T>*> n;

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