#include <iostream>
using namespace std;
#include "p326���ƿռ�.cpp"
using namespace Jack; // ���jack��main()��ʹ���˴α���ָ��, ��ô����Ϊ�ں���֮��������, ���ǲ���ʹ��̫�ļ��е����������ܹ�ʹ����Щ����
int main()
{
// ������ʹ��using����ָ�����ֲ����������
	double pail = 1;  // �ֲ�����������Jack::pail
	cout << pail << endl;
	cin >> Jack::pail;
	cout << Jack::pail << endl; // ���ǿ��������������

// ���ڶ��ھֲ����������using����ָ������
	int pal = 2;
	cout << pal << endl;
	using namespace Jill;
	cout << pal <<endl;  // ����ʹ�õĻ��Ǿֲ�����, ˵��Jill::pal��������
	cin >> Jill::pal;
	cout << Jill::pal << endl;
	cout << pal << endl;

	return 0;
}

// #############�ܽ�using������using����ָ�������###########
// �������ƿռ����������������ͬ������, �����ͼʹ��using���������ƿռ�����Ƶ������������, �����������ƻᷢ����ͻ,
// ���Ҷ��Ǻ�������������г���.    ���ʹ��using����ָ������ƿռ�����Ƶ������������, ��ֲ��汾���������ƿռ�汾, 
// �������۾ֲ������ͱ���ָ���Ǹ��Ƚ���д��, ���Ǳ���ָ���ͬ������������