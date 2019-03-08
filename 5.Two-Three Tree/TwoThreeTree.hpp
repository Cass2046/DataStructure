/**
*	@file : TwoThreeTree.hpp
*	@author : Lu Yin
*	@date : Feb 19, 2018
*	@brief A method file for template 2-3Tree class
*/

#include "Node.h"
#include "TwoThreeTree.h"
#include <string>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <limits>


using namespace std;

template <typename T>
TwoThreeTree<T>::TwoThreeTree()
{
  m_root=nullptr;
}

template <typename T>
TwoThreeTree<T>::~TwoThreeTree()
{
  if (m_root!=nullptr)
  {
      DeleteMin();
  }
}

template <typename T>
void TwoThreeTree<T>::setValue(Node<T>* subTree)
{
    if (subTree!=nullptr) //not an empty tree
    {
        // subtree is interior node and its child is leaf
        if (subTree->getTag()==false && subTree->getfirstChild()->getTag()==true)
        {
            subTree->setminSecond(subTree->getsecondChild()->getItem());
            if (subTree->getthirdChild()!=nullptr)
            {
                subTree->setminThird(subTree->getfirstChild()->getItem());
            }
            else
            {
                subTree->setminThird(-1);
            }

        }
        else if (subTree->getTag()==false && subTree->getfirstChild()->getTag()==false)
        {   
            subTree->setminSecond(getLeftMost(subTree->getsecondChild())->getItem());
            if (subTree->getthirdChild()!=nullptr)
            {
                subTree->setminThird(getLeftMost(subTree->getthirdChild())->getItem());
            }
            else
            {
                
                subTree->setminThird(-1);
            }
            Node<T>* first_child=subTree->getfirstChild();
            Node<T>* second_child=subTree->getsecondChild();
            Node<T>* third_child=subTree->getthirdChild();
            
            setValue(first_child);
            
            setValue(second_child);
            
            if (third_child!=nullptr)
            {
                setValue(third_child);
            }
        }       
    }
}

template <typename T>
void TwoThreeTree<T>::setChild(Node<T>* n_parent, Node<T>* fnode, Node<T>* snode, Node<T>* tnode)
{
    if (tnode!=nullptr)
    {
        if (fnode->getminSecond() < snode->getminSecond() && fnode->getminSecond()< tnode->getminSecond() )
        {
            n_parent->setfirstChild(fnode);          //first node is the smallest
            if (snode->getminSecond() < tnode->getminSecond())
            {
                n_parent->setsecondChild(snode);
                n_parent->setthirdChild(tnode);
            }
            else
            {
                n_parent->setsecondChild(tnode);
                n_parent->setthirdChild(snode);
            }
        }
        else if (snode->getminSecond() < fnode->getminSecond() && snode->getminSecond() < tnode->getminSecond())
        {
            n_parent->setfirstChild(fnode);           //second node is the smallest
            if (fnode->getminSecond() < tnode->getminSecond())
            {
                n_parent->setsecondChild(fnode);
                n_parent->setthirdChild(tnode);
            }
            else
            {
                n_parent->setsecondChild(tnode);
                n_parent->setthirdChild(fnode);
            }
        }
        else
        {
            n_parent->setfirstChild(tnode);           //third node is the smallest
            if (fnode->getminSecond() < snode->getminSecond())
            {
                n_parent->setsecondChild(fnode);
                n_parent->setthirdChild(snode);
            }
            else
            {
                n_parent->setsecondChild(snode);
                n_parent->setthirdChild(fnode);
            }
        }
    }

    else  //no third child
    {
        if (fnode->getminSecond() < snode->getminSecond())
        {
            n_parent->setfirstChild(fnode);
            n_parent->setsecondChild(snode);
        }
        else
        {
            n_parent->setfirstChild(snode);
            n_parent->setsecondChild(fnode);
        }
    } 
}

template <typename T>
bool TwoThreeTree<T>::Insert(T value)
{
    if (Find(m_root, value)==true)
    {
        return false;
    }
    else
    {
        Node<T>* newone = new Node<T> (true, value);  //create a leaf node
        RecInsert(newone, m_root, value);
        return true;
    }
}

