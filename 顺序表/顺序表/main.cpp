#include<iostream>
#include"SeqList.h"
#include"LinearList.h"
#include"List.h"
#include"DblList.h"
using namespace std;
int main()
{
	cout << "˳���" << endl;
	SeqList<int> seqlist;
	seqlist.input();
	int num;
	do
	{ 
		cout << "�������Ӧ��ţ�" << endl;
		cout << "(0)�뿪 (1)���� (2)���� (3)ɾ�� (4)����Ϣ (5)�޸�ֵ (6)ȡֵ (7)��λ " << endl;
		cout << "����������˳�" << endl;
	}
	while (!(cin >> num));
	int data;
	int location;
		switch (num)
		{
		case 1:
			cout << "�������������������ݣ�" << endl;
			
			cin >> data;
			seqlist.Search(data);
			break;
		case 2:
			cout << "�������������Ԫ�ص�λ��(��0��ʼ)��" << endl;
			cin >> location;
			cout << "�����������������ݣ�" << endl;
			cin >> data;
			seqlist.Insert(location,data);
			break;
		case 3:
			cout << "����������ɾ��Ԫ�ص�λ��(��1��ʼ)" << endl;
			cin >> location;
			cout << location;
			seqlist.Remove(location);
			break;
		case 4:
			cout << "�˱�����������Ϊ:" << defaultSize << endl;
			seqlist.output();
		case 5:
			cout << "�����������޸�Ԫ�ص�λ��(��1��ʼ)��" << endl;
			cin >> location;
			cout << "�����������޸ĵ����ݣ�" << endl;
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