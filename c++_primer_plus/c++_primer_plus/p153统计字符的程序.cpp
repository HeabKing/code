// �����嵥 5.17
#include <iostream>
int main()
{
	using namespace std;
	char ch;
	int count = 0;

	cout << "Enter characters; enter # to qiut:\n";
	// ### ��������㷨 ####
	cin >> ch;
	while (ch != '#')
	{
		//cout << ch;
		++count;
		cin >> ch;
	}
	cout << "�����ͳ�Ƴ���:" << count << endl;

	// ### ��ȷ���㷨 ###
	cin.get(); // ���ϸ�ѭ�����ڻ����е�'\n'����
	count = 0;
	cin.get(ch); // ���ﴫ�ݵ���ch������ch�ĵ�ַ, ֮�����ܹ��޸�ch��ֵ����Ϊ��������������Ϊ������
	while (ch != '#')
	{
		cout << ch;
		++count;
		cin.get(ch);
	}
	cout << "��ȷ��ͳ�Ƴ���:" << count << endl;

	return 0;
}