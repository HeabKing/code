#include <iostream>
// ���ƿռ������ȫ�ֵ�, Ҳ����λ����һ�����ƿռ���, ���ǲ���λ�ڴ������, ���, ��Ĭ�������, �����ƿռ�����������������Ϊ�ⲿ��(�����������˳���);
namespace Jack {
	double pail;            // variable declaration
	void fetch();		   // function prototype
	int pal = 1;				   // variable declaration
	struct Well{int in;};	   // structure declaration
}
namespace Jill {
	double bucket(double){return 0.0;}  // function definition
	double fetch;						 // variable declaration
	int pal;							 // variable declaration
	struct Hill {int in;};				 // structure declaration
	int pp = 222;
}

// ԭ����Jack���ƿռ�Ϊfetch()�����ṩ��ԭ��, �����ڸ��ļ�����(��������һ���ļ���)�ٴ�ʹ��Jack���ƿռ����ṩ�ú����Ĵ���
namespace Jack {
	void fetch()
	{
		int in;
	}
}