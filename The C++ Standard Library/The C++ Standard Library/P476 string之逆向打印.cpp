#include <iostream>
#include <string>
using namespace std;

int main(int argc, char ** argv)
{
	const string delims(" \t,.;");	// ���м������������һ�������ַ���������
	string line;

	// for every line read succesfully
	while (getline(cin, line))
	{
		string::size_type begIdx, endIdx;

		// search beginning of the first word
		begIdx = line.find_first_not_of(delims);
			// ��Ѱ��һ�����ʵ���ʵλ��, ����find_first_not_of()����"������������ָ�ַ���"�ĵ�һ���ַ�������, ���û���ҵ�, ����string::npos	

		// while beginning of a word found
		while (begIdx != string::npos)	// ����ҵ���һ������, �����ڲ�ѭ��
		{
			// search end of the actual word
			endIdx = line.find_first_of(delims, begIdx);	// ������Ѱ��һ��������ָ�ַ����ڵ��κ��ַ��ĵ�һ�γ���λ��, �ڶ��������ǿ�ѡ��, ������ʾ��Ѱ���
			if (endIdx == string::npos)
				// end of word is end of line
				endIdx = line.length();

			// print characters in reverse order
			// �������ַ������ӡ
			for (int i = endIdx - 1; i >= static_cast<int>(begIdx); --i)
				cout << line[i];	// ������ǰ�begIdxת��Ϊint, ������ܽ�������ѭ����, ����������, 

		cout << ' ';

		// search beginning of the next word
		begIdx = line.find_first_not_of(delims, endIdx);	// ���³�ʼ��begIdx, ʹ����ʾ��һ�����ʵ����(�������һ�����ʵĻ�)
		}
		cout << endl;
	}
}