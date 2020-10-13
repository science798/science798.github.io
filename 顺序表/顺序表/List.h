#ifndef _LIST_H
#define _LIST_H
#include"LinkNode.h"
template<typename T>
class List :public LinearList<T>
{
public:
	List() { first = new LinkNode<T>; }      //���캯��
	List(const T& x) { first = new LinkNode<T>(x); }   //���캯��
	List(List<T>& L);     //���ƹ��캯��
	~List() { makeEmpty(); }    //��������
	void makeEmpty();     //��������Ϊ�ձ�
	int Length() const;    //��������ĳ���
	LinkNode<T> *getHead() const { return first; }     //���ظ���ͷ����ַ
	LinkNode<T> *Search(T x);           //����������x��Ԫ��
	LinkNode<T> *Locate(int i);        //������i��Ԫ�صĵ�ַ
	bool getData(int i, T& x) const;           //ȡ����i��Ԫ�ص�ֵ
	void setData(int i, T& x);                 //��x�޸ĵ�i��Ԫ�ص�ֵ
	bool Insert(int i, T& x);                     //�ڵ�i��Ԫ�غ����x
	bool Remove(int i, T& x);                  //ɾ����i��Ԫ�أ�x���ظ�Ԫ�ص�ֵ
	bool IsEmpty(int i, T& x) const{return first->link == nullptr ? true : false;} //�жϱ��Ƿ�Ϊ�գ�
	bool IsFull(int i, T& x)const { return false; }   //???�жϱ��Ƿ�Ϊ��
	//void Sort(); 
	void inputFront(T endTag);          //ǰ������
	void inputRear(T endTag);           //�������
	void output();             //���
	List<T>& operator=(List<T>& L);      //���غ�������ֵ
protected:
	LinkNode<T> * first;  //����ͷָ��
};
//���ƹ��캯��
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
//��������Ϊ�ձ�
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
//���㸽��ͷ���ĵ�����ĳ���
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
//�ڱ�������������x�Ľ�㣬�����ɹ�ʱ�������ظý���ַ�����򷵻�NULLֵ
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
//��λ���������ر��е�i��Ԫ�صĵ�ַ����i<=0��i�������н��������򷵻�NULL
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
	return current;   //���ص�i������ַ��������NULL����ʾiֵ̫��
}
//ȡ�������е�i��Ԫ�ص�ֵ
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
//�������еĵ�i��Ԫ�ظ�ֵ
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
//����Ԫ��x�����������е�i�����֮��
template<typename T>
bool List<T>::Insert(int i, T& x)
{
	LinkNode<T> * current = Locate(i);
	if (current)
		return false;
	LinkNode<T> *newNode = new LinkNode<T>(x);
}
//�������еĵ�i��Ԫ��ɾȥ��ͨ�������Ͳ���x���ظ�Ԫ�ص�ֵ
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
//�������������
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
//ǰ�巨����������
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
			cerr << "�洢�������" << endl; exit(1);
		}
		newNode->link = first->link;
		first->link = newNode;
		cin >> val;
	}
}
//��巨����������
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
			cerr << "�洢�������" << endl; exit(1);
		}
		last->link = newNode->link;
		last = newNode;
		cin >> val;
	}
}
#endif
