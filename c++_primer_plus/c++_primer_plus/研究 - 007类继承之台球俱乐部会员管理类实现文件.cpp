#include "007�о� - ��̳�̨֮����ֲ���Ա������.h"
#include <iostream>

TableTennisPlayer::TableTennisPlayer(const string & fn, 
									 const string & ln, 
									 bool ht) : 
strFirstName(fn), strLastName(ln), isHasTable(ht) {}	// ����ʹ�ó�ʼ���б�, ������: Ĭ�Ϲ��캯��->��ֵ����� �ĳ��� ����ת�����캯�� ��һ��.

void TableTennisPlayer::ShowName() const
{
	std::cout << strLastName << ", " << strFirstName;
}

RatedPlayer::RatedPlayer(unsigned int r, const string & fn, const string & ln, bool ht) : TableTennisPlayer(fn, ln, ht)
{																					// ��Ա��ʼ���б�, ���ǿ�ִ�д���, ���ڵ���������֮ǰ���ô˻��෽��
																					// ��������û��๹�캯��, ���ϱߵĴ���ע����, ��������Ĭ�ϵĻ��๹�캯��
	//TableTennisPlayer(fn, ln, ht);	// ����д�ǲ��е�, ���뽫�����Ļ������Ƕ������������
										// ����������д��û�õ�, ����ֻ����ʽ������һ���������, �������û��Ƕ�׽���������
										// C++���ڲ����������������������֮ǰ���ɻ������, ʹ���±ߵ����ַ�����Ƕ�ײ���ȥ��
	//this->TableTennisPlayer = TableTennisPlayer(fn, ln, ht);	// �޷�������Ƕ�׽�������

	rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp) : TableTennisPlayer(tp)
{
	rating = r;
}