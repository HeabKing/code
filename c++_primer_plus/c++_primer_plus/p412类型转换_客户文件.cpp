// �����嵥 11.18 �ͻ��ļ�
#include <iostream>
using std::cout;
#include "p411����ת��.h"
void display(const Stonewt & st, int n);
int main()
{
	Stonewt incognito = 275;  // uses constructor to initialize
	Stonewt wolfe(285.7);  // same as Stonewt wolfe = 285.7
		// ֻ�н���һ�������Ĺ��캯��������Ϊת������, ����Ĺ��캯��
	Stonewt taft(21, 8);

	cout << "The celebrity weighted ";
	incognito.show_stn();
	cout << "The detective weighed ";
	wolfe.show_stn();
	cout << "The President weighed ";
	taft.show_lbs();
	incognito = 276.8;  // uses constructor for conversion
	taft = 325;  // same as taft = Stonewt(325); use Stonewt(325) to convert(ת��, ʹת��) 325 to Stonewt
		// ����ʹ�ù��캯��Stonewt(double)������һ����ʱ��Stonewt����, ����19.6��Ϊ��ʼ��ֵ, ��� �������Ա��ֵ��ʽ������ʱ�������ݸ��Ƶ�taft��, ��һ���̳�Ϊ��ʽת��, ��Ϊ�����Զ����е�, ����Ҫ��ʾǿ������ת��
	cout << "After dinner, the celebrity weighed ";
	incognito.show_stn();
	cout << "After dinner, the President weighed ";
	taft.show_lbs();
	display(taft, 2);
	cout << "The wrestler weighed even more.\n";
	display(422, 2);
	cout << "No stone left unearned\n";

	return 0;
}

void display(const Stonewt & st, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Wow! ";
		st.show_stn();
	}
}