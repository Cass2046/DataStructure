/**
*	@file : SkewNode.h
*	@author : Lu Yin
*	@date : April 16, 2018
*/
//constructor
template <typename T>
SkewNode<T>::SkewNode(T s_value)  
{
  value=s_value;
  leftchild=nullptr;
  rightchild=nullptr;
}

//destructor
template <typename T>
SkewNode<T>::~SkewNode()  
{

}

template <typename T>
void SkewNode<T>::setValue(T s_value)  
{
  value = s_value;
}


template <typename T>
T SkewNode<T>::getValue()  
{
  return value;
}

template <typename T>
void SkewNode<T>::setLeftChild(SkewNode<T>* s_leftchild) 
{
  leftchild = s_leftchild;
}

template <typename T>
SkewNode<T>* SkewNode<T>::getLeftChild()
{
  return leftchild;
}

template <typename T>
void SkewNode<T>::setRightChild(SkewNode<T>* s_rightchild) 
{
  rightchild = s_rightchild;
}

template <typename T>
SkewNode<T>* SkewNode<T>::getRightChild()
{
  return rightchild;
}
