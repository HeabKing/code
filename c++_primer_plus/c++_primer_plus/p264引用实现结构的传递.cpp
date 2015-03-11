// �����嵥 8.6
#include <iostream>
#include <string>
struct free_throws
{
	std::string name;
	int made;
	int attempts;
	float percent;
};

void display(const free_throws & ft);
void set_pc(free_throws & ft);
free_throws & accumulate(free_throws & target, const free_throws & source);

int  main()
{
	free_throws one = {"Ifelsa Branch", 13, 14}; // ����û�г�ʼ��percent �������ڳ�ʼ���Ĺ����б�����Ϊ0
	free_throws two = {"Andor Knott", 10, 16};
	free_throws three = {"Minnie Max", 7, 9};
	free_throws four = {"Whily Looper", 5, 9};
	free_throws five = {"Long Long", 6, 14};
	free_throws team = {"Throwgoods", 0, 0};
	free_throws dup;

	set_pc(one);
	display(one);
	accumulate(team, one);
	display(team);
	// ʹ��return�����ýṹ����
	display(accumulate(team, two));
	accumulate(accumulate(team, three), four);
	display(team);
	dup = accumulate(team, five); // ���ﷵ�ص�������, ֱ�ӽ�temp��ֵ����dup ������ص��ǽṹֵ�Ļ� ��ôaccumulate()���Ȱѷ���ֵ����һ��δ��������ʱ�ṹ��������, Ȼ���ڰ���ʱ�ṹ��������dupЧ�ʵ�, �ڴ��˷�
	std::cout << "Display team:\n";
	display(team);
	std::cout << "Display dup after assignment:\n";
	display(dup);

	set_pc(four);
	// ����ĸ�ֵ
	accumulate(dup, five) = four; // ������ﷵ�ص��ǽṹ�����Ļ���ֵ�������, ��Ϊ���صĽṹ����������һ��δ��������ʱ��������, ����ֱ����ʾ��������ֵ����5, ��ô5=3�Ǵ����---------(�Լ��Ʋ�Ĳ�֪���Բ���)
	std::cout << "Display dup after ill-addvised assignment:\n";
	display(dup);

	return 0;
}

void display (const free_throws & ft)
{
	using std::cout;
	cout << "Name: " << ft.name << '\n';
	cout << "  Made: " << ft.made << '\t';
	cout << "Attempts: " << ft.attempts << '\t';
	cout << "Percent: " << ft.percent << '\t' << '\n';
}
void set_pc(free_throws & ft)
{
	if (ft.attempts != 0)
		ft.percent = 100.0f * float(ft.made) /
		float(ft.attempts);
	else
		ft.percent = 0;
}
free_throws & accumulate(free_throws & target, const free_throws & source)
{
	target.attempts += source.attempts;
	target.made += source.made;
	set_pc(target);
	return target;   // �������õ�ʱ��Ҫע�������: Ӧ�ñ��ⷵ�غ�����ֹ��ʱ���ٴ��ڵ��ڴ浥Ԫ������, ��: free_throws & aaa = target; return aaa;����ִ����ɺ��������ٴ���, �����ڵĶ�������ô����? �������������: 1. ������Ϊ�������ý����ı���, �籾��������������  2.ʹ��new��̬�����ڴ�
}