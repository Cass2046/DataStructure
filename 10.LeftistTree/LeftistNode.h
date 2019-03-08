/**
*	@file : LeftistNode.h
*	@author : Lu Yin
*	@date : April 16, 2018
*/
#ifndef LEFTISTNODE_H
#define LEFTISTNODE_H

template <typename T>
class LeftistNode
{
  public:
    //constructor
    LeftistNode(T t_value);
    //donstructor
    ~LeftistNode();
    
    /** @pre the value is T.
    *   @post set value.
    *   @return none.
    */
    void setValue(T t_value);

    /** @pre the value is T.
    *   @post none.
    *   @return the value of the node.
    */
    T getValue();

    /** @pre the value is T.
    *   @post set leftchild of the node.
    *   @return none.
    */
    void setLeftChild(LeftistNode<T>* t_leftchild);

    /** @pre the value is T.
    *   @post none.
    *   @return the leftchild of the node.
    */
    LeftistNode<T>* getLeftChild();

    /** @pre the value is T.
    *   @post set rightchild of the node.
    *   @return none.
    */
    void setRightChild(LeftistNode<T>* t_rightchild);

    /** @pre the value is T.
    *   @post none.
    *   @return the rightchild of the node.
    */
   LeftistNode<T>* getRightChild();

    /** @pre the value is T.
    *   @post set rank of the node.
    *   @return none.
    */
    void setRank(int t_rank);

    /** @pre the value is T.
    *   @post none.
    *   @return the rank of the node.
    */
    T getRank();
   
    private:
    T value;
    int rank;
    LeftistNode<T>* leftchild;  
    LeftistNode<T>* rightchild;  


  };
  #include "LeftistNode.hpp"
  #endif
