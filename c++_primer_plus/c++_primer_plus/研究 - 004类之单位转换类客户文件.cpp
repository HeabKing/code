#include <iostream>
#include "�о� - 004��֮��λת����.h"
using std::cout;

int main(void)
{
/******************** ���Թ���ת������ **********************/

	{
	Stonewt myWeight = 25;	// ��ʼ����ʱ��ʹ��ת������, ����������ʱ����
	Stonewt sheWeight(285.7);	// �����ʹת��������explicitҲ��ʵ��
	Stonewt itWeight(21, 15);

	cout << "�ҵ�����: ";
	myWeight.show_stn();
	cout << "��������: ";
	sheWeight.show_stn();
	cout << "��������: ";
	itWeight.show_lbs();
	cout << "   ";
	itWeight.show_stn();

	myWeight	= 26;	// ��Ϊת�������ǹ��캯��, ���캯��ֻ�������ɶ����ʱ�򱻵���, ��������϶�������һ������, ��ô�����Ȱ�26ת��������һ��Stonewt����ʱ����, Ȼ��ѱ�����ֵ���Ƹ��Ⱥ����;
	itWeight	= Stonewt(0, 1.1);	// �������ϱߵ�ץ������������һ����, ֻ���������ʽ��������;
	sheWeight	= 325;
	cout << "���극, �ҵ�����: ";
	myWeight.show_stn();
	cout << "���극, ��������: ";
	sheWeight.show_stn();
	}

/********************** �����෽��ת������ *********************/
	Stonewt w = 52.6;
	cout << "\nStonewt => int: " << (int)w << std::endl;
	cout << "Stonewt => double: " << (double)w << std::endl;

	return 0;
}