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
	T *data;   //�������
	int maxSize;    //�������ɱ��������
	int last;    //��ǰ�Ѵ��������λ��(��0��ʼ)
	void reSize(int newSize);    //�ı�data����ռ��С
public:
	T re;
	SeqList(int sz = defaultSize);   //���캯��
	SeqList(SeqList<T>& L);          //Ĭ�Ϲ��캯��
	~SeqList() { delete[] data; }    //��������
	int Size()const { return maxSize; }   //������������ɱ�����
	int Length() const { return last + 1; }   //�������
	int Search(T& x) const;   //����x�ڱ���λ�ã��������ر������
	int Locate(int i)const;    //��λ��i������������ر������
	bool getData(int i, T& x) const;   //ȡ��i�������ֵ
	void setData(int i, T& x);     //�޸ĵ�i�������ֵΪx
	bool Insert(int i, T& x);   //�ڵ�i����������x
	bool Remove(int i);   //ɾ����i�����ͨ��x����
	bool IsEmpty() const;     //�жϱ��Ƿ�Ϊ��
	bool IsFull() const;     //�жϱ��Ƿ�Ϊ��
	//virtual void Sort();    //����
	void input();   //����
	void output();  //���
	SeqList<T> operator=(SeqList<T>& L);

};
//���캯��
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
			cerr << "�洢�������" << endl;
			exit(1);
		}
	}
}
//���ƹ��캯��
template<typename T>
SeqList<T>::SeqList(SeqList<T>& L)
{
	maxSize = L.Size();
	last = L.Length() - 1;
	T value;
	data = new T[maxSize];
	if (data == nullptr)    //��̬����ʧ��
	{
		cerr << "�洢�������" << endl;
		exit(1);
	}
	for (int i = 1; i <= last + 1; i++)
	{
		L.getData(i, value);   //��value��ֵ
		data[i - 1] = value;
	}
}
//��������
template<typename T>
int SeqList<T>::Search(T& x) const
{
	//�ڱ���˳�����������ֵxƥ��ı���ҳ��������ظñ����ǵڼ���Ԫ��
	//����������0����ʾ����ʧ��
	for (int i = 0; i <= last; i++)
	{
		if (data[i] == x)
		{
			cout << "�ҵ����ǵ�" << i + 1 << "��Ԫ��" << endl;
			return i + 1;
		}
	}  //˳�������������������
	cout << "δ�ҵ�" << endl;
	return 0;   //����ʧ��
}
//��λ����
template<typename T>
int SeqList<T>::Locate(int i) const
{
	//�������ص�i(1<=i<=last+1)�������λ�ã�����������0����ʾ��λʧ��
	if (i >= 1 && i < last + 1)
		return i;
	else
		cout << "��λʧ��" << endl;
		return 0;
}
//getdata����
template<typename T>
inline bool SeqList<T>::getData(int i, T& x) const   
{
	if (i > 0 && i < last + 1)
	{
		x = data[i - 1];
		cout << "��"<<i<<"�������ֵΪ��" << x << endl;
		return true;
	}
	else
		cout << "iֵ����(0," << last + 1 << ")��Χ��" << endl;
		return false;
}
//setdata����
template<typename T>
inline void SeqList<T>::setData(int i, T& x)
{
	if (i > 0 && i < last + 1)
	{
		data[i - 1] = x;
		cout << "�޸ĳɹ���" << data[i - 1] << endl;
	}
	else
		cout << "iֵ����(0," << last + 1 << ")��Χ��" << endl;
}

//˽�к���
template<typename T>
void SeqList<T>::reSize(int newSize)
{
	//˽�к���������˳���Ĵ洢����ռ��С���������Ԫ�ظ���ΪnewSize
	if (newSize <= 0)
	{
		cerr << "��Ч�������С" << endl;
		return;
	}
	if (newSize != maxSize)
	{
		T *newarray = new T[newSize];
		if (newarray == nullptr)
		{
			cerr << "�洢�������(reSize)" << endl;
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

//���뺯��
template<typename T>
bool SeqList<T>::Insert(int i, T& x)
{
	//����Ԫ��x���뵽���е�i(0<=i<=last+1)������֮��
	//�������ز���ɹ�����Ϣ
	if (last == maxSize - 1)
	{
		cout << "���������ܲ���" << endl;
		return false;     
	}
		
	if (i<0 || i>last + 1)
	{
		cout << "����i���������ܲ���" << endl;
		return false;   
	}
	for (int j = last; j >= i; j--)
		data[j + 1] = data[j];   //���κ��ƣ��ճ���i��λ��
	data[i] = x;  //����
	++last;   //���λ��+1
	this->output();
	return true;   //����ɹ�
}
//ɾ������
template<typename T>
bool SeqList<T>::Remove(int i)
{
	//�ӱ���ɾ����i�����ͨ�������Ͳ���x����ɾ����Ԫ��ֵ
	if (last == -1)
	{
		cout << "��գ�����ɾ��" << endl;
		return false;
	}
	if (i<1 || i>last + 1)    //last+1ΪԪ�ظ���
	{
		cout << "����i����������ɾ��" << endl;
		return false;
	}
	re = data[i - 1];   //��ű�ɾ��Ԫ��
	for (int j = i; j <= last+1; j++)
	{
		data[j - 1] = data[j];   //����ǰ�ƣ��
		--last;     //���λ��-1
		cout << "ɾ����Ԫ���ǣ�" << re << endl;
		this->output();
		return true; //ɾ���ɹ�
	}
}
//�жϱ��Ƿ�Ϊ��
template<typename T>
bool SeqList<T>::IsEmpty() const
{
	if (last == -1)
	{
		cout << "���" << endl;
		return false;
	}
	else
		cout << "��Ϊ��" << endl;
}
//�жϱ��Ƿ�Ϊ��
template<typename T>
bool SeqList<T>::IsFull() const
{
	if (last == maxSize - 1)
	{
		cout << "����" << endl;
		return false;
	}
	else
		cout << "��Ϊ��" << endl;
}
//�������ݣ�����˳���
template<typename T>
void SeqList<T>::input()
{
	cout << "��ʼ����˳������������Ԫ�ظ���:" << endl;
	int a;
	cin >> a;
	last = a - 1;
	if (last >= maxSize - 1)
		cout << "��Ԫ�ظ����������󣬷�Χ���ܳ���" << maxSize - 1 << endl;
	for (int i = 0; i <= last; i++)
	{
		cout << "�������" << i + 1 << "��Ԫ��:" << endl;
		cin >> data[i];    //Ӧ��ӶԶ�Ӧ����T���ݴ����
	}
	cout << "�������" << endl;
	this->output();
}
//������ݣ���ʾ˳���
template<typename T>
void SeqList<T>::output()
{
	cout << "˳���ǰԪ�����λ��Ϊ(��0��ʼ)��" << last << endl;
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
	//���غ������룺
}



#endif
