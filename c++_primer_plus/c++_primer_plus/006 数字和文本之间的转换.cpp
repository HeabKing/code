// ����: 2014-08-22 14:47:01
// atoi() itoa() sprintf() sscanf()

#include <iostream>
#include <string>
using namespace std;
#pragma warning(disable: 4996)
int main()
{
	//============= �ı� => ���� ==============
				
				// atoi()

	string str1 = "18 : 56";
	cout << str1 << " = " << atoi(str1.c_str()) << endl;	// ���18

				// sscanf()

	int temp1;
	int temp2;
	sscanf(str1.c_str(), "%d : %d", &temp1, &temp2);
	cout << str1 << " = \n\ttemp1 = " << temp1 << "\n\ttmep2 = " << temp2 << endl << endl;

	//============= ���� => �ı� ==============

				// itoa()

	temp1 = 123456;
	char tmp[32];
	cout << temp1 << " = " << itoa(temp1, tmp, 10) << " dec" << endl;	// �ڶ��������Ǳ����, nullptr�ᵼ��д��0x00000000�������ʳ�ͻ
	cout << temp1 << " = " << itoa(temp1, tmp, 2) << " bin" << endl;	// ������
	cout << temp1 << " = " << itoa(temp1, tmp, 8) << " oct"<< endl;		// �˽���
	cout << temp1 << " = " << itoa(temp1, tmp, 16) << " hex"<< endl << endl;	// ʮ������
				// ssprintf()

	sprintf(tmp, "%d", temp1);
	cout << temp1 << " = " << tmp << " dec" << endl;	// ʮ����
	//cout << temp1 << " = " << temp1 << " bin" << endl;	// ������
	sprintf(tmp, "%o", temp1);
	cout << temp1 << " = " << tmp << " oct"<< endl;		// �˽���
	sprintf(tmp, "%x", temp1);
	cout << temp1 << " = " << tmp << " hex"<< endl;	// ʮ������

	/*int x = 100;
	printf ("ʮ����: %d, �˽���: %o, ʮ������: %x(%X)\n", x, x, x, x);
	printf ("ʮ����: %d, �˽���: %#o, ʮ������: %#x(%#X)\n", x, x, x, x);*/
}