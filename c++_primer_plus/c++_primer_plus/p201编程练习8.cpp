// �����ϰ 6.11 (8)
// ͳ��һ���ļ����ַ���
#include <iostream>
#include <fstream>
#include <string>
int main()
{
	using namespace std;
	int count = 0;
	string filename;
	char ch;

	cout << "������Ҫ����ͳ���ַ����ļ����ļ���:\n";
	cin >> filename;
	ifstream fin;
	fin.open(filename);
	if (!fin.is_open())
	{
		cout << "�޷����ļ�" << filename << endl;
		exit(EXIT_FAILURE);
	}
	while (fin >> ch)
	{
		cout << ch;
		count++;
	}
	cout << "һ���е��ַ���:" << count << endl << endl << endl;
	fin.close();
	fin.open(filename);
	if (!fin.is_open())
	{
		cout << "�޷����ļ�" << filename << endl;
		exit(EXIT_FAILURE);
	}
	count = 0;
	while (EOF != (ch = fin.get()))
	{
		cout << ch;
		count++;
	}
	cout << "һ���е��ַ���:" << count << endl << endl << endl;
	return 0;
}