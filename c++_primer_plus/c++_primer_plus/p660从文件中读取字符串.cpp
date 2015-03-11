// string�汾��getline()�����ݱ��浽������������:
//		1. �����ļ���β, �����������, ��������eofbit��������, ����ζ�ŷ���fail()�ͷ���eof()��������true
//		2. �����ֽ��ַ�(Ĭ��Ϊ\n), �����������, ���ɷֽ��ַ�����������ɾ��, ���ǲ�������
//		3. ��ȡ���ַ����ﵽ�������ֵ(string::npos�Ϳɹ�������ڴ��н�С��һ��), �����������, ����������������failbit, ����ζ�ŷ���fail()������true 
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
int main(void)
{
	using namespace std;
	ifstream fin;
	fin.open("p660���ļ��ж�ȡ�ַ���.txt");
	if (!fin.is_open())
	{
		cerr << "Can't open file. Bye.\n";
		exit(EXIT_FAILURE);
	}
	string item;
	int count = 0;
	getline(fin, item, ':');
	while (fin)
	{
		++count;
		cout << count << ": " << item << endl;
		getline(fin, item, ':');  // �������Ĭ�ϵ�'\n'�ֽ��������':' �����ڶ�ȡ��ʱ����'\n'Ҳ����ȥ
	}
	cout << "Done\n";
	fin.close();

	return 0;
}