template <typename T>
void TwoThreeTree<T>::RecInsert(Node<T>* newNodePtr, Node<T>* subTree, T value)
{
    if(subTree==nullptr) //if the subtree is empty
    {                    //if T=null, then return T with one node
        //subTree = newNodePtr; 
        //m_root=subTree;
        m_root=newNodePtr;
    }
    else if (subTree->getTag()==true)  //if the subtree has one leaf
    {                                  
        //create a new interior node with children
        Node<T>* newInterior=new Node<T> (false, -1, -1);
        if (value > subTree->getItem())
        {
            newInterior->setminSecond(value);
            newInterior->setfirstChild(subTree);
            newInterior->setsecondChild(newNodePtr);
        }
        else
        {
            newInterior->setminSecond(subTree->getItem());
            newInterior->setfirstChild(newNodePtr);
            newInterior->setsecondChild(subTree);
        }
       
        m_root =  newInterior;
    }
    else if (subTree->getTag()==false)  //find parent N of x for insertion
    {
        //one interior node in the tree with minSecond and minThird is empty
        if (subTree->getTag()==false && subTree->getfirstChild()->getTag()==true)
        {
            if (subTree->getminThird()==-1)
            {
                if (value < getLeftMost(subTree)->getItem())
                {
                    subTree->setthirdChild(getRightMost(subTree));
                    subTree->setminSecond(getLeftMost(subTree)->getItem());
                    subTree->setminThird(getRightMost(subTree)->getItem());
                    subTree->setsecondChild(getLeftMost(subTree));
                    subTree->setfirstChild(newNodePtr);
                }
                else if (value > getLeftMost(subTree)->getItem() && value < getRightMost(subTree)->getItem())
                {
                    subTree->setminThird(getRightMost(subTree)->getItem());
                    subTree->setthirdChild(getRightMost(subTree));
                    subTree->setminSecond(value);   
                    subTree->setsecondChild(newNodePtr);
                }
                else
                {
                    subTree->setsecondChild(getRightMost(subTree));
                    subTree->setminThird(value);
                    subTree->setthirdChild(newNodePtr);
                }
                //return subTree;
            }
            else//3 children
            {
                Node<T>* RInterior=new Node<T> (false, -1, -1);  //new interior node at right
                if(value > subTree->getminThird())
                {
                    RInterior->setfirstChild(subTree->getthirdChild());
                    RInterior->setsecondChild(newNodePtr);
                    subTree->setthirdChild(nullptr);
                }
                else if (value > subTree->getminSecond() && value < subTree->getminThird())
                {
                    RInterior->setfirstChild(newNodePtr);
                    RInterior->setsecondChild(subTree->getthirdChild());
                    subTree->setthirdChild(nullptr);
                }
                else if (value < subTree->getminSecond())
                {
                    if (value < subTree->getfirstChild()->getItem())
                    {
                        RInterior->setfirstChild(subTree->getsecondChild());
                        subTree->setsecondChild(subTree->getfirstChild());
                        RInterior->setsecondChild(subTree->getthirdChild());
                        subTree->setfirstChild(newNodePtr);
                        subTree->setthirdChild(nullptr);
                    }
                    else
                    {
                        RInterior->setfirstChild(subTree->getsecondChild());
                        RInterior->setsecondChild(subTree->getthirdChild());
                        subTree->setsecondChild(newNodePtr);
                        subTree->setthirdChild(nullptr);
                    }
                }
                setValue(RInterior);
                setValue(subTree);

                if (subTree==m_root)
                {
                    Node<T>* new_root=new Node<T> (false, -1, -1); 
                    new_root->setfirstChild(subTree);
                    new_root->setsecondChild(RInterior);
                    setValue(new_root);
                    m_root = new_root;
                }
                else
                { 
                    Node<T>* P = subTree->getparent();
                    if (P->getminThird()==-1)  //no third child
                    {   
                        if (subTree == P->getfirstChild())
                        {
                            Node<T>* Pschild = P->getsecondChild();
                            setChild(P, subTree, RInterior, Pschild);
                            setValue(P);
                        }
                        else
                        {
                            Node<T>* Pfchild = P->getfirstChild();
                            setChild(P, subTree, RInterior, Pfchild);
                        }
                    }
                    else
                    {
                        //create two new interior node
                        Node<T>* L=new Node<T> (false, -1, -1);
                        Node<T>* R=new Node<T> (false, -1, -1);
                        if (subTree == P->getfirstChild())
                        {
                            L->setfirstChild(subTree);
                            L->setsecondChild(RInterior);
                            R->setfirstChild(P->getsecondChild());
                            R->setsecondChild(P->getthirdChild());
                            P->setfirstChild(L);
                            P->setsecondChild(R);
                            P->setthirdChild(nullptr);
                        }
                        else if (subTree == P->getsecondChild())
                        {
                            L->setfirstChild(P->getfirstChild());
                            L->setsecondChild(subTree);
                            R->setfirstChild(RInterior);
                            R->setsecondChild(P->getthirdChild());
                            P->setfirstChild(L);
                            P->setsecondChild(R);
                            P->setthirdChild(nullptr);
                        }
                        else //thirdchild
                        {
                            L->setfirstChild(P->getfirstChild());
                            L->setsecondChild(P->getsecondChild());
                            R->setfirstChild(subTree);
                            R->setsecondChild(RInterior);
                            P->setfirstChild(L);
                            P->setsecondChild(R);
                            P->setthirdChild(nullptr);
                        }
                        setValue(m_root);
                    }
                }
            }
        }

        //subtree is interior node and its child is also interior node
        else if (subTree->getTag()==false && subTree->getfirstChild()->getTag()==false)
        {
            if (value < subTree->getminSecond())
            {
                RecInsert(newNodePtr, subTree->getfirstChild(), value);
            }
            else if (value > subTree->getminSecond())
            {
                if (subTree->getminThird() != -1) //there is minthird
                {
                    if (value < subTree->getminThird())
                    {
                        RecInsert(newNodePtr, subTree->getsecondChild(), value);
                    }
                     else  //no minThird
                    {
                        RecInsert(newNodePtr, subTree->getthirdChild(), value);
                    }
                }
                else
                {
                    RecInsert(newNodePtr, subTree->getsecondChild(), value);
                }
            }

            else //value > minThird
            {
                RecInsert(newNodePtr, subTree->getthirdChild(), value);
            }
            ///////
            setValue(m_root);
        }
    }
}

