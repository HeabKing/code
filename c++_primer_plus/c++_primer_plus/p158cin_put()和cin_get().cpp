// �����嵥 5.19
#include <iostream>
int main()
{
	using namespace std;
	int ch;  // ������������int����charŶ
	int count = 0;

	while (EOF != (ch = cin.get())) // ��Ϊcin.get()�ܹ���ȡEOF(-1)�������ķ���ֵΪint����, �����е�ϵͳchar�����Ϳ���Ϊunsigned����ʹ��int������ch;
	{
		cout.put(char(ch));  // char(ch) ��ch��������ʾ��ת����char����, ��Ϊchǰ����������int����, Ȼ������Щc++��ʵ����������ԭ��put(char);put(unsigned char);put(signed char)������ʹ��put(int);��ʱ����ʽ��ת��������֪������ת����ʲô����
		++count;
	}
	cout << endl << count << " characters read\n";
	cin >> ch;   // ������е��� �������� ������ ��ʼִ��(������) ��ô�����dos���һ������, ��ʹ������cin >> ch;Ҳ����, ��Ϊ�ڼ�⵽��EOF�Ժ󽫻��ֹ��һ��������������ֻ������������������ . ʹ����ʱѭ�� . ʹ��cin.clear();����������

	return 0;
}