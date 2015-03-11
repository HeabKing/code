#include <iostream>
using namespace std;
#include "p531�����ϰ1_ͷ�ļ�.h"
void Bravo(const Cd & disk);

int main(void)
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in b flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
	Cd * pcd = &c1;

	cout << "\nUsing object directly:\n";
	c1.Report();  // use Cd method
	c2.Report();  // use Classic method

	cout << "\nMsing type cd * pointer to objects:\n";
	pcd->Report();  // use Cd method for cd object

	pcd = &c2;
	pcd->Report();  // use Classic method for classic object

	cout << "\nCalling a function with a Cd reference";
	Bravo(c1);  // use Cd method for cd object
	Bravo(c2);  // use Classic method for classic object

	cout << "\nTesting assignment: ";
	Classic copy;
	copy = c2;
	copy.Report();

// ���Ĭ�Ϲ��캯��ʲô����д�Ļ��ᵼ�����´���"����������..."   ϵͳ�ṩ��Ĭ�Ϲ��캯����������ʲôҲ��д, ����Ҳ�ᵼ��"����������..." 
	/*Classic cop;
	cop.Report();*/

	return 0;
}

void Bravo(const Cd & disk)
{
	disk.Report();
}