template <typename T>
T TwoThreeTree<T>::FindMin()
{
    if (m_root == nullptr)  //empty tree
    {
        return -1;
    }
    else
    {
        return (getLeftMost(m_root)->getItem());
    }
}

template <typename T>
Node<T>* TwoThreeTree<T>::getLeftMost(Node<T>* subTreePtr)
{
    if (subTreePtr->getTag()==true)  //the leaf node
    {
        return subTreePtr;
    }
    else
    {
        Node<T>*leftmost=getLeftMost(subTreePtr->getfirstChild());
        return leftmost;
    }
}

template <typename T>
T TwoThreeTree<T>::FindMax()
{
    if (m_root == nullptr)  //empty tree
    {
        return -1;
    }
    else
    {
        return (getRightMost(m_root)->getItem());
    }
}

template <typename T>
Node<T>* TwoThreeTree<T>::getRightMost(Node<T>* subTreePtr)
{
    if (subTreePtr->getTag()==true)  //the leaf node
    {
        return subTreePtr;
    }
    else
    {
       // subTreePtr=subTreePtr->get
    
        if (subTreePtr->getthirdChild()!=nullptr)
        {
            Node<T>*rightmost=getRightMost(subTreePtr->getthirdChild());
            return rightmost;
        }
        else if (subTreePtr->getsecondChild()!=nullptr)
        {
            Node<T>*rightmost=getRightMost(subTreePtr->getsecondChild());
            return rightmost;
        }
        else// (subTreePtr->getfirstChild()!=nullptr)
        {
            Node<T>*rightmost=getRightMost(subTreePtr->getfirstChild());
            return rightmost;
        }
    }
}

