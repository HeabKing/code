// �����嵥 6.15
// ��������ʾ����Ļ�Ϻʹ��浽�ļ���
#include <iostream>
#include <fstream>
int main()
{
	using namespace std;

	char automobile[50];
	int year;
	double a_price;
	double d_price;

	ofstream outFile;          // ����ofstream��Ķ���
	outFile.open("p192�ļ����.txt");// ��outFileͬһ���ļ���������, Ĭ����û�оʹ���, �о�����д������

	cout << "Enter the make and model of auto automobile: ";
	cin.getline(automobile, 50);
	cout << "Enter the model year: ";
	cin >> year;
	cout << "Enter the original asking price: ";
	cin >> a_price;
	d_price = 0.913 * a_price;

// display information on screen with cout

	cout << fixed; // ��һ�㷽ʽ��������������ǿ�ѧ������
	cout.precision(2); // precision ׼ȷ�� ׼ȷ��
	cout.setf(ios_base::showpoint);
	cout << "Make and model: " << automobile << endl;
	cout << "Year: " << year << endl;
	cout << "Was asking $" << a_price << endl;
	cout << "Now asking $" << d_price << endl;

// Now do exact same things using outFile instead of cout

	outFile << fixed;
	outFile.precision(2);
	outFile.setf(ios_base::showpoint);
	outFile << "Make and model: " << automobile << endl;
	outFile << "Year: " << year << endl;
	outFile << "Was asking $" << a_price << endl;
	outFile << "Now asking $" << d_price << endl;

	return 0;
}