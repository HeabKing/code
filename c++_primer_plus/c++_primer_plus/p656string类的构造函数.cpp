#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string one("Lottery Winner!");  // ctor #1
	cout << one << endl;  // ����<<
	string two(20, '$');  // ctor #2 ����һ������20��Ԫ�ص��ַ���, ÿ���ַ�����ʼ��Ϊ'$'
	cout << two << endl;
	string three(one);  // ctor #3 ʹ�ø��ƹ��캯��
	cout << three << endl;
	one += " Oops";  // ���� +=
	cout << one << endl;
	two = "Sorry! That was ";
	three[0] = 'P';
	string four;  // actor #4  Ĭ�Ϲ��캯�� ����һ������Ϊ0��string����
	four = two + three;
	cout << four << endl;
	char alls[] = "All's well that ends well";
	string five(alls, 20);  // ator #5 ��string�����ʼ��Ϊsָ���NBTS(�Կ��ַ������Ĵ�ͳC�ַ���)��ǰn���ַ���, ��ʹ������NBTS��β, ��������˻�"����������"
	cout << five << "!\n";
	string six(alls+6, alls+10);  // ctor #6 ��alls+6��ʼ(����), ��alls+10����(������)
	cout << six << ", ";
	string seven(&five[6], &five[10]);  // ctor #6 again [begin, end)
				// �������ֲ��ῴ���Ƕ���ĵ�ַ, ����five+6��û�������
	cout << seven << "...\n";
	string eight(four, 7, 16);  // cotr #7  ��λ��7��ʼ��n���ַ����β(���������'\0'�����ֱ�ӵ���βֹͣ)
	cout << eight << " in motion!" << endl;

	return 0;
}