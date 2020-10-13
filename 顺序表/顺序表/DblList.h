#ifndef _DBLIST_H
#define _DBLIST_H
#include"DblNode.h"
template<typename T>
class DblList:public LinearList<T>
{
public:
	DblList(T uniqueVal);   //���캯������������ͷ���
	~DblList();             //�����������ͷ����ô洢
	int Length() const;    //����˫����ĳ���
	bool IsEmpty() { return first->rLink == first; }  //��˫����շ�
	DblNode<T> *getHead()const { return first; }      //ȡ����ͷ����ַ
	void setHead(DblNode<T> *ptr) { first = ptr; }     //���ø���ͷ����ַ
	DblNode<T> * Search(const T& x);    //���������غ�̷���Ѱ�ҵ��ڸ���ֵx�Ľ��
	DblNode<T> * Locate(int i, int d);   //�������ж�λ���Ϊi(i>=0)�Ľ�㣬d=0��ǰ������d!=0����̷���
	bool Insert(int i, const T& x, int d);   //�ڵ�i���������һ��������ֵx���½��
	bool Remove(int i, T& x, int d);   //ɾ����i����㣬x������ֵ
private:
	DblNode<T> * first;
};
template<typename T>
DblList<T>::DblList(T uniqueVal)
{
	first = new DblList<T>(uniqueVal);
	if (first)
		first->rLink = first->lLink = first;
	else
	{
		cerr << "�洢�������" << endl; exit(1);
	}
		
}
template<typename T>
DblList<T>::~DblList()
{

}
template<typename T>
int DblList<T>::Length() const
{
	DblNode<T> *current = first->rLink;
	int count = 0;
	while (current != first)
	{
		current = current->rLink;
		count++;
	}
	return count;
}
template<typename T>
DblNode<T> * DblList<T>::Search(const T& x)
{
	DblNode<T> *current = first->rLink;
	while (current != first && current->data != x)
		current = current->rLink;
	if (current != first)
		return current;       //�����ɹ�
	else
		return nullptr;      //����ʧ��
}
//��λ����(d������������)
template<typename T>
DblNode<T> * DblList<T>::Locate(int i, int d)
{
	if (first->rLink == first || i == 0)
		return first;
	DblNode<T> * current;
	if (d == 0)
		current = first->lLink;   //��������
	else current = first->rLink;
	for (int j = 0; j < i; j++)
	{
		if (current == first)
			break;      //��̫���˳�����
		else if (d == 0)
			current = current->lLink;
		else
			current = current->rLink;
		if (current != first)
			return current;   //�����ɹ�
		else return nullptr;   //����ʧ��

	}
}
//���뺯��
template<typename T>
bool DblList<T>::Insert(int i, const T& x, int d)
{
	DblList<T> * current = Locate(i, d);
	if (current == nullptr)
		return false;
	DblList<T> * newNode = new DblList<T>(x);
	if (newNode == nullptr)
	{cerr << "�洢����ʧ��" << endl; exit(1);}
	if (d == 0)
	{
		newNode.

	}
}
#endif // !_DBLIST_H
