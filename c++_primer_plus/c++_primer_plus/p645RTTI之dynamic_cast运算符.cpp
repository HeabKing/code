// ���� 2013 12 16 17
// ��ϰ 2014 08 18 18 # 1

// RTTI(Runtime Type Identification)���н׶�����ʶ��
#include <iostream>
#include <cstdlib>
#include <ctime>
//#include <typeinfo>	// ����dynamic_cast�е�bad_cast�쳣(exception�м̳�)

using std::cout;
class Grand
{
private:
	int hold;
public:
	Grand(int h = 0) : hold(h) {}
	//virtual ~Grand() {} ����û�м������, ��ص���������?????????
	virtual void Speak() const {cout << "I am a grand class;";}	// Grand Superb Magnificent ���ж��� # 1
	virtual int Value() const {return hold;}
};

class Superb : public Grand
{
public:
	Superb(int h = 0) : Grand(h) {} 
	void Speak() const {cout << "I am a superb class!!";}
	virtual void Say() const {cout << "I hold the superb value of " << Value() << "!\n";}	// Superb Magnificent �ж��� # 1
};

class Magnificent : public Superb
{
private:
	char ch;
public:
	Magnificent(int h = 0, char c = 'A') : Superb(h), ch(c) {}
	void Speak() const {cout << "I am a magnificent class.";}
	void Say() const {cout << "I hold the character " << ch << " and the integer " << Value() << "!\n";}
};

Grand * GetOne();

int main()
{
	std::srand(static_cast<unsigned long>(std::time(0)));
	Grand * pg;
	Superb * ps;

		// ����ָ����÷�

	cout << "����ָ�뷵��nullptr: \n\n";
	for (int i = 0; i < 5; i++)
	{
		pg = GetOne();
		pg->Speak();
		if (ps = dynamic_cast<Superb *>(pg))  // ����ǰ�ȫ�ķ�����ָ��, �����ָ��
			// ����ʵ���˶�̬����ʶ��: Superb, Magnificent����ʶ����� # 1
			// ����ʹ�õ��Ƿ���nullptr����ʶ����ʵ�ְ�ȫ��ת��, ���ǵ����������õ�ʱ��, û�����ָ���Ӧ������ֵ, �޷�������ֵ����ʶʧ��, ��ʱ��dynamic_cast����һ����bad_cast�쳣(exception�м̳ж���)
			ps->Say();
	}

		// ������������bad_cast�쳣 # 1

	cout << "\n\n������������bad_cast�쳣:\n\n";
	for (int i = 0; i < 5; i++)
	{
		pg = GetOne();
		Grand & temp = *pg;
		try
		{
			temp.Speak();
			Superb & temp1 = dynamic_cast<Superb &>(temp);	// ���ʧ�ܵĻ�, ����bad_cast�쳣, �±ߵ���䲻ִ��, ֱ������try��Ľ��������� # 1
			temp1.Say();
		}
		catch(std::bad_cast)
		{
			cout << "�����Grand��.\n";
		}
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