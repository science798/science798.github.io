#ifndef _DBLIST_H
#define _DBLIST_H
#include"DblNode.h"
template<typename T>
class DblList:public LinearList<T>
{
public:
	DblList(T uniqueVal);   //构造函数：建立附加头结点
	~DblList();             //析构函数：释放所用存储
	int Length() const;    //计算双链表的长度
	bool IsEmpty() { return first->rLink == first; }  //判双链表空否
	DblNode<T> *getHead()const { return first; }      //取附加头结点地址
	void setHead(DblNode<T> *ptr) { first = ptr; }     //设置附加头结点地址
	DblNode<T> * Search(const T& x);    //在链表中沿后继方向寻找等于给定值x的结点
	DblNode<T> * Locate(int i, int d);   //在链表中定位序号为i(i>=0)的结点，d=0按前驱方向，d!=0按后继方向
	bool Insert(int i, const T& x, int d);   //在第i个结点后插入一个包含有值x的新结点
	bool Remove(int i, T& x, int d);   //删除第i个结点，x返回其值
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
		cerr << "存储分配错误" << endl; exit(1);
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
		return current;       //搜索成功
	else
		return nullptr;      //搜索失败
}
//定位函数(d决定搜索方向)
template<typename T>
DblNode<T> * DblList<T>::Locate(int i, int d)
{
	if (first->rLink == first || i == 0)
		return first;
	DblNode<T> * current;
	if (d == 0)
		current = first->lLink;   //搜索方向
	else current = first->rLink;
	for (int j = 0; j < i; j++)
	{
		if (current == first)
			break;      //链太短退出搜索
		else if (d == 0)
			current = current->lLink;
		else
			current = current->rLink;
		if (current != first)
			return current;   //搜索成功
		else return nullptr;   //搜索失败

	}
}
//插入函数
template<typename T>
bool DblList<T>::Insert(int i, const T& x, int d)
{
	DblList<T> * current = Locate(i, d);
	if (current == nullptr)
		return false;
	DblList<T> * newNode = new DblList<T>(x);
	if (newNode == nullptr)
	{cerr << "存储分配失败" << endl; exit(1);}
	if (d == 0)
	{
		newNode.

	}
}
#endif // !_DBLIST_H
