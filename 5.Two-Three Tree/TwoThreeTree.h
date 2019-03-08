/**
*	@file : TwoThreeTree.h
*	@author : Lu Yin
*	@date : Feb 19, 2018
*	@brief A header file for template 2-3Tree class
*/

#ifndef TWOTHREETREE_H
#define TWOTHREETREE_H

#include "Node.h"

template <typename T>
class TwoThreeTree
{
    public:
    TwoThreeTree();
    ~TwoThreeTree();

    /** @pre the value is vaild tree node.
    *   @post help func that set the minimum node for each interior node.
    *   @return none.
    */
    void setValue(Node<T>* subTree);

    /** @pre the value is vaild tree node.
    *   @post help func that split interior and set children.
    *   @return none.
    */
    void setChild(Node<T>* n_parent, Node<T>* fnode, Node<T>* snode, Node<T>* tnode);

    /** @pre the value is vaild tree node.
    *   @post add a new 2-3 tree node.
    *   @return none.
    */
    bool Insert(T value);

    /** @pre the value is vaild tree node.
    *   @post none.
    *   @return the new subtree.
    */
    void RecInsert(Node<T>* newNodePtr, Node<T>* subTreePtr, T value);

    // /** @pre the value are two T value.
    // *   @post switch two elements which help with insertion function.
    // *   @return none.
    // */
    // T Switch(T num1, T num2);

    /** @pre none.
    *   @post delete the minimum node in the 2-3Tree
    *   @return the new subtree.
    */
    bool DeleteMin();

    /** @pre none.
    *   @post delete the maximum node in the 2-3Tree
    *   @return the new subtree.
    */
    bool DeleteMax();

    /** @pre none.
    *   @post call the find help func
    *   @return the value of the element.
    */
    T FindMin();

    /** @pre none.
    *   @post find the minimum node in the 2-3 Tree.
    *   @return the value of the element.
    */
    Node<T>* getLeftMost(Node<T>* subTreePtr);
    
    /** @pre none.
    *   @post find the maximum node in the 2-3 Tree.
    *   @return the value of the element.
    */
    T FindMax();

    /** @pre none.
    *   @post help to find the minimum node in the 2-3 Tree.
    *   @return the value of the element.
    */
    Node<T>* getRightMost(Node<T>* subTreePtr);

    /** @pre the value is vaild T target.
    *   @post call the find function.
    *   @return if the item exist, otherwise return false.
    */
    bool Findnum(T value);

    /** @pre the value is vaild T target.
    *   @post none.
    *   @return true if the item exist, otherwise return false.
    */
    bool Find(Node<T>* subTreePtr, T value);
    
    /** @pre the value is vaild Key value.
    *   @post none.
    *   @return true if it removed, otherwise return false.
    */
    bool Delete(T target);

    /** @pre the value is vaild tree node with its value.
    *   @post none.
    *   @return the new subtree.
    */
    void deleteValue(Node<T>* subTree, T target);

    /** @pre none.
    *   @post level traversal
    *   @return none.
    */
    void levelOrder(Node<T>* subTreePtr);

    /** @pre none.
    *   @post help with levelOrder get the root.
    *   @return none.
    */
    void levelOrderTraverse();




    private:
    /** @pre none.
    *   @post create a new node for the parent of the tree
    *   @return none.
    */
    Node<T>*  m_root;

    /** @pre none.
    *   @post Recursively deletes all nodes from the tree
    *   @return none.
    */
    void destroyTree(Node<T>* subTreePtr);
   
    /** @pre none.
    *   @post help with levelorder traversal
    *   @return none.
    */
   void lorder(Node<T>* treePtr) const;
};
#include "TwoThreeTree.hpp"
#endif