/**
*	@file : SkewNode.hpp
*	@author : Lu Yin
*	@date : April 16, 2018
*/

#ifndef SKEWNODE_H
#define SKEWNODE_H

template <typename T>
class SkewNode
{
    public:
    //constructor
    SkewNode(T s_value);
    //donstructor
    ~SkewNode();
    
    /** @pre the value is T.
    *   @post set value.
    *   @return none.
    */
    void setValue(T s_value);

    /** @pre the value is T.
    *   @post none.
    *   @return the value of the node.
    */
    T getValue();

    /** @pre the value is T.
    *   @post set leftchild of the node.
    *   @return none.
    */
    void setLeftChild(SkewNode<T>* s_leftchild);

    /** @pre the value is T.
    *   @post none.
    *   @return the leftchild of the node.
    */
    SkewNode<T>* getLeftChild();

    /** @pre the value is T.
    *   @post set rightchild of the node.
    *   @return none.
    */
    void setRightChild(SkewNode<T>* s_rightchild);

    /** @pre the value is T.
    *   @post none.
    *   @return the rightchild of the node.
    */
    SkewNode<T>* getRightChild();

    private:
    T value;
    SkewNode<T>* leftchild;
    SkewNode<T>* rightchild;

};
#include "SkewNode.hpp"
#endif

