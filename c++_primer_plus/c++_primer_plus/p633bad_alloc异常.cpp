// ����		2013.12.13.19
// ��ϰ		2014.08.15.11  # 1

// ��ǰ���޷������ڴ��ʱ��, new����һ����ָ��, �������ڽ����׳��쳣, pt = new... pt�൱��û���յ���ֵ, ��Ϊnew������throw�����쳣, ����ջ����ֱ��������try��Ľ�β, pt���Ǵ���δ��ʼ����״̬, �������������쳣, ִ��״̬��: abort()������ , ����״̬��: ָ������һ��δ������쳣������, bad_alloc...   # 1
// ����ʹ��new (std::nothrow) Big[10000]ָ��ʹ�÷���nullptr�İ汾 # 1

#include <iostream>
#include <new>  // ������bad_alloc�������, ���Ǵ�exception�๫������������
#include <cstdlib>
using namespace std;

struct Big
{
	double stuff[20000];
};

int main(void)
{
	Big * pb;

	if (new (std::nothrow) Big[10000] == nullptr)	// # 1
		cout << "����ʹ��new (std::nothrow) Big[10000]ָ��ʹ�÷���nullptr�İ汾\n\n";

	try
	{
		cout << "Trying to get a big block of memory:\n";
		pb = new Big[10000];  // 16 0000 0000 bytes
		cout << "Got past the new request:\n";
	}
	catch (bad_alloc & ba)	// ������������ʱ����, Ȼ��������ʱ���� # 1
	{
		/*if (pb == nullptr)
			cout << "��һ�ֱ�׼�Ƿ���NULL\n";
		else
			cout << "��һ�ֱ�׼û��\n";*/
		cout << "Caught the exception!\n";
		cout << ba.what() << endl;
		exit(EXIT_FAILURE);
	}
	catch(...)	// �����д��һ��������һ�������ĺ���, �㲢��֪�������ú����������������Щ�쳣, ��ʱ����Ȼ�ܹ������쳣, ������ʹ��ʡ�Ժ�����ʾ�쳣����, �Ӷ������κ��쳣 # 1
	{
		cout << "����try������ĺ���֮��Ĵ��۸��ӵĺ�������, ������δ֪���쳣, ʹ��catch(...)������\n";
	}

	cout << "Memory successfully allocated\n";
	pb[0].stuff[0] = 4;
	cout << pb[0].stuff[0] << endl;
	delete [] pb;

	return 0;
}