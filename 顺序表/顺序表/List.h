#ifndef _LIST_H
#define _LIST_H
#include"LinkNode.h"
template<typename T>
class List :public LinearList<T>
{
public:
	List() { first = new LinkNode<T>; }      //构造函数
	List(const T& x) { first = new LinkNode<T>(x); }   //构造函数
	List(List<T>& L);     //复制构造函数
	~List() { makeEmpty(); }    //析构函数
	void makeEmpty();     //将链表置为空表
	int Length() const;    //计算链表的长度
	LinkNode<T> *getHead() const { return first; }     //返回附加头结点地址
	LinkNode<T> *Search(T x);           //搜索含数据x的元素
	LinkNode<T> *Locate(int i);        //搜索第i个元素的地址
	bool getData(int i, T& x) const;           //取出第i个元素的值
	void setData(int i, T& x);                 //用x修改第i个元素的值
	bool Insert(int i, T& x);                     //在第i个元素后插入x
	bool Remove(int i, T& x);                  //删除第i个元素，x返回该元素的值
	bool IsEmpty(int i, T& x) const{return first->link == nullptr ? true : false;} //判断表是否为空，
	bool IsFull(int i, T& x)const { return false; }   //???判断表是否为满
	//void Sort(); 
	void inputFront(T endTag);          //前插输入
	void inputRear(T endTag);           //后插输入
	void output();             //输出
	List<T>& operator=(List<T>& L);      //重载函数：赋值
protected:
	LinkNode<T> * first;  //链表头指针
};
//复制构造函数
template<typename T>
List<T>::List(List<T>& L)
{
	T value;
	LinkNode<T> *srcptr = L.getHead();
	LinkNode<T> *destptr = first = new LinkNode<T>;
	while (srcptr->link)
	{
		value = srcptr->link->data;
		destptr->link = new LinkNode<T>(value);
		destptr = destptr->link;
		srcptr = srcptr->link;
	}
}
//将链表置为空表
template<typename T>
void List<T>::makeEmpty()
{
	LinkNode<T> * q;
	while (first->link)
	{
		q = first->link;
		first->link = q->link;
		delete q;
	}
}
//计算附加头结点的单链表的长度
template<typename T>
int List<T>::Length() const
{
	LinkNode<T> *p = first->link;
	int count = 0;
	while (p)
	{
		p = p->link; ++count;
	}
	return count;
}
//在表中搜索含数据x的结点，搜索成功时函数返回该结点地址；否则返回NULL值
template<typename T>
LinkNode<T> *List<T>::Search(T x)
{
	LinkNode<T> *corrent = first->link;
	while (corrent)
	{
		if (corrent->data == x)
			break;
		else corrent = corrent->link;
	}
	return corrent;
}
//定位函数，返回表中第i个元素的地址。若i<=0或i超出表中结点个数，则返回NULL
template<typename T>
LinkNode<T>* List<T>::Locate(int i)
{
	if (i <= 0)
		return nullptr;
	LinkNode<T> * current = first;
	int k = 0;
	while (current&&k < i)
	{
		current = current->link;
		++k;
	}
	return current;   //返回第i个结点地址，若返回NULL，表示i值太大
}
//取出链表中第i个元素的值
template<typename T>
bool List<T>::getData(int i,T& x) const 
{
	if (i <= 0)
		return nullptr;
	LinkNode<T> *current = Locate(i);
	if (current)
		return false;
	else
	{
		x = current->data;
		return true;
	}
}
//给链表中的第i个元素赋值
template<typename T>
void List<T>::setData(int i, T& x)
{
	if (i <= 0)
		return;
	LinkNode<T> *current = Locate(i);
	if (current)
		return;
	else current->data = x;
}
//将新元素x插入在链表中第i个结点之后
template<typename T>
bool List<T>::Insert(int i, T& x)
{
	LinkNode<T> * current = Locate(i);
	if (current)
		return false;
	LinkNode<T> *newNode = new LinkNode<T>(x);
}
//将链表中的第i个元素删去，通过引用型参数x返回该元素的值
template<typename T>
bool List<T>::Remove(int i,T& x)
{
	LinkNode<T>* current = Locate(i - 1);
	if (current == nullptr || current->link == nullptr)
		return false;
	LinkNode<T>* del = current->link;
	current->link = del->link;
	x = del->data;
	delete del;
}
//单链表输出函数
template<typename T>
void List<T>::output()
{
	LinkNode<T> *current = first->link;
	while (current)
	{
		cout << current->data << endl;
		current = current->link;
	}
}
template<typename T>
List<T>& List<T>::operator=(List<T>& L)
{
	T value;
	LinkNode<T> *srcptr = L.getHead();
	LinkNode<T> *desptr = first = new LinkNode<T>;
	while (srcptr->link)
	{
		value = srcptr->link->data;
		desptr->link = new LinkNode<T>(value);
		desptr = desptr->link;
		srcptr = srcptr->link;
	}
	desptr->link = nullptr;
	return *this;
}
//前插法建立单链表
template<typename T>
void List<T>::inputFront(T endTag)
{
	LinkNode<T> *newNode;
	T val;
	makeEmpty();
	cin >> val;
	while (val != endTag)
	{
		newNode = new LinkNode<T>(val);
		if (newNode == nullptr)
		{
			cerr << "存储分配错误" << endl; exit(1);
		}
		newNode->link = first->link;
		first->link = newNode;
		cin >> val;
	}
}
//后插法建立单链表
template<typename T>
void List<T>::inputRear(T endTag)
{
	LinkNode<T> *newNode ,*last;
	T val;
	makeEmpty();
	cin >> val;
	last = first;
	while (val != endTag)
	{
		newNode = new LinkNode<T>(val);
		if (newNode == nullptr)
		{
			cerr << "存储分配错误" << endl; exit(1);
		}
		last->link = newNode->link;
		last = newNode;
		cin >> val;
	}
}
#endif
