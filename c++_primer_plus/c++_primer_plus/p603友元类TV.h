#include <iostream>
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
};

class Remote
{
private:
	int mode;  // TV or DVD
public:
	Remote(int m = Tv::TV) : mode(m) {}
	bool volup(Tv & t) {return t.volup();}
	bool voldowl(Tv & t) {return t.voldown();}
	void onoff(Tv & t) {t.onoff();}
	void chanup(Tv & t) {t.chanup();}
	void chandown(Tv & t) {t.chandown();}
	void set_chan(Tv & t, int c) {t.channel = c;}
	void set_mode(Tv & t) {t.set_mode();}
	void set_input(Tv & t) {t.set_input();}
};

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