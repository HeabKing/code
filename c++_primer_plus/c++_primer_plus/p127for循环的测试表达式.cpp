// �����嵥 5.2
// forѭ���еĲ��Ա��ʽ����Ϊ�κα��ʽ, ����c++��ѽ��ǿ��ת��Ϊbool����
// ��: ��0ת����false ����ת����true
#include <iostream>
int main()
{
	using namespace std;

	cout << "����ѭ������:\n";
	int input;
	cin >> input;
	for(int i = input; i; i--) // �ѱ��ʽi;ת������bool���� bool����ʹ����ļ����Ը���,
							   // ��Ϊת����bool���͵�ʱ��, 0��ת������false������ת������true
						       // ����ʹ��bool����ת����int��ʱ�� false����0 true����1
		// ���� int i = input; . ����i���������for�ľֲ��Զ�����, ������for��ʹ��
		//               	   . �Ⲣ����һ�����ʽ, ��ֻ������һ�����, ���ʽ����ֵ, 
	    //                       ��int iֻ��һ���������
		cout << "i = " << i << endl;
	cout << "ѭ����ߵ�i: " << i << endl;

	return 0;
}