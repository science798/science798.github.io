#include<iostream>
#include"SeqList.h"
#include"LinearList.h"
#include"List.h"
#include"DblList.h"
using namespace std;
int main()
{
	cout << "顺序表" << endl;
	SeqList<int> seqlist;
	seqlist.input();
	int num;
	do
	{ 
		cout << "请输入对应序号：" << endl;
		cout << "(0)离开 (1)搜索 (2)插入 (3)删除 (4)表信息 (5)修改值 (6)取值 (7)定位 " << endl;
		cout << "其他任意键退出" << endl;
	}
	while (!(cin >> num));
	int data;
	int location;
		switch (num)
		{
		case 1:
			cout << "请输入你想搜索的数据：" << endl;
			
			cin >> data;
			seqlist.Search(data);
			break;
		case 2:
			cout << "请输入你想插入元素的位置(从0开始)：" << endl;
			cin >> location;
			cout << "请输入你想插入的数据：" << endl;
			cin >> data;
			seqlist.Insert(location,data);
			break;
		case 3:
			cout << "请输入你想删除元素的位置(从1开始)" << endl;
			cin >> location;
			cout << location;
			seqlist.Remove(location);
			break;
		case 4:
			cout << "此表最大可容纳数为:" << defaultSize << endl;
			seqlist.output();
		case 5:
			cout << "请输入你想修改元素的位置(从1开始)：" << endl;
			cin >> location;
			cout << "请输入你想修改的数据：" << endl;
			cin >> data;
			seqlist.setData(location, data);
			break;
		case 6:

			break;
		case 7:

			break;
		case 8:
			

		default:
			break;
		}



	return 0;
}