// �����嵥 3.6
// cout.put();��cout���ַ���ʶ�����
#include <iostream>
int main()
{
	using namespace std;
	char ch = 'M';
	int i = ch;
	cout << ch << "��ascll����Ϊ: " << i << endl;
	cout << "����һ�Ժ�:" << endl;
	ch = ch + 1;
	i = ch;
	cout << ch << "��ascll����Ϊ: " << i << endl;

	cout << "ʹ��cout.put()��������ַ�:" << endl;
	cout.put(ch); // ��㱻��Ϊ��Ա�����
	cout.put('|');
	cout << endl << "---------" << 'm' << "-------------" << endl;
	// ��ʱ�������'m'������m��asill���ֵ, �������ڵ�c��'m'����������
	// int��, ����cout��˵, ��ֻ��ʶ8λ��char������ʶ32λ��int, ��������������int��������ǵ���
	// �ַ����, ���о͵�����cout.put(), ���Ǻ�����c��ʵ���˰��ַ�����m������char����, ���Լ�ʹ
	// ����cout.put()Ҳ�������
	cout << sizeof('m') << endl;

	cout << endl << "Done!" << endl;
	// cout << "Let them eat g\u00E2teau." << endl;
	// �鿴�Ƿ�֧����չ�ַ���     ��֧��

	return 0;
}