#include <iostream>

	// ����һ��ʸ����

class Vector
{
private:
	double x, y;	// ֱ�������ʾ
	double ang, dis;// �������ʾ
	
	void Setxy();
	void Setangdis();
public:
	Vector(){x = y = ang = dis = 0.0;};

	void	SetXY(double x, double y){this->x = x; this->y = y; Setangdis();}
	void	SetAngDis(double ang, double dis){this->ang = ang; this->dis = dis; Setxy();}
	double	Getx(void) const {return x;}
	double	Gety(void) const {return y;}
};

#include <ctime>
#include <fstream>
int main(void)
{
	using std::cout;
	using std::endl;
	using std::cin;
	srand((unsigned long)time(0));

	double x = 0, y = 0, step, dis;
	Vector V;

	std::ofstream fcout;
	fcout.open("p422�����������.txt");

	cout << "���벽��: ";
	cin >> step;
	cout << "�������: ";
	cin >> dis;
	fcout << "����: " << step << "����: " << dis << endl;
	int i;
	for(i = 0; 1; i++)
	{
		V.SetAngDis(rand() % 360, step);
		x += V.Getx();
		y += V.Gety();
		fcout << i << ": (x, y) = (" << x << ',' << y << ")" << endl;
		if (sqrt(x * x + y * y) >= dis)
			break;
	}
	fcout << "���� " << i << " ��, �������� " << sqrt(x * x + y * y) << "��ֱ�߾���!\n";
	cout << "д���ļ����\n";
	return 0;
}

#include <cmath>
#define  TWOPIE		(2 * 3.1415926)
void Vector::Setxy()
{
	x = dis * cos(TWOPIE * ang / 360);
	y = dis * sin(TWOPIE * ang / 360);
}

void Vector::Setangdis()
{
	dis = sqrt(x * x + y * y);
	ang = atan2(y, x);
}