// ͷ�ļ�<altorithm>�к���������������, һ����������ֵ֮����ѡ�ϴ���, ��һ������ֵ֮����ѡ��С��, ����������������ֵ
#include <algorithm>
using namespace std;

bool int_ptr_less(int * a, int * b)
{
	return *a < *b;
}

int main()
{
	int x = 17;
	int y = 42;
	int * px = &x;
	int * py = &y;
	int * pmax;

	pmax = std::max(px, py, int_ptr_less);	// px��py���ͱ���һ��, ����std::<long>(); ��������ȷ�˷���ֵ������
}