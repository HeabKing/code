// �����嵥 5.12
// ����c�����ַ����ȽϺ�c++�����ַ����Ƚ�
#include <iostream>
#include <string>   // string class
#include <cstring>  // strcmp()
int main()
{
	using namespace std;

// ###### c-style #######
	char word1[5] = "?ate";
	for (char ch = 'a'; strcmp(word1, "mate"); ch++)
	{
		cout << word1 << endl;
		word1[0] = ch;
	}
	cout << "���ս��:" << word1 << endl;

	string word2 = "?ate";
	for (char ch = 'a'; word2 != "mate"; ch++)
	{
		cout << word2 << endl;
		word2[0] = ch;
	}
	cout << "string�ķ������ս��:" << word2 << endl;

	return 0;
}