// Build: 2014-10-10 12:12:33
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <time.h>
#include "HeabUtility.h"
using namespace std;

struct item
{
	string	key;
	int		value;
};

void openHowChangeFile(vector<item> & tra);
int isChangeItem(vector<item> & tra, string s);


int main()
{
	char buf[10000];
	ifstream fin;

			// ��ת����׼�ĵ�, ��ȡ������

	vector<item> tra;
	openHowChangeFile(tra);
	
			// ��source�ĵ�, ���в���

	fin.open("����.txt");
	if (!fin.is_open())
	{
		cout << "�޷����ļ� ����.txt\n";
		exit(EXIT_FAILURE);
	}

	ofstream fout;
	sprintf_s(buf, "%d.txt", time(nullptr));
	fout.open(buf);

		// ��ȡһ��
	fin.getline(buf, 10000);
	HString hs(buf, "\t");
	while (fin.good())
	{
			// ������ļ�
		int index;
		while (!hs.isEnd())
		{
			string elem = hs.subStr();
			
			// ���ת����׼�ļ���ָ���ĸ�����, �����, ����ֱ�����
			if ((index = isChangeItem(tra, elem)) != -1)	// �����Ҫ���ĵ�
				fout << tra[index].value << "\t";
			else											// ����ǲ��ø��ĵ�
				fout << elem << "\t";					
		}
		fout << "\n";
			// ��ȡ��һ��
		fin.getline(buf, 10000);
		hs.reset(buf, "\t");
	}
}

void openHowChangeFile(vector<item> & tra)
{
	ifstream fin;
	item it;

	fin.open("Test.txt");
	if (!fin.is_open())
	{
		cout << "�޷����ļ�Test.txt\n";
		exit(EXIT_FAILURE);
	}

	fin >> it.key;
	while (fin.good())
	{
		// �Ե�ע����
		if (it.key[0] == '=')
		{
			while (fin.get() != '\n');
			fin >> it.key;
		}
		fin >> it.value;
		tra.push_back(it);
		fin >> it.key;
	}

	fin.close();
}

int isChangeItem(vector<item> & tra, string s)
{
	for (unsigned int i = 0; i < tra.size(); i++)
	{
		if (tra.at(i).key == s)
			return i;
	}
	return -1;
}