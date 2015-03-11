#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

class Person
{
private:
	string firstname;
	string lastname;
public:
	Person(const string & f = "Null", const string & l = "Null") : firstname(f), lastname(l) {}
	virtual ~Person() {}  // �������Ǳ����!!!!!!!!!!!!
	virtual void show(void) const {cout << firstname << " " << lastname;}
	virtual void set() {cout << "Enter firstname: "; cin >> firstname; cout << "Enter lastname: "; cin >> lastname;}
};

class Gunslinger : virtual public Person
{
private:
	double draw;  // ���ֵİ�ǹʱ��
	int kehen;  // ǹ�ϵĿ̺���
public:
	Gunslinger(const string & f = "Null", const string & l = "Null", const double & d = 0.0, const int & k = 0) : draw(d), kehen(k), Person(f, l) {}
	Gunslinger(const Person & p, double d = 0.0, int k = 0) : Person(p), draw(d), kehen(k) {}
	double Draw(void) const {return draw;}
	void show(void) const {Person::show(); cout << "\n��ǹʱ��: " << draw << "\t�̺���: " << kehen << endl;}
	void set() {Person::set(); cout << "Draw Time: "; cin >> draw; cout << "Kehen: "; cin >> kehen;}
};

class PokerPlayer : virtual public Person
{
public:
	int Draw() const {srand(time(0));return rand() % 52 + 1;}  // ����1-52�����ֵ��ʾ52���˿���
	PokerPlayer(const string & f = "Null", const string & l = "Null") : Person(f, l) {}
	PokerPlayer(const Person & p) : Person(p) {}
};

class BadDude : public Gunslinger, public PokerPlayer
{
public:
	BadDude(const string & f = "Null", const string & l = "Null", const double & d = 0.0, const int & k = 0) : Person(f, l), Gunslinger(f, l, d, k) {} // : Gunslinger(f, l, d, k) {} ��Ϊ����Ϊ�������, ������ô�õĻ�Person���õ���Ĭ�ϵĹ��캯��, firstname����Null��
	BadDude(const Person & p, const double & d = 0.0, const int & k = 0) : Person(p), Gunslinger(p, d, k) {}
	double Gdraw(void) const {return Gunslinger::Draw();}  // ����Gunslinger��PokerPlayer�е�Draw()������, ����Ҫ�����������������ȷ��λ
	int Cdraw(void) const {return PokerPlayer::Draw();}
	void show(void) {Gunslinger::show();}
	void set() {Gunslinger::set();}
};

const int SIZE = 5;
int main(void)
{
    using namespace std;
    int ct, i;
    Person * gang[SIZE];
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the gang category:\n"
            << "o: ordinary person  g: gunslinger  "
            << "p: pokerplayer  b: bad dude  q: quit\n";
        cin >> choice;
        while (strchr("ogpbq", choice) == NULL)
        {
            cout << "Please enter an o, g, p, b, or q: ";
            cin >> choice;
        }
        if (choice == 'q')
            break;
        switch(choice)
        {
            case 'o':   gang[ct] = new Person;
                        break;
            case 'g':   gang[ct] = new Gunslinger;
                        break;
            case 'p':   gang[ct] = new PokerPlayer;
                        break;
            case 'b':   gang[ct] = new BadDude;
                        break;
        }
        cin.get();
        gang[ct]->set();
    }

    cout << "\nHere is your gang:\n";
    for (i = 0; i < ct; i++)
    {
        cout << '\n';
        gang[i]->show();
    }
    for (i = 0; i < ct; i++)
        delete gang[i];
    cout << "\nBye!\n";
    return 0;
}
