// �����嵥 5.6
#include <iostream>
#include <string>
int main()
{
	using namespace std;
	cout << "Enter a word: ";
	string word;
	cin >> word;

	for (int i = word.size() - 1; i >= 0; i--) // string���е�size()����ַ������ַ�������'\0'
		cout << word[i];
	cout << "\nBye.\n";

	// ###### ��һ�ָ��õ��㷨 ########
	for(int i = 0, j = word.size() - 1; i < j; ++i, --j)
	{
		 char temp;
		 temp = word[j];
		 word[j] = word[i];
		 word[i] = temp;
	}
	cout << word << endl;

	return 0;
}