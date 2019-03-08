/**
*	@file : BST.h
*	@author : Lu Yin
*	@date : Feb 12, 2018
*	@brief A header file for template BST class
*   Models the collection of data, holding data, in multiple BinaryNodes.
*/

#ifndef BST_H
#define BST_H

#include "BinaryNode.h"
using namespace std;

template <typename ItemType>
class BST
{
    public:

    BST();
 
    ~BST();
       
    /** @pre the value is vaild tree node.
    *   @post none.
    *   @return true if it has no children, otherwise return false.
    */
    bool isLeaf(BinaryNode<ItemType>* subtree);

   /** @pre the value is vaild tree node.
    *   @post none.
    *   @return if the given value is found, 
        return a pointer to the node, otherwise nullptr.
    */
   BinaryNode<ItemType>* FindNode(BinaryNode<ItemType>* subTreePtr, int target);

    /** @pre the value is vaild KeyType target.
    *   @post none.
    *   @return true if the item exist, otherwise return false.
    */
    bool Search(int target);

    /** @pre the value is vaild tree node.
    *   @post add a new tree node.
    *   @return none.
    */
    void Insert(int value); // throw(NotFoundException);

    /** @pre the value is vaild tree node.
    *   @post none.
    *   @return the new subtree.
    */
    BinaryNode<ItemType>* RecInsert(BinaryNode<ItemType>* newNodePtr, BinaryNode<ItemType>* subTreePtr);
    


    /** @pre the value is vaild KeyType value.
    *   @post none.
    *   @return true if it removed, otherwise return false.
    */
    bool Delete(ItemType target);

    /** @pre the value is vaild tree node with its value.
    *   @post none.
    *   @return the new subtree.
    */
    BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr, ItemType target);

    /** @pre the value is vaild tree node with its value.
    *   @post remove the node which have target value and link them up
    *   @return the new subtree.
    */
   BinaryNode<ItemType>* removeNode(BinaryNode<ItemType>* nodePtr);

   /** @pre the value is vaild tree node with its value.
    *   @post remove the node which is at the left most
    *   @return the new subtree.
    */
   BinaryNode<ItemType>* removeLeftmostNode(BinaryNode<ItemType>* nodePtr, ItemType& value);

    /** @pre none.
    *   @post delete the minimum node in the BST
    *   @return the new subtree.
    */
    BinaryNode<ItemType>* DeleteMin();

    /** @pre none.
    *   @post delete the maximum node in the BST.
    *   @return the new subtree.
    */
    BinaryNode<ItemType>* DeleteMax();
    

    /** @pre none.
    *   @post recursive find the left most node in the BST.
    *   @return the value of the element.
    */
    BinaryNode<ItemType>* getLeftMost(BinaryNode<ItemType>* subTreePtr);
    /** @pre none.
    *   @post find the minimum node in the BST.
    *   @return the value of the element.
    */
    BinaryNode<ItemType>* FindMin();

    /** @pre none.
    *   @post recursive find the right most node in the BST.
    *   @return the value of the element.
    */
    BinaryNode<ItemType>* getRightMost(BinaryNode<ItemType>* subTreePtr);
     /** @pre none.
    *   @post find the maximum node in the BST.
    *   @return the value of the element.
    */
    BinaryNode<ItemType>* FindMax();

    /** @pre none.
    *   @post inorder traversal
    *   @return none.
    */
    void InorderTraverse();

    /** @pre none.
    *   @post preorder traversal
    *   @return none.
    */
    void PreorderTraverse();
       
    /** @pre none.
    *   @post postorder traversal
    *   @return none.
    */
    void PostorderTraverse();


//     private:

    /** @pre none.
    *   @post create a new node for the parent of the tree
    *   @return none.
    */
    BinaryNode<ItemType>*  m_root;

    /** @pre none.
    *   @post Recursively deletes all nodes from the tree
    *   @return none.
    */
    void destroyTree(BinaryNode<ItemType>* subTreePtr);

    /** @pre none.
    *   @post help with inorder traversal
    *   @return none.
    */
   void inorder(BinaryNode<ItemType>* treePtr) const;
   
    /** @pre none.
    *   @post help with oreorder traversal
    *   @return none.
    */
   void preorder(BinaryNode<ItemType>* treePtr) const;
   
    /** @pre none.
    *   @post help with postorder traversal
    *   @return none.
    */
   void postorder(BinaryNode<ItemType>* treePtr) const;

};
#include "BST.hpp"
#endif

//change ItemType& to BST<ItemType, KeyType>&