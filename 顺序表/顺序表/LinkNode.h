#ifndef _LINKNODE_H
#define _LINKNODE_H
//不带附加头结点
//class List;
//class LinkNode
//{
//	friend class List;
//private:
//	int data;    //数据元素域
//	LinkNode * link;     //指针域
//};

//带附加头结点
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
