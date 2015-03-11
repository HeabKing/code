#include <iostream>
#include <string>
#ifndef TV_H
#define TV_H
class Tv
{
private:
	int state;  // on or off
	int volume;  // ����
	int maxchannel;  // ����Ƶ����
	int channel;  // ��ǰ�㲥Ƶ����
	int mode;  // ���߽��� or �㲥����
	int input;  // TV or DVD
public:
	friend class Remote;  // ������Ԫң������, ���ڹ��л���˽�ж���һ����
	enum {Off, On};
	enum {MinVol, MaxVol = 20};  // �������, ��С����
	enum {Antenna, Cable};  // ����, �㲥
	enum {TV, DVD};

	Tv(int s = Off, int mc = 125) : state(s), volume(5),
		maxchannel(mc), channel(2), mode(Cable), input(TV) {}
	void onoff() {state = (state == On) ? Off : On;}  // ���ػ�
	bool ison() const {return state == On;}
	bool volup();  // ������
	bool voldown();  // ������
	void chanup();  // ��Ƶ��
	void chandown();  // ��Ƶ��
	void set_mode() {mode = (mode == Antenna) ? Cable : Antenna;} // ���� �㲥ת��
	void set_input() {input = (input == TV) ? DVD : TV;}  // DVD TVת��
	void settings() const;  // �����ǰ����

	bool RemoteMoshi(Remote & r) const;
};

class Remote
{
private:
	int mode;  // TV or DVD
	enum {changgui, hudong};
	int moshi;
public:

	friend class Tv;

	Remote(int m = Tv::TV, int ms = Remote::changgui) : mode(m), moshi(ms) {}
	bool volup(Tv & t) {return t.volup();}
	bool voldowl(Tv & t) {return t.voldown();}
	void onoff(Tv & t) {t.onoff();}
	void chanup(Tv & t) {t.chanup();}
	void chandown(Tv & t) {t.chandown();}
	void set_chan(Tv & t, int c) {t.channel = c;}  // ֻ�����������˽�е����ݳ�Ա
	void set_mode(Tv & t) {t.set_mode();}
	void set_input(Tv & t) {t.set_input();}
	std::string Moshi() const {return moshi == changgui ? "����ģʽ" : "����ģʽ";}
};

inline bool Tv::RemoteMoshi(Remote & r) const  // �������ֱ��д�������ĵط�(Tv���ڲ�)�����Ƿ���Remote�����Ļ��ڱ����ʱ��ᱨ��˵û�ж���Remote��, ��Ϊr.moshi...����Tv���ʱ���ǲ��ɼ���
{
	if (state == On) 
	{                                 //  ��̬���ò������ض��Ķ����Ӧ, �������ﲻ��д��r.hudong����д��Remote::hudong
		r.moshi == Remote::changgui ? r.moshi = Remote::hudong : r.moshi = Remote::changgui;
		return true;
	}
	else 
		return false; 
}

#endif

bool Tv::volup()
{
	if (volume < MaxVol)
	{
		volume++;
		return true;
	}
	else
		return false;
}

bool Tv::voldown()
{
	if (volume > MinVol)
	{
		volume--;
		return true;
	}
	else
		return false;
}

void Tv::chanup()
{
	if (channel < maxchannel)
		channel++;
	else
		channel = 1;
}

void Tv::chandown()
{
	if (channel > 1)
		channel--;
	else 
		channel = maxchannel;
}

void Tv::settings() const
{
	using std::cout;
	using std::endl;
	cout << "Tv is " << (state == Off ? "Off" : "On") << endl;
	if (state == On)
	{
		cout << "Volume setting = " << volume << endl;
		cout << "Channel setting = " << channel << endl;
		cout << "Mode = " << (mode == Antenna ? "antenna" : "cable") << endl;
		cout << "Input = " << (input == TV ? "TV" : "DVD") << endl;
	}
}

int main(void)
{
    Tv s20;
    std::cout << "Initial settings for 20\" TV:\n";
    s20.settings();
    s20.onoff();
    s20.chanup();
    std::cout << "\nAdjusted settings for 20\" TV:\n";
    s20.settings();

    Remote grey;

    grey.set_chan(s20, 10);
    grey.volup(s20);
    grey.volup(s20);
    std::cout << "\n20\" settings after using remote\n";
    s20.settings();

    Tv s27(Tv::On);
    s27.set_mode();
    grey.set_chan(s27,28);
    std::cout << "\n27\" settings:\n";
    s27.settings();
	std::cout << 1111111111111 << std::endl; 
    std::cout << grey.Moshi() << std::endl;    // check mode
	s27.RemoteMoshi(grey);         // change mode
	std::cout << grey.Moshi() << std::endl;   // recheck mode
    s27.onoff();            // turn set off
	s27.RemoteMoshi(grey);        // try changing mode again
	std::cout << grey.Moshi() << std::endl;     // check result

    return 0;
}