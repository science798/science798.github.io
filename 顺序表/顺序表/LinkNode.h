#ifndef _LINKNODE_H
#define _LINKNODE_H
//��������ͷ���
//class List;
//class LinkNode
//{
//	friend class List;
//private:
//	int data;    //����Ԫ����
//	LinkNode * link;     //ָ����
//};

//������ͷ���
template<typename T>
class LinkNode
{
private:
	T data;
	LinkNode * link;
	LinkNode(LinkNode<T> * ptr = nullptr) { link = ptr; }
	LinkNode(const T& item, LinkNode<T> * ptr = nullptr) { data = item, link = ptr; }
};
#endif 
