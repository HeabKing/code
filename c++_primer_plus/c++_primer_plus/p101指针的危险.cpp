// �Լ��ܽ�
// ����ָ��δ��ʼ����Σ��
#include <iostream>
int main()
{
	using namespace std;
	int * inputPtr;   // ����һ��ָ��, ����ָ����ڴ�ռ�
					  // ������û�г�ʼ��, ���Բ�û�и�ָ��ָ���int�����ڴ�ռ�
	*inputPtr = 222;  // 222���᲻֪����������
	cout << inputPtr << endl;

	return 0;
}