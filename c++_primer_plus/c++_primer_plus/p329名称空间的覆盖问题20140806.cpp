// ����: 2014-08-06
#include <iostream>
using namespace std;
namespace Ui { typedef int A; }
typedef double A;
typedef A AA;
namespace Ui{ typedef AA B; }	// ������Ҫʹ���ⲿA�Ͱ��ⲿA�����AAȻ��������ʹ��AA��
int main()
{
	Ui::B temp = 2.34;
	cout << temp << endl;
}