// �����嵥 4.22
// ͨ��������ʱ���� Ȼ��̬��������ʹ�õ��ڴ��С����̬�����ڴ� �Դﵽ��ʡ�ڴ��Ŀ��
#include <iostream>
#include <cstring>
using namespace std;
char * getname(void);
int main()
{
	char * name;

	name = getname();
	cout << name << " at " << (int * )name << endl;
	delete [] name; // ��delete��new���ڲ�ͬ�ĺ����в���һ���õ�����, ����ֻ��Ϊ�˸������������ǿ��Ե�

	return 0;
}
char * getname() // �˴�����ʡдvoid
{
	char temp[80];
	cout << "Enter last name: " << endl;
	cin >> temp;
	char * pn = new char[strlen(temp) + 1];
	strcpy(pn, temp);

	return pn;
}