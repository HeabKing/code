// �����嵥 9.6
#include <iostream>
extern double warming; // use waiming from another file
int i;
// function prototypes
//void update(double);
//void local();
	// �����������ԭ�Ͳ����, ���ǲ�����Ҳ��Ӱ��

using std::cout;
void update(double dt) // modifies global varible
{
	extern double warming;  // optional redeclaration
		// �������Ƕ��ⲿ�����Ķ������� �������ֻ�Ա������ɼ� ���Ǹ��ĵ�ֵ����Ӱ���ⲿ����warming
	warming += dt;         // uses gloabal warming
	cout << "Updating global warming to " << warming;
	cout << " degrees.\n";
}

void local()
{
	double warming = 0.8;  // new varible hides extern one
	cout << "Local warming = " << warming << " degrees.\n";
	// Access global varible with the scope resolution operator
	cout << "But global warming = " << ::warming << "degrees.\n";
								// :: �������������� ��ʹ�ñ����ص�warming���Ա�����
}