// �Լ��ܽ�
#include <iostream>
int main()
{
	using namespace std;
	const int Size = 100;
	char ar1[Size];
	char ar2[Size];

	// getline()��ȡһ��,���ÿ��ַ��滻���з�
	// ����cin.getline(ar1, Size)���ص���cin����, ���Կ������ں���ƴ��һ��getline();
	// ����д��ڵ���Size���ַ���ôֻ�ܶ�ȡSize-1���ַ�, Ȼ��getline()�Ὣʣ�µ��ַ�����������в�����ʧЧλ�ر�����;
	cout << "getline():\n";
	cin.getline(ar1, 10).getline(ar2, 10);
	cout << ar1 << endl << ar2 << endl;

	// get()��ȡһ��, �����������뻻�з�, ���з���������������
	// get()���û�в���, ��ô���͸�getchar()һ�����Զ���һ���ַ�, ��ʹ��һ���ַ��ǻ��з�(���õ��Ǻ�������)
	// get(ar1, size)���ص���һ��cin����, ����cin.get()���صĲ���һ������
	cout << "get():\n";
	cin.get(ar1, Size).get();
	cin.get(ar2, Size);
	cin.get(); // Ϊ�����getline()���ٵ�·
	cout << ar1 << endl << ar2 << endl;

	// ����������е�ʱ����������������
	// getline()��ǰһ����������λ�ÿ�ʼ��ȡ(����ȡ����)
	// get()��ȡ���к�����ʧЧλ, ����ζ�Ž������Ķ�ȡ���ᱻ���
	cout << "getline():\n";
	cin.getline(ar1, Size);
	cout << ar1 << endl;
	cout << "get():\n";
	cin.get(ar1, Size).get();
	cout << ar1 << endl;
	cin.get(ar2, Size);
	cout << ar2 << endl;

	return 0;
}