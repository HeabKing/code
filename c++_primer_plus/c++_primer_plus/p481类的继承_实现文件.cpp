// �����嵥 13.2  �����嵥 13.5
#include "p481��ļ̳�_ͷ�ļ�.h"
#include <iostream>

TableTennisPlayer::TableTennisPlayer(const string & fn, const string & ln, bool ht):firstname(fn), lastname(ln), hasTable(ht){}  // ��ʼ���б��﷨??????????????
//TableTennisPlayer::TableTennisPlayer(const string & fn, const string & ln, bool ht)
//{
//	firstname = fn;
//	lastname = ln;
//	hasTable = ht;
//}
// ����Ĺ��캯��ʹ���˵�ʮ���½��ܵĳ�Ա��ʼ���б��﷨, Ҳ����ʹ������ķ���, ������Ϊfirstname����string��Ĭ�Ϲ��캯��, �ڵ���string�ĸ�ֵ�����, ��firstname����Ϊfn, ���ǳ�ʼ���б��﷨���Լ���һ������, ��ֱ��ʹ��string�ĸ��ƹ��캯����firstname��ʼ��Ϊfn

void TableTennisPlayer::Name() const
{
	std::cout << lastname << ", " << firstname;
}

RatedPlayer::RatedPlayer(unsigned int r, const string & fn, const string & ln, bool ht) : TableTennisPlayer(fn, ln, ht)
{                                                                                  //  ��Ա��ʼ���б�, ���ǿ�ִ�д���, ���ڵ���������֮ǰ���ô˻��෽��
	                                                                               // ��������û��๹�캯��, ������ĳ�ʼ���б����ע����, ��������Ĭ�ϵĻ��๹�캯��
	//TableTennisPlayer(fn, ln, ht);  // ����д�ǲ��е�, ���뽫�����Ļ������Ƕ������������
	// this.TableTennisPlayer = TableTennisPlayer(fn, ln, ht);
	rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp) : TableTennisPlayer(tp), rating(r)
{                                                                  // ��tp�����˳�ʼ���б�Ļ��๹�캯��, ��������û�ж���ֻ��һ���������Ĳ���, ϵͳ���Զ�����һ�����ƹ��캯��(�������ж�̬�����ڴ�Ļ��Զ����ɵĸ��ƹ��캯���ǲ����ʵ�)         
	rating = r;
}