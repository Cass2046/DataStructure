/**
*	@file : BinaryNode.h
*	@author :Lu Yin
*	@date : Feb 12, 2018
*	@brief: A header file for template BinaryNode class
*           Models a single tree node: to hold a data entry,
*           left and right sub-trees. 
*/

#ifndef BINARYNODE_H
#define BINARYNODE_H

template<typename T>
class BinaryNode
{
    public:

    BinaryNode();

    ~BinaryNode();

    /** @pre the value is node T.
    *   @post create a single tree node.
    *   @return none.
    */
    BinaryNode(const T& value);

    /** @pre the value is tree node.
    *   @post set the tree node with two subtrees.
    *   @return none.
    */
    BinaryNode(const T& value,
               BinaryNode<T>* leftChildPtr,
               BinaryNode<T>* rightChildPtr);
    
    /** @pre the value is vaild tree node.
    *   @post none.
    *   @return true if it is a leaf, otherwise return false.
    */
    bool isLeaf() const;

    /** @pre the value is vaild tree node.
    *   @post set the value to the node.
    *   @return none.
    */
    void setItem(const T& value);

    /** @pre the value is vaild binary node.
    *   @post get the value from the node.
    *   @return the value.
    */
    T getItem() const;

    /** @pre the value is vaild tree node.
    *   @post set a pointer points to the left subtree.
    *   @return none.
    */
    void setleftPtr(BinaryNode<T>* leftChildPtr);

    /** @pre the value is vaild tree node.
    *   @post set pointer points to the right subtree
    *   @return none.
    */
    void setrightPtr(BinaryNode<T>* rightChildPtr);

    /** @pre the value is vaild tree node.
    *   @post none.
    *   @return the value of the left subtree node.
    */
    BinaryNode<T>* getleftChildPtr() const;

    /** @pre the value is vaild tree node.
    *   @post none.
    *   @return the value of the right subtree node.
    */
    BinaryNode<T>* getrightChildPtr() const;

   

    private:
    T Item;
    BinaryNode<T>* leftPtr;   // Pointer to left child
    BinaryNode<T>* rightPtr;  // Pointer to right child

};

#include "BinaryNode.hpp"
#endif

