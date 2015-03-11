// ���� 2013 12 16 17
// ��ϰ 2014 08 18 18 # 1

// typeid�����ʹ���ܹ�ȷ�����������Ƿ�Ϊͬ������, ������һ����type_info����(ͷ�ļ�typeinfo)������ # 1
// typeid(Magnificent) == typeid(*pg);  type_info ���������� == !=, ���pg��һ����ָ��, ������bad_typeid�쳣 # 1
// typeid(*pg).name() ����pg��ָ��Ķ����������ඨ����ַ��� # 1
// typeid������dynamic_cast��virtual�������ܴ�������
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
using namespace std;

class Grand
{
private:
	int hold;
public:
	Grand (int h = 0) : hold(h) {}
	virtual ~Grand() {}
	virtual void Speak() const {cout << "Speak of Grand.\n";}
	virtual int Value() const {return hold;}
};

class Superb : public Grand
{
public:
	Superb(int h = 0) : Grand(h) {}
	virtual void Speak() const {cout << "Speak of Superb.\n";}
	virtual void Say() const {cout << "I hold the superb value of " << Value() << ".\n";}
};

class Magnificent : public Superb
{
private: 
	char ch;
public:
	Magnificent(int h = 0, char cv = 'A') : Superb(h), ch(cv) {}
	void Speak() const {cout << "Speak of Magnificent.\n";}
	void Say() const {cout << "I hold the character " << ch << " and the integer " << Value() << endl;}
};

Grand * GetOne();
int main()
{
	srand(time(0));
	Grand * pg;
	Superb * ps;

	for (int i = 0; i < 5; i++)
	{
		pg = GetOne();
		cout << "Now processing type " << typeid(*pg).name() << "...\n";
		pg->Speak();
		if (ps = dynamic_cast<Superb *> (pg))
			ps->Say();
		if (typeid(Magnificent) == typeid(*pg))	// ����� # 1 1 ���������� typeid���κ�������֮��Ƚ�, ��# 1 1ֻ�������ж��ǲ���������... (��� # 1 2) # 1
		//if (dynamic_cast<Magnificent *>(pg))	// # 1 1
			cout << "Yes, you are really magnificent.\n";
		if (dynamic_cast<Grand *>(pg))			// # 1 2
			cout << "dynamic_cast vs typeid ������\n";
		cout << endl;
	}

	return 0;
}

Grand * GetOne()
{
	Grand * p;
	switch (std::rand() % 3)
	{
	case 0: p = new Grand(std::rand() % 100); break;
	case 1: p = new Superb(std::rand() % 100); break;
	case 2: p = new Magnificent(std::rand() % 100, 'A' + std::rand() % 26); break;
	}
	return p;
}