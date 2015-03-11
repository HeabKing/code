// �����嵥 8.8
// ����: 1. ���������ʹ�û�������� 2. �������ÿ���ָ�������������������ǿ������ת��
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void file_it(ostream & os, double fo, const double fe[], int n);
const int LIMIT = 5;
int main()
{
	ofstream fout;
	const char * fn = "p272��΢������.txt";
	fout.open(fn);
	if (!fout.is_open())
	{
		cout << "Can't open " << fn << ". Bye!";
		exit(EXIT_FAILURE);
	}
	double objective;
	cout << "Enter the focal length of your "
		"telescope objective in mm: ";
	cin >> objective;
	double eps[LIMIT];
	cout << "Enter the focal length, in mm, of " << LIMIT << " eyepieces:\n";
	for (int i = 0; i < LIMIT; i++)
	{
		cout << "Eyepiece #" << i + 1 << ": ";
		cin >> eps[i];
	}
	file_it(fout, objective, eps, LIMIT);
	file_it(cout, objective, eps, LIMIT);
	cout << "Done\n";

	return 0;
}

void file_it(ostream & os, double fo, const double fe[], int n)
{
	ios_base::fmtflags initial;
	initial = os.setf(ios_base::fixed); // setf()�ܹ��������ø��ָ�ʽ��״̬ setf(ios_base::fixed)����������ʹ�ö����ʾ��ģʽ��
			// setf()���ص�����֮ǰ�ĸ�ʽ������ ios_base::fmtflags �Ǵ���������Ϣ��Ҫ��������������
	os.precision(0); // precision ��ȷ�� ����ģʽ��: ָ����ʾ����λС��
	os << "Focal length of objective: " << fo << " mm\n";
	//os.setf(ios::showpoint); // setf(ios::showpoint) ������������ʾС�����ģʽ, ��С������Ϊ0
	os.precision(1);

	// ���ϵĸ�ʽ�����ö������ֲ���, ֱ���ٴε�����Ӧ�ķ���������������

	os.width(12); // ������һ���������ʹ�õ��ֶο��, ֻ����ʾ��һ��ֵ��ʱ����Ч, Ȼ��ָ���Ĭ������0
	os << "f.1. eyepiece";
	os.width(15);
	os << "magnification" << endl;
	for (int i = 0; i < n; i++)
	{
		os.width(12);
		os << fe[i];
		os.width(15);
		os << int (fo/fe[i] + 0.5) << endl;
	}
	os.setf(initial);
}