// Build: 2014-10-9 17:12:46

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include "HeabUtility.h"
using namespace std;

int main()
{
	string ItemKey =	"Rfxno;Itemcode;IsNewSoldListing;Confirmdate;";
						

	ifstream fin;
	fin.open("D:\\����.txt");
	if (!fin.is_open())
	{
		cout << "û�ܴ��ļ�!\n";
		exit(EXIT_FAILURE);
	}

	map<string, string> AItem;

		// ��ȡItem��Key	
	string temp = ItemKey;
	string getALable;
	fin >> getALable;	// �Ե�����
	string tap;

	char t[10000];
	fin.getline(t, 10000);
	fin.getline(t, 10000);
	HString s(t, "\t");
	
	while (!s.isEnd())
	{
		cout << s.subStr() << endl;
	}
	//while (true)
	//{
	//	int ii;
	//	if ((ii = temp.find(";")) < 0)	// ��ȡ����
	//		break;

	//		// ���ļ��ж�ȡһ��
	//	fin >> getALable;

	//	cout << getALable;
	//	 //temp.substr(0, ii) << " ";      
	//	
	//	temp = temp.substr(ii + 1);		// �Ե�����ȡ��substr
	//}
}