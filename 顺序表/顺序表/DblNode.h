#pragma once
#ifndef _DBLNODE_H
#define _DBLNODE_H
template<typename T>
class DblNode
{
	friend class DblList;
public:
	T data;
	DblNode<T> *lLink, *rLink;
	DblNode(DblNode<T> * left = nullptr, DblNode<T> * right = nullptr) :lLink(left), rLink(right){}
	DblNode(T value, DblNode<T> * left = nullptr, DblNode<T> * right = nullptr) :data(value), lLink(left), rLink(right){}
};
#endif // !_DBLNODE_H
