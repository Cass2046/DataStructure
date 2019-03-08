/**
*	@file : BST.hpp
*	@author : Lu Yin
*	@date : Feb 12, 2018
*	@brief A method file for template BST class
*/


#include <string>
#include <iostream>

using namespace std;

template <typename ItemType>
BST<ItemType>::BST()
{
  m_root=nullptr;
}

template <typename ItemType>
BST<ItemType>::~BST()
{
  this->destroyTree(m_root);
}

//check if the item has no children
template <typename ItemType>
bool BST<ItemType>::isLeaf(BinaryNode<ItemType>* subtree)
{
  if(subtree->getleftChildPtr()==nullptr && subtree->getrightChildPtr()==nullptr)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//Returns a pointer to the node containing the given value
template<typename ItemType>
BinaryNode<ItemType>* BST<ItemType>::FindNode(BinaryNode<ItemType>* subTreePtr, int target)
{
    if(subTreePtr==nullptr) //check if its empty tree or it is not found
    {
        return nullptr;
    }
    else if(subTreePtr->getItem() == target)  //check the root
    {
        return subTreePtr;
    }
    else if(subTreePtr->getItem() > target)  //less value goes to left.
    {
        return FindNode(subTreePtr->getleftChildPtr(),target);
    }
    else                                              //greater value goes to right.
    {
        return FindNode(subTreePtr->getrightChildPtr(),target);
    }
}

//Searches the binary search tree for a given target value.
template <typename ItemType>
bool BST<ItemType>::Search(int target)
{
  if(FindNode(m_root, target) == nullptr)
    {
        return false;
    }
    else
    {   
        return true;    
    }
}

//Inserts newEntry into this binary search tree.
template <typename ItemType>
void BST<ItemType>::Insert(int value)   //throw (NotFoundException)
{
   BinaryNode<ItemType>* newPtr = new BinaryNode<ItemType> (value);
   m_root = RecInsert(newPtr, m_root);
}

//use Recursive function to add value in tree
template <typename ItemType>
BinaryNode<ItemType>* BST<ItemType>::RecInsert(BinaryNode<ItemType>* newNodePtr, BinaryNode<ItemType>* subTreePtr)
{
  if(m_root == nullptr)
    {
        return newNodePtr;
    }
    else 
    {
        if((newNodePtr->getItem()) < (subTreePtr->getItem()))
        {
            if (subTreePtr->getleftChildPtr() == nullptr)
            {
                subTreePtr->setleftPtr(newNodePtr);
                return subTreePtr;
            }
            else
            {
                BinaryNode<ItemType>* leftPtr = subTreePtr->getleftChildPtr();
                leftPtr=RecInsert(newNodePtr, leftPtr);
            }   
        }
        else 
        {
            if (subTreePtr->getrightChildPtr() == nullptr)
            {
                subTreePtr->setrightPtr(newNodePtr);
                return subTreePtr;
            }
            else
            {
                BinaryNode<ItemType>* rightPtr = subTreePtr->getrightChildPtr();
                rightPtr=RecInsert(newNodePtr, rightPtr);
            }
        }
        return subTreePtr;
    }
}

//Removes the given entry from this binary search tree
template <typename ItemType>
bool BST<ItemType>::Delete(ItemType target)
{
  if(Search(target) == true)                  //check if the target is exist
    {
        m_root=removeValue(m_root, target);  //call removeValue method
        return true;
    }
    else
    {
        return false;
    }
}

//remove the target Value from a subtree
template<typename ItemType>
BinaryNode<ItemType>* BST<ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr, ItemType target)
{
  if(subTreePtr==nullptr)
    {
        return nullptr;
    }
    else if(subTreePtr->getItem() == target)
    {
        subTreePtr = removeNode(subTreePtr);       //call removeNode method to remove the node with target
        return subTreePtr;
    }
    else if(subTreePtr->getItem() > target)
    {
        BinaryNode<ItemType>* temp = removeValue(subTreePtr->getleftChildPtr(), target);
		////
        subTreePtr->setleftPtr(temp);
        return subTreePtr;
    }
    else
    {
  
        BinaryNode<ItemType>* temp = removeValue(subTreePtr->getrightChildPtr(), target);
        subTreePtr->setrightPtr(temp);
        return subTreePtr;
    }
}

//remove the node which have target value
template<typename ItemType>
BinaryNode<ItemType>* BST<ItemType>::removeNode(BinaryNode<ItemType>* nodePtr)
{
  if(nodePtr->isLeaf())
    {
        delete nodePtr;  //remove the node
        nodePtr=nullptr;
        return nodePtr;
    }
    else if((nodePtr->getleftChildPtr()==nullptr || nodePtr->getrightChildPtr()==nullptr) && !nodePtr->isLeaf())
    {
        BinaryNode<ItemType>* nodeconnectPtr;//create a connector pointer
        if(nodePtr->getleftChildPtr()!=nullptr)
        {
            nodeconnectPtr=nodePtr->getleftChildPtr();
        }
        else
        {
            nodeconnectPtr=nodePtr->getrightChildPtr();
        }
        delete nodePtr;
        nodePtr = nullptr;
        return nodeconnectPtr;
    }
    else
    {
        ItemType newValue;
        BinaryNode<ItemType>* temp = removeLeftmostNode(nodePtr->getrightChildPtr(), newValue);
        nodePtr->setrightPtr(temp);
        nodePtr->setItem(newValue);
        return nodePtr;
    }
}

