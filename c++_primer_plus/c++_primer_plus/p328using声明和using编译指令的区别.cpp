// 1. ���ƿռ�ֻ���ڷǴ�����, ��������������Ĭ��Ϊ�ⲿ(�����������˳���);
// 2. ���ƿռ��ǿ��ŵ�, �����ڲ�ͬ�ļ�����������ͳһ���ƿռ�;
// 3. using namespace Jill; �Ǳ���ָ��, �������Զ�Ϊ����ǰ�����Jill::, Ȼ��using Namespace::n;����������ʱ��, �ͺ�����������Ӧ������һ��, �����������ֲ�����int n��ʱ��������ض���Ĵ���;
#include <iostream>
using namespace std;

namespace Jill{
	double bucket(double n){return n;};
	double fetch;
	struct Hill{
		int a;
		int b;
	};
};

namespace Namespace{
	int n;
};

char fetch;  // ȫ�ֱ���

int main(void)
{
	using namespace Jill;			// �������пռ���
	Hill Thrll;						// �����ṹ��: Jill::Hill
	double water = bucket(2);		// ʹ��Jill::bucket();
	double fetch;					// û�д�, ������Jill::fetch;  // ���ﲻ�ᵼ���ض���Ĵ�
	cin >> fetch;					// local fetch
	cin >> ::fetch;					// global fetch
	cin >> Jill::fetch;				// Jill::fetch

	using Namespace::n;				// ���ｫ�ᱨ���ض���Ĵ�
	int n;
	cin >> n;

	return 0;
}

int foom()
{
	//Hill top;  // Error
	Jill::Hill create;		// valid
}