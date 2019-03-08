/**
*	@file : Node.h
*	@author : Lu Yin
*	@date : Feb 19, 2018
*	@brief A header file for template Node class
*/

#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
  public:
  /** @pre the value is 2-3 node.
  *   @post create a 2-3 tree interior (tag=0) which has minSecond&minThird.
  *   @return none.
  */
  Node(bool tag, int minSecond, int minThird);

  /** @pre the value is 2-3 node.
  *   @post create a 2-3 tree leaf node (tag=1) which stores the item.
  *   @return none.
  */
  Node(bool tag, int item);

  Node();
  ~Node();

  /** @pre the value is bool tag.
  *   @post if it is leaf node set to true, otherwise set to false.
  *   @return none.
  */
  void setTag(bool tag);

  /** @pre the value is bool tag.
  *   @post none.
  *   @return if it is leaf node return true, otherwise return false.
  */
  bool getTag();

  /** @pre the value is T.
  *   @post set value to leaf node.
  *   @return none.
  */
  void setItem(int value);

  /** @pre the value is T.
  *   @post none.
  *   @return the value of element.
  */
  T getItem();

  /** @pre the value is T.
  *   @post set minSecond value for interior node.
  *   @return none.
  */
  void setminSecond(T minSecond);

  /** @pre the value is T.
  *   @post none.
  *   @return the value.
  */
  T getminSecond();

  /** @pre the value is T.
  *   @post set minThird value for interior node.
  *   @return none.
  */
  void setminThird(T minThird);

  /** @pre the value is T.
  *   @post none.
  *   @return the value.
  */
  T getminThird();

  /** @pre the value is pointer.
  *   @post set parent pointer for interior node.
  *   @return none.
  */
  void setparent(Node<T>* parent);

  /** @pre the value is a pointer.
  *   @post none.
  *   @return the parent pointer.
  */
  Node<T>* getparent();

  /** @pre the value T.
  *   @post set first child pointer for interior node.
  *   @return none.
  */
  void setfirstChild(Node<T>* firstChild);

  /** @pre the value is bool tag.
  *   @post none.
  *   @return the firstchild pointer.
  */
  Node<T>* getfirstChild();

  /** @pre the value T.
  *   @post set second child pointer for interior node.
  *   @return none.
  */
  void setsecondChild(Node<T>* secondChild);

  /** @pre the value is bool tag.
  *   @post none.
  *   @return the second child pointer.
  */
  Node<T>* getsecondChild();

  /** @pre the value T.
  *   @post set third child pointer for interior node.
  *   @return none.
  */
  void setthirdChild(Node<T>* thirdChild);

  /** @pre the value is bool tag.
  *   @post none.
  *   @return the third child pointer.
  */
  Node<T>* getthirdChild();

  private:

  bool tag_leaf;  //flag
  
  //leaf node
  int key;        //leaf node key value

  //interior node
  Node<T>* first; //Pointer to first subtree
  Node<T>* second; //Pointer to second subtree
  Node<T>* third; //Pointer to third subtree
  Node<T>* interior_parent; //Pointer to parent
  T m_minSecond;
  T m_minThird;
  
};

#include "Node.hpp"
#endif