//switch node.
template<typename ItemType>
BinaryNode<ItemType>* BST<ItemType>::removeLeftmostNode(BinaryNode<ItemType>* nodePtr, ItemType& value)
{
    if(nodePtr->getleftChildPtr()==nullptr)
    {
        value = nodePtr->getItem();
        return removeNode(nodePtr);        
    }
    else
    {
		BinaryNode<ItemType>* newnode = removeLeftmostNode(nodePtr->getleftChildPtr(), value);
		nodePtr->setleftPtr(newnode);
		return nodePtr;
	}
}

template <typename ItemType>
BinaryNode<ItemType>* BST<ItemType>::DeleteMin()
{
    if (m_root != nullptr)   //an empty tree
    {
        BinaryNode<ItemType>* subtree = getLeftMost(m_root);
        Delete(subtree->getItem());
        return m_root;
    }
    else
    {
        return nullptr;
    }
}

template <typename ItemType>
BinaryNode<ItemType>* BST<ItemType>::DeleteMax()
{
    if (m_root != nullptr)   //an empty tree
    {
        BinaryNode<ItemType>* subtree = getRightMost(m_root);
        Delete(subtree->getItem());
        return m_root;
    }
    else
    {
        return nullptr;
    }
}

template <typename ItemType>
BinaryNode<ItemType>* BST<ItemType>::getLeftMost(BinaryNode<ItemType>* subTreePtr)
{
    if (subTreePtr->getleftChildPtr() != nullptr)
    {
        BinaryNode<ItemType>*leftMost = getLeftMost(subTreePtr->getleftChildPtr());
        return leftMost;
    }
    else
    {
        return subTreePtr;
    }
}

template <typename ItemType>
BinaryNode<ItemType>* BST<ItemType>::FindMin()
{  
    if (m_root != nullptr)
    {
        return getLeftMost(m_root);
    }
    else
    {
        return nullptr;
    }
}

template <typename ItemType>
BinaryNode<ItemType>* BST<ItemType>::getRightMost(BinaryNode<ItemType>* subTreePtr)
{
    if (subTreePtr->getrightChildPtr() != nullptr)
    {
        BinaryNode<ItemType>*rightMost = getRightMost(subTreePtr->getrightChildPtr());
        return rightMost;
    }
    else
    {
        return subTreePtr;
    }
}
template <typename ItemType>
BinaryNode<ItemType>* BST<ItemType>::FindMax()
{
    if (m_root != nullptr)
    {
        return getRightMost(m_root);
    }
    else
    {
        return nullptr;
    }
}

//
//Traversals Functions
//
template<typename ItemType>
void BST<ItemType>::InorderTraverse() 
{
    inorder(m_root);
}

template<typename ItemType>
void BST<ItemType>::PreorderTraverse() 
{
    preorder(m_root);
}

template<typename ItemType>
void BST<ItemType>::PostorderTraverse() 
{
    postorder(m_root);
}


//
//Private
//
// Recursively deletes all nodes from the tree.
template <typename ItemType>
void BST<ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr)
{
     //if (subTreePtr!= nullptr)
	 //{
      ///    destroyTree(subTreePtr->getleftChildPtr());//destroy the left subtree
       //   destroyTree(subTreePtr->getrightChildPtr());//destroy the right subtree
       ///   delete subTreePtr;
		//  subTreePtr = nullptr;
      // }
	  while(m_root!=nullptr)
	  {
		  DeleteMax();
	  }
}

template<typename ItemType>
void BST<ItemType>::inorder(BinaryNode<ItemType>* treePtr) const 
{
    if (treePtr != nullptr)
   {
      inorder(treePtr->getleftChildPtr());
      cout<<treePtr->getItem()<<" ";
      inorder(treePtr->getrightChildPtr());
   }
   else
   {
       //cout<<"."<<endl;
   }
}

template<typename ItemType>
void BST<ItemType>::preorder(BinaryNode<ItemType>* treePtr) const 
{
    if (treePtr != nullptr)
   {
      cout<<treePtr->getItem()<<" ";
      preorder(treePtr->getleftChildPtr());//call preorder method
      preorder(treePtr->getrightChildPtr());//call preorder method
   }
   else
   {
       //cout<<"."<<endl;
   }
}

template<typename ItemType>
void BST<ItemType>::postorder(BinaryNode<ItemType>* treePtr) const 
{
    if (treePtr->getleftChildPtr()!= nullptr)
    {
      postorder(treePtr->getleftChildPtr()); //call postorder method
    }

    if (treePtr->getrightChildPtr()!= nullptr)
    {
      postorder(treePtr->getrightChildPtr()); //call postorder method
    }
     cout<<treePtr->getItem()<<" ";
}
