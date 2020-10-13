#ifndef _LinearList_H
#define _LinearList_H
template<typename T>
class LinearList
{
public:
	LinearList();
	~LinearList();
	virtual int Size() const = 0;   //���������
	virtual int Length() const = 0;  //�����
	virtual int Search(T& x) const = 0;  //�ڱ�����������ֵx
	virtual int Locate(int i) const = 0;    //�ڱ��ж�λ��i��Ԫ�ص�λ��
	virtual bool getData(int i, T& x) const = 0;  //ȡ��i�������ֵ
	virtual void setData(int i, T& x) = 0;     //�޸ĵ�i�������ֵΪx
	virtual bool Insert(int i, T& x) = 0;   //�ڵ�i����������x
	virtual bool Remove(int i) = 0;   //ɾ����i�����ͨ��x����
	virtual bool IsEmpty() const = 0;    //�жϱ��Ƿ�Ϊ��
	virtual bool IsFull() const = 0;   //�жϱ��Ƿ�Ϊ��
	//virtual void Sort() = 0;    //����
	virtual void input() = 0;   //����
	virtual void output() = 0;  //���
};
template<typename T>
LinearList<T>::LinearList()
{

}
template<typename T>
LinearList<T>::~LinearList()
{

}
#endif
