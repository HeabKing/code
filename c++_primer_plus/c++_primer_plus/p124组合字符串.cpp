// �����ϰ 3
//�������� �������� ���� Ȼ����������м��һ���������
#include <iostream>
#include <cstring>
#define SIZE 20
int main()
{
	using namespace std;
	char fir[SIZE];
	char sec[SIZE];
	char name[2 * SIZE + 1];
	char name_std[2 * SIZE + 1];

	cout << "First name:\n";
	cin >> fir;
	cout << "Second name:\n";
	cin >> sec;

	// #####�Լ����㷨######
	strcpy(name, fir);
	name[strlen(fir)] = ',';
	strcpy(name + strlen(fir) + 1, sec);
	cout << "daxiong: " << name << endl;

	//########std�㷨#####
	strcpy(name_std, fir);
	strcat(name_std, ",");
	strncat(name_std, sec, SIZE); // sec�е�ǰn���ַ��ӵ�name��β, �����Զ����һ��'\0'
							  // ���sec����n���ַ����ٵ��ַ���'\0'����
	cout << "std: " << name << endl;

	return 0;
}