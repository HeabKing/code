#include <iostream>
#include "�о� - 005��֮dxString��.h"
using std::cout;
using std::cin;

void callme1(dxString &);
void callme2(dxString);

int main(void)
{
	using std::endl;
{
		// ���Ը��ƹ��캯����ʾ��ʼ����ʱ��
	dxString temp("temp");
	dxString a(temp);
	dxString b = temp;				// # 1	����������������ʱ����, Ȼ��ֵ��ʼ���¶���
	dxString c = dxString(temp);	// # 2  ���Ǳ�ʵ����ֱ��ʹ�ø��ƹ���ת������, ��������ʱ����
	dxString * p = new dxString(temp);
	delete p;

	{
		cout << "��һ���������п�ʼ:\n";
		dxString headling1("����headline1");
		dxString headling2("����headline2");
		dxString sports("����sports");
		puts("");

		cout << headling1 << endl;
		cout << headling2 << endl;
		cout << sports << endl;
		puts("");
		
		callme1(headling1);	// ���ô���, ���ᵼ�¶��󱻴���
		cout << headling1 << endl;
		callme2(headling2);	// ֵ����, �µĶ��󱻴���, ���ҽ����������ֵ !��ʼ��! ���¶���
								// ���û�ж�����ȸ��ƹ���ת������, ���ﰴĬ�ϵ�ֱ�Ӹ�ÿ�����ݸ�ֵ��ȥ������, ����, ��ʱ����ʧЧ��ʱ�����������������headling2ָ��ָ��ľ�̬���ַ������ͷ���;
								// ���ض���ͬ����ʹ�ø��ƹ���ת������
								// ����������Ӵ�����ʱ���󱣴��м���
								// ��ʾ��ʼ����ʱ��
		cout << headling2 << endl;
		puts("");

		cout << "��һ�������ʼ������һ��:\n";
		dxString sailor = sports;	// ֱ��ʹ�ø���ת�����캯��
		cout << sailor << endl;
		puts("");

		cout << "��һ������ֵ����һ��:\n";
		dxString knot;
		knot = headling1;	// ���û������ = �Ļ�, �����ֱ�ӳ�Ա��ֵ
		cout << "knot: " << knot << endl;
		puts("");
		
		cout << "�˳�������\n";
	}

}
{
	cout << "\n\n\n\t\t����dxString�ڶ���\n\n";

	dxString name;
	cout << "�����������: ";
	cin >> name;
	if (name == "��ʿ��")
		cout << "���������" << name << endl;
}
	cout << "End of main()\n";

	return 0;
}

void callme1(dxString & rsb)
{
	cout << "�ַ���ͨ�����ô���:\n";
	cout << "    \"" << rsb << "\"\n";
}

void callme2(dxString sb)
{
	cout << "�ַ���ͨ��ֵ����:\n";
	cout << "    \"" << sb << "\"\n";
}