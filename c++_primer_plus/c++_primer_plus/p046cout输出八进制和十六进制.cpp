// �����嵥 3.4
// cout����˽��ƺ�ʮ������ ���Ʒ�:decʮ���� oct�˽��� hexʮ������
#include <iostream>
using namespace std;
int main()
{
	using namespace std;
	int chest = 42;
	int waist = 42;
	int inseam = 42;

	cout << "Monsieur(���� ĥer��er) cuts a striking(������Ŀ��) figure(����,����)!" << endl;
	cout << "ʮ����chest = " << chest << endl;
	cout << hex;  // ���Ʒ�ʵ������һ����Ϣ, ����cout��ȡ������Ϊ;
	cout << "ʮ������waist = " << waist << endl;
	cout << oct;
	cout << "�˽���inseam = " << inseam << endl;

	return 0;
}