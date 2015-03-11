						// ���ڼ̳е�ѧϰ  Ȼ���½��Ƕ�̬�̳�

// �����಻���ɻ���Ĺ��캯��, ���Խ����캯�����ó��麯��ûʲô����
// ���м̳�: is-a��ϵ

#ifndef ��Ա����_H_
#define ��Ա����_H_

#include <string>
using std::string;
class TableTennisPlayer
{
private:
	string	strFirstName;
	string	strLastName;
	bool	isHasTable;
public:
	TableTennisPlayer(const string & fn = "FirstName", const string & ln = "LastName", bool ht = false);
	void ShowName() const;
	bool GetisHasTable() const { return isHasTable; }
	void ResetTable(bool v) { isHasTable = v; }
};

class RatedPlayer : public TableTennisPlayer	// ��������: ����->���� ˽��->��Ϊ�������һ����, ����ֻ��ͨ������Ĺ��кͱ�����������
												// �����಻�̳л���Ĺ��캯��
{
private:
	unsigned int rating;
public:
	RatedPlayer(unsigned int r = 0, const string & fn = "fname", const string & ln = "lname", bool ht = false);
	RatedPlayer(unsigned int r, const TableTennisPlayer & tp);	// ������Ĺ��캯��������������³�Ա�ͻ���ĳ�Ա�ṩ����;
						// ���ڶ�̬, tpҲ����������				// ������Ĺ��캯������ʹ�û���Ĺ��캯��(���û����ʽ���ý�����ʽ����Ĭ�Ϲ��캯��);
																// ��������������ʱ��, �������ȴ����������, ����ζ�Ż������Ӧ���ڽ��������๹�캯��֮ǰ������, C++ʹ�ó�Ա��ʼ���б��﷨������ֹ���;
																// �ͷŶ����˳���봴����˳���෴, �ȵ���������������������, Ȼ����û������������;
	unsigned int GetRating() const { return rating; }
	void ResetRating(unsigned int r) { rating = r; }
};

#endif