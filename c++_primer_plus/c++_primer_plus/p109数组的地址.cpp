// �Լ��ܽ�
/*static buding��̬����: ����ʱ����������ڴ�   dynamic buding��̬����: �ڳ�������ʱ��������(��̬����dynamic array)
��̬���� �� ��̬���� ������: .��̬��������һ������ָ��, ����̬��������һ������ָ��
	. ��̬������ʹ��sizeof���ص���������ֽ���, ����̬��������ʹ��sizeof���ص���ָ����ֽ���ԭ���������������, 
	c��c++���Ὣ����ָ�����Ϊ��ַ(��һ����Ҫ����ʱ������ȡ��ַ��ʱ��, ������Ҳ�������Ϊ���ַ) */
#include <iostream>
int main()
{
	using namespace std;
	int in[10];
	int * in1Ptr = new int[10];

	cout << "��̬������inʹ��sizeof:" << sizeof(in) << endl;
	cout << "��̬������in1Ptrʹ��sizeof:" << sizeof(in1Ptr) << endl;

	short tell[10];
	short * tellPtr = new short[10];
	cout << "tell = " << tell << "ֱ��ʹ�õ�ʱ��tellΪ�����һ��Ԫ�صĵ�ַ" << endl;
	cout << "&tell = " << &tell << "������Ӧ��&�������ʱ��õ�������������ĵ�ַ" << endl;
	cout << "tellPtr = " << tellPtr << "ֱ��ʹ�ö�̬�����������Ϊ��һ��Ԫ�صĵ�ַ" << endl;
	cout << "&tellPtr = " << &tellPtr << "�Զ�̬����ʹ��&������õ����ǵ�һ��Ԫ�صĵ�ַ�ĵ�ַ" << endl;

	return 0;
}