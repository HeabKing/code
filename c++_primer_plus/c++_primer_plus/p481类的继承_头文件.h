// �����嵥 13.1 �����嵥 13.4
// �����๹�캯���ڳ�ʼ������˽�����ݵ�ʱ���õ��ǳ�Ա��ʼ���б��﷨
// �����಻�̳л���Ĺ��캯��, ���Խ����캯�������麯��Ҳûʲô����
#ifndef TABTENN0_H_
#define TABTENN0_H_
#include <string>
using std::string;

// һ���򵥵Ļ���
class TableTennisPlayer
{
private:
	string firstname;
	string lastname;
	bool hasTable;
public:
	TableTennisPlayer(const string & fn = "none", const string & ln = "none", bool ht = false);
	void Name() const;  // �����const����˼���������Ķ����ǲ��ܱ��ı��
	bool HasTable() const {return hasTable;}
	void ResetTable(bool v){hasTable = v;}
};

// �����嵥 13.4
class RatedPlayer : public TableTennisPlayer  
{  // : ָ�������ǻ��� publicָ���ǹ�������(����Ĺ��г�Ա��Ϊ������Ĺ��г�Ա, �����˽�г�Ա��Ϊ�������һ����, ����ֻ��ͨ�����л򱣻���������)
private:
	unsigned int rating;
public:
	// ������Ĺ��캯������Ϊ����ĳ�Ա�ṩ����
	RatedPlayer(unsigned int r = 0, const string & fn = "none", const string & ln = "none", bool ht = false);
	RatedPlayer(unsigned int r, const TableTennisPlayer & tp);
	unsigned int Rating() const {return rating;}
	void RestRating(unsigned int r){rating = r;}
};
#endif