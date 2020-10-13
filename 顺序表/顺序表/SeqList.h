#ifndef _SEQLIST_H
#define _SEQLIST_H


#include<iostream>
#include<stdlib.h>
#include "LinearList.h"
const int defaultSize = 100;
using namespace std;
template<typename T>
class SeqList : public LinearList<T>
{
protected:
	T *data;   //存放数组
	int maxSize;    //最大可容纳表项的项数
	int last;    //当前已存表项的最后位置(从0开始)
	void reSize(int newSize);    //改变data数组空间大小
public:
	T re;
	SeqList(int sz = defaultSize);   //构造函数
	SeqList(SeqList<T>& L);          //默认构造函数
	~SeqList() { delete[] data; }    //析构函数
	int Size()const { return maxSize; }   //计算表最大可容纳表项数
	int Length() const { return last + 1; }   //计算表长度
	int Search(T& x) const;   //搜索x在表中位置，函数返回表项序号
	int Locate(int i)const;    //定位第i个表项，函数返回表项序号
	bool getData(int i, T& x) const;   //取第i个表项的值
	void setData(int i, T& x);     //修改第i个表项的值为x
	bool Insert(int i, T& x);   //在第i个表项后插入x
	bool Remove(int i);   //删除第i个表项，通过x返回
	bool IsEmpty() const;     //判断表是否为空
	bool IsFull() const;     //判断表是否为满
	//virtual void Sort();    //排序
	void input();   //输入
	void output();  //输出
	SeqList<T> operator=(SeqList<T>& L);

};
//构造函数
template<typename T>
SeqList<T>::SeqList(int sz)
{
	if (sz > 0)
	{
		maxSize = sz;
		last = -1;
		data = new T[maxSize];
		if (data == nullptr)
		{
			cerr << "存储分配错误" << endl;
			exit(1);
		}
	}
}
//复制构造函数
template<typename T>
SeqList<T>::SeqList(SeqList<T>& L)
{
	maxSize = L.Size();
	last = L.Length() - 1;
	T value;
	data = new T[maxSize];
	if (data == nullptr)    //动态分配失败
	{
		cerr << "存储分配错误" << endl;
		exit(1);
	}
	for (int i = 1; i <= last + 1; i++)
	{
		L.getData(i, value);   //给value赋值
		data[i - 1] = value;
	}
}
//搜索函数
template<typename T>
int SeqList<T>::Search(T& x) const
{
	//在表中顺序搜索与给定值x匹配的表项，找出则函数返回该表项是第几个元素
	//否则函数返回0，表示搜索失败
	for (int i = 0; i <= last; i++)
	{
		if (data[i] == x)
		{
			cout << "找到，是第" << i + 1 << "个元素" << endl;
			return i + 1;
		}
	}  //顺序搜索，返回搜索结果
	cout << "未找到" << endl;
	return 0;   //搜索失败
}
//定位函数
template<typename T>
int SeqList<T>::Locate(int i) const
{
	//函数返回第i(1<=i<=last+1)个表项的位置，否则函数返回0，表示定位失败
	if (i >= 1 && i < last + 1)
		return i;
	else
		cout << "定位失败" << endl;
		return 0;
}
//getdata函数
template<typename T>
inline bool SeqList<T>::getData(int i, T& x) const   
{
	if (i > 0 && i < last + 1)
	{
		x = data[i - 1];
		cout << "第"<<i<<"个表项的值为：" << x << endl;
		return true;
	}
	else
		cout << "i值不在(0," << last + 1 << ")范围内" << endl;
		return false;
}
//setdata函数
template<typename T>
inline void SeqList<T>::setData(int i, T& x)
{
	if (i > 0 && i < last + 1)
	{
		data[i - 1] = x;
		cout << "修改成功：" << data[i - 1] << endl;
	}
	else
		cout << "i值不在(0," << last + 1 << ")范围内" << endl;
}

//私有函数
template<typename T>
void SeqList<T>::reSize(int newSize)
{
	//私有函数：扩充顺序表的存储数组空间大小，新数组的元素个数为newSize
	if (newSize <= 0)
	{
		cerr << "无效的数组大小" << endl;
		return;
	}
	if (newSize != maxSize)
	{
		T *newarray = new T[newSize];
		if (newarray == nullptr)
		{
			cerr << "存储分配错误(reSize)" << endl;
			exit(1);
		}
		int n = last + 1;
		T *srcptr = data;
		T * destptr = newarray;
		while (n--)*destptr++ = *srcptr++;
		delete[]data;
		data = newarray;
		maxSize = newSize;
	}
}

//插入函数
template<typename T>
bool SeqList<T>::Insert(int i, T& x)
{
	//将新元素x插入到表中第i(0<=i<=last+1)个表项之后
	//函数返回插入成功的信息
	if (last == maxSize - 1)
	{
		cout << "表满，不能插入" << endl;
		return false;     
	}
		
	if (i<0 || i>last + 1)
	{
		cout << "参数i不合理，不能插入" << endl;
		return false;   
	}
	for (int j = last; j >= i; j--)
		data[j + 1] = data[j];   //依次后移，空出第i号位置
	data[i] = x;  //插入
	++last;   //最后位置+1
	this->output();
	return true;   //插入成功
}
//删除函数
template<typename T>
bool SeqList<T>::Remove(int i)
{
	//从表中删除第i个表项，通过引用型参数x返回删除的元素值
	if (last == -1)
	{
		cout << "表空，不能删除" << endl;
		return false;
	}
	if (i<1 || i>last + 1)    //last+1为元素个数
	{
		cout << "参数i不合理，不能删除" << endl;
		return false;
	}
	re = data[i - 1];   //存放被删的元素
	for (int j = i; j <= last+1; j++)
	{
		data[j - 1] = data[j];   //依次前移，填补
		--last;     //最后位置-1
		cout << "删除的元素是：" << re << endl;
		this->output();
		return true; //删除成功
	}
}
//判断表是否为空
template<typename T>
bool SeqList<T>::IsEmpty() const
{
	if (last == -1)
	{
		cout << "表空" << endl;
		return false;
	}
	else
		cout << "表不为空" << endl;
}
//判断表是否为满
template<typename T>
bool SeqList<T>::IsFull() const
{
	if (last == maxSize - 1)
	{
		cout << "表满" << endl;
		return false;
	}
	else
		cout << "表不为满" << endl;
}
//输入数据，建立顺序表
template<typename T>
void SeqList<T>::input()
{
	cout << "开始建立顺序表，请输入表中元素个数:" << endl;
	int a;
	cin >> a;
	last = a - 1;
	if (last >= maxSize - 1)
		cout << "表元素个数输入有误，范围不能超过" << maxSize - 1 << endl;
	for (int i = 0; i <= last; i++)
	{
		cout << "请输入第" << i + 1 << "个元素:" << endl;
		cin >> data[i];    //应添加对对应类型T的容错机制
	}
	cout << "输入完成" << endl;
	this->output();
}
//输出数据，显示顺序表
template<typename T>
void SeqList<T>::output()
{
	cout << "顺序表当前元素最后位置为(从0开始)：" << last << endl;
	for (int i = 0; i <= last; i++)
	{
		cout << "#" << i + 1 << ":" << data[i]<<"	";
		if (!(i % 5) && i != 0)
			cout << endl;
	}
}
template<typename T>
SeqList<T> SeqList<T>::operator=(SeqList<T>& L)
{
	//重载函数代码：
}



#endif
