// �����嵥 11.12
#include <iostream>  // �Ӽ�����˵, ���ﲢ���ð���ͷ�ļ�iostream, ��Ϊ��"p395cout���ʱ��(���������).h"���Ѿ������˸��ļ�, Ȼ��, ��ΪTime����û�, ������֪����������а�������Щ�ļ�, �����Ӧ�ø���Ľ�����д���������ͷ�ļ���������
#include "p395cout���ʱ��(���������).h"

int main()
{
	using std::cout;
	using std::endl;
	Time aida(3, 35);
	Time tosca(2, 48);
	Time temp;

	cout << "Aida and Tosca: \n";
	cout << aida << "; " << tosca << endl;
	temp = aida + tosca;  // operator+
	cout << "Aida + Tosca: " << temp << endl;
	cout << aida << endl;
	temp = aida* 1.17;  // member operator*()
	cout << "Aida * 1.17: " << temp << endl;
	cout << "10.0 * Tosca: " << 10.0 * tosca << endl;  // ʹ��cout���ʱ��

	return 0;
}