template <typename T>
bool TwoThreeTree<T>::Findnum(T value)
{
    if (Find(m_root, value)==true)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

template <typename T>
bool TwoThreeTree<T>::Find(Node<T>* subTreePtr, T value)
{
    if (subTreePtr==nullptr)  //empty tree
    {
        return false; //does not exist
    }
    else if (subTreePtr->getTag()==true)
    {
        if (subTreePtr->getItem() == value)  //leaf 
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
    else //if (subTreePtr->getTag()==false)
    {
        if (value == subTreePtr->getminSecond())
        {
            return true;
        }
        else if (value == subTreePtr->getminThird())
        {
            return true;
        }
        else if (value < subTreePtr->getminSecond())
        {
            return Find(subTreePtr->getfirstChild(), value);
        }
        else
        {
            if(subTreePtr->getminThird()==-1)
            {
                return Find(subTreePtr->getsecondChild(), value);
            }
            else
            {
                if(value >= subTreePtr->getminThird())
                {
                    return Find(subTreePtr->getthirdChild(), value);
                }
                else
                {
                    return Find(subTreePtr->getsecondChild(), value);
                }
            }
        }
    }
}

template <typename T>
bool TwoThreeTree<T>::Delete(T target)
{
    if (Findnum(target)==true)
    {
        deleteValue(m_root, target);
        return true; //target can be delete
    }
    else
    {
        return false;
    }
}

template <typename T>
void TwoThreeTree<T>::deleteValue(Node<T>* subTree, T target)
{
    if (subTree->getTag()==true)  //leaf 
    {
       if (subTree==m_root)
       {
           delete subTree;
           subTree=nullptr;
           m_root = nullptr;
       }
       else 
       {
            Node<T>* P=subTree->getparent();
            if (P->getminThird()!=-1)
            {
                if (P->getthirdChild()->getItem()==target)
                {
                    P->setthirdChild(nullptr);
                    delete subTree;
                    subTree=nullptr;   
                    setValue(m_root);
                }
                else
                {
                    if (P->getsecondChild()->getItem()==target)
                    {
                        P->setsecondChild(P->getthirdChild());
                        P->setthirdChild(nullptr);
                        delete subTree;
                        subTree=nullptr;
                        setValue(m_root);
                    }
                    else
                    {
                        P->setfirstChild(P->getsecondChild());
                        P->setsecondChild(P->getthirdChild());
                        P->setthirdChild(nullptr);
                        delete subTree;
                        subTree=nullptr;
                        setValue(m_root);
                    }
                }
            }
            else if(P==m_root)//first & sec child
            {
                //only two children, delete one the other will be a leaf
                if (P->getsecondChild()->getItem()==target)
                {
                    m_root=P->getfirstChild();
                    delete subTree;
                    subTree=nullptr;
                    delete P;
                    P=nullptr;
                }
                else
                {
                    m_root=P->getsecondChild();
                    delete subTree;
                    subTree=nullptr;
                    delete P;
                    P=nullptr;
                }
            }
            else
            {
                if (P->getsecondChild()->getItem()==target)
                {
                    P->setsecondChild(nullptr);
                    delete subTree;
                    subTree=nullptr;
                }
                else
                {
                    P->setfirstChild(P->getsecondChild());
                    P->setsecondChild(nullptr);
                    delete subTree;
                    subTree=nullptr;  
                }
                Node<T>* PP=P->getparent();
                Node<T>* fc=PP->getfirstChild();
                Node<T>* sc=PP->getsecondChild();
                Node<T>* tc=PP->getthirdChild();
              
                if(PP->getminThird()!=-1)  //PP has 3 children
                {
                    if(P==tc)
                    {
                        if (sc->getminThird()==-1) //no third child
                        {
                            sc->setthirdChild(P->getfirstChild());
                            P->setfirstChild(nullptr);
                            PP->setthirdChild(nullptr);
                            delete P;
                            P=nullptr;
                        }
                        else 
                        {
                            P->setsecondChild(P->getfirstChild());
                            P->setfirstChild(sc->getthirdChild());
                            sc->setthirdChild(nullptr);
                        }

                    }
                    else if (P==sc)
                    {
                        if (fc->getminThird()==-1) //no third child
                        {
                            fc->setthirdChild(P->getfirstChild());
                            P->setfirstChild(nullptr);
                            PP->setsecondChild(PP->getthirdChild());
                            PP->setthirdChild(nullptr);
                            delete P;
                            P=nullptr;
                        }
                        else 
                        {
                            P->setsecondChild(P->getfirstChild());
                            P->setfirstChild(fc->getthirdChild());
                            fc->setthirdChild(nullptr);
                        }
                    }
                    else //p==fc
                    {
                        if (sc->getminThird()==-1)
                        {
                            sc->setthirdChild(sc->getsecondChild());
                            sc->setsecondChild(sc->getfirstChild());
                            sc->setfirstChild(P->getfirstChild());
                            
                            P->setfirstChild(nullptr);
                            PP->setfirstChild(sc);
                            PP->setsecondChild(tc);
                            PP->setthirdChild(nullptr);
                            delete P;
                            P=nullptr;
                        }
                        else
                        {
                            P->setsecondChild(sc->getfirstChild());
                            sc->setfirstChild(sc->getsecondChild());
                            sc->setsecondChild(sc->getthirdChild());
                            sc->setthirdChild(nullptr);
                        }
                    }
                    setValue(m_root);
                }
                else
                {
                    if (P==sc)
                    {
                        if (fc->getminThird()!=-1)
                        {
                            sc->setsecondChild(sc->getfirstChild());
                            sc->setfirstChild(fc->getthirdChild());
                            fc->setthirdChild(nullptr);
                        }
                        else //no third
                        {
                            fc->setthirdChild(P->getfirstChild());
                            P->setfirstChild(nullptr);
                            PP->setsecondChild(nullptr);
                            delete P;
                            P=nullptr; //PP=root?
                        }
                    }
                    else //p=fc
                    {
                        if (sc->getminThird()!=-1)
                        {
                            fc->setsecondChild(sc->getfirstChild());
                            sc->setfirstChild(sc->getsecondChild());
                            sc->setsecondChild(sc->getthirdChild());
                            sc->setthirdChild(nullptr);
                        }
                        else //no third
                        {
                            
                            sc->setthirdChild(sc->getsecondChild());
                            sc->setsecondChild(sc->getfirstChild());
                            sc->setfirstChild(fc->getfirstChild());
                            fc->setfirstChild(nullptr);
                            PP->setfirstChild(sc);
                            PP->setsecondChild(nullptr);
                            delete P;
                            P=nullptr;
                        }
                    }
                    //while
                    if (PP->getsecondChild()==nullptr)
                    {
                        if (PP==m_root)
                        {
                            m_root=PP->getfirstChild();
                            PP->setfirstChild(nullptr);
                            delete PP;
                        }

                    }
         
                    setValue(m_root);
           
                }
            }
       }
    }
    else  //interior node
    {
        if (target < subTree->getminSecond())
        {
            deleteValue(subTree->getfirstChild(), target);
        }
        else  //whether there is minthird
        {
            if (subTree->getminThird()==-1) //no third child
            {
                if (target >= subTree->getminSecond())
                {
                    deleteValue(subTree->getsecondChild(), target);
                }
            }
            else  
            {
                if (target >= subTree->getminSecond() && target < subTree->getminThird())
                {
                    deleteValue(subTree->getsecondChild(), target);
                }
                else if (target >= subTree->getminThird())
                {
                    deleteValue(subTree->getthirdChild(), target);
                }
            }
        }
    }
}

template <typename T>
void TwoThreeTree<T>::levelOrder(Node<T>* subTreePtr)
{
    if (subTreePtr->getTag() != true)
    {   
        if (subTreePtr->getfirstChild()!=nullptr)
        {
           
            levelOrder(subTreePtr->getfirstChild());
        }
        
        if (subTreePtr->getsecondChild()!=nullptr)
        {
           
            levelOrder(subTreePtr->getsecondChild());
        }
        
        if (subTreePtr->getthirdChild()!=nullptr)
        {
            levelOrder(subTreePtr->getthirdChild());
        }

    }
    else
    {
        cout<<subTreePtr->getItem()<<" ";
    }
}

template <typename T>
void TwoThreeTree<T>::levelOrderTraverse()
{
    if(m_root!=nullptr)
    {
        levelOrder(m_root);
        cout<<""<<endl;
    }
    else
    {
        cout<<"Empty. "<<endl;
    }
}

template <typename T>
bool TwoThreeTree<T>::DeleteMin()
{
    if (m_root==nullptr)
    {
        return false;
    }
    else
    {
        Delete(FindMin());
    }
}

    
template <typename T>
bool TwoThreeTree<T>::DeleteMax()
{
    if (m_root==nullptr)
    {
        return false;
    }
    else
    {
        Delete(FindMax());
    }   
}
