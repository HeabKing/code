#include "02ѧ��ѧ����Ϣ����ϵͳ2.0_ͷ�ļ�.h"
#include <fstream>
#include <cstdlib>
#include <windows.h>

int getlet(const char *);  // �ݴ�ѡ��
int getMainMenu();  // ��Ϣ/�ɼ�����ѡ�� 
void showStuArray(const Student *);  // ��ʾStudent������Ϣ
void coutNumAndName(const Student &, int = 0);
int getSQLmenu();  // �Ĵ����ѡ��
void Add(Student *);  // �Ĵ����֮��(������Ϣ)
int getNum(const Student *, int = 0);  // ѡ��ѧ��
void SiDaYuJu(void (&)(Student *), Student *);  // ���Ĵ���亯��������
void Delete(Student *);  // �Ĵ����֮ɾ(������Ϣ)
void Change(Student * s){cin >> *s;}  // �Ĵ����֮��(������Ϣ)
void Find(Student * s){cout << *s;}  // �Ĵ����֮��(������Ϣ)
void stuArrayDESC(Student *);  // ��ѧ�Ŵ�С��������

int main()
{
	const char * fileName = "02ѧ��ѧ����Ϣ����ϵͳ2.0.txt";
	ifstream fin;
	Student stu[100];
	int choice;
	int i = 0;
	SetConsoleTitleA("ѧ����Ϣ����ϵͳ2.0  by: ����");
// ��ȡģʽ���ļ�
	fin.open(fileName);
	if (!fin.is_open())
	{
		cout << "�޷����ļ�: " << fileName << endl;
		cout << "���򽫻��˳�.\n";
		exit(EXIT_FAILURE);
	}

// ���ļ��е�ѧ����Ϣ���浽stu������
	for (i = 0; fin >> stu[i]; i++);
	
// ѡ�����
	while ('4' != (choice = getMainMenu()))
	{
		system("cls");
		// ��ģʽѡ��
		for (int i = 0; i < 100; i++)
			if (choice == '1')
				stu[i].mode = stu[i].Info;
			else if (choice == '2')
				stu[i].mode = stu[i].Gra;
			else if (choice == '3')
			{
				stu[i].mode = stu[i].Info_and_Gra;
				if (stu[i].is_info == stu[i].Full)
					cout << stu[i];
			}
		if (choice == '3')
			continue;
		// ��ʾ������Ϣ/�ɼ���Ϣ
		showStuArray(stu);
		// �Ĵ�������
		switch (getSQLmenu())
		{
		case '1':
			if (choice == '1')
				Add(stu);
			else if (choice == '2')
				SiDaYuJu(Add, stu);
			break;
		case '2': SiDaYuJu(Delete, stu);break;
		case '3': SiDaYuJu(Change, stu);break;
		case '4': SiDaYuJu(Find, stu);break;
		case '5': break;
		}
	}
// ���浽�ļ���ȥ
	ofstream fout;
	fout.open(fileName);
	stuArrayDESC(stu);
	for (int i = 0; i < 100; i++)
		if (stu[i].is_info == stu[i].Full)
		{
			stu[i].mode = stu[i].Info_and_Gra;
			fout << stu[i];
		}

	return 0;
}

int getlet(const char * str)
{
	char choice;
	while (cin >> choice && strchr(str, choice) == NULL)  // char * strchr(const char * s, int c) �ú�������һ��ָ���ַ���s�д���ַ�c�ĵ�һ��λ�õ�ָ��(��ǽ����Ŀ��ַ����ַ�����һ����, ���Ҳ������������). ���û���ҵ����ַ�, �������ؿ�ָ��NULL
		// cin >> '�ַ�' �в������հ׷�
		cout << "������\""<< str << "\"�е�һ���ַ�." << endl;
	while (cin.get() != '\n')  // �����ɾ��ĺ���, ��Ҫִ��������һ��'\n'�ַ�����������
		continue;
	return choice;
}

void coutNumAndName(const Student & s, int form)
{
	if (form == 0)
		std::cout << "~~~�����ǿ��Խ�����ѡ������ѧ��~~~~\n";
	cout << "------\nNo.: " << s.StuNum();
	cout << "  Name: " << s.StuName();
	cout << "\n------\n";
}

int getMainMenu()
{
	cout << "1> ѧ��������Ϣ����   2> ѧ���ɼ���Ϣ����"
		"   3> �鿴����   4> �˳�\n";
	cout << "-----------------------------------------------------\n";
	return getlet("1234");
}

void showStuArray(const Student * s)
{
	for (int i = 0; i < 100; i++)
		if (s[i].mode == s[i].Info &&
			s[i].is_info == s[i].Full)
			cout << s[i];
		else if (s[i].mode == s[i].Gra &&
			s[i].is_gra == s[i].Full)
		{
			cout << "--> No.: " << s[i].StuNum() 
				<< "   Name: " << s[i].StuName()  << endl;
			cout << s[i];
		}
}

int getSQLmenu()
{
	cout << "1> ��  2> ɾ  3> ��  4> ��  5> ����\n";
	cout << "----------------------------------\n";
	return getlet("12345");
}

void Add(Student * s)
{
	int j = 0;
	if (s->mode == s->Info)
		for (int i = 0; i < 100; i++)
			while (s[i].is_info == s[i].Empty)
			{
				cin >> s[i];
				cout << "1> �������  2> ֹͣ���\n";
				if ('2' == getlet("12"))
				{
					i = 100;
					break;
				}
			}
	else if (s->mode == s->Gra)
		for (int i = 0; i < 100; i++)
			while (s[i].is_info == s[i].Full 
				&& s[i].is_gra == s[i].Empty)
			{
				cin >> s[i];
				cout << "1> �������  2> ֹͣ���\n";
				if (getlet("12") == '1')
				{
					for (j = i; j < 100; j++)
						if (s[i].is_info == s[i].Full &&  // ����еȴ����ѧ���ɼ�����
							s[i].is_gra == s[i].Empty)
							break;
					if (j == 100)
					{
						cout << "!!!ע��: û�п���ִ�еĶ�����,"
							"�Զ�ѡ��Ϊ\"ֹͣ���\"!!!\n";
						i = 100;  // �������forѭ��
						break;  // �����ڲ�whileѭ��
					}
				}
				else
				{
					i = 100;
					break;
				}
			}
}

int getNum(const Student * s, int form)  // formĬ��Ϊ0, �����ı�Ϊ1��ʱ����е���gra����ѧ��ѡ��
{
	int num[100];
	int num2[100] = {-1};
	int i = 0;
	int flag = 0;
	int temp;
	for (int j = 0; j < 100; j++)
		if (s[j].mode == s[j].Info   // Ϊinfo��ɾ, ��, ����׼��, ֻ��ģʽ��info, �л�����Ϣ��ʱ����ܽ������������(ѧ�Ų��ܱ�ѡ��)
			&& s[j].is_info == s[j].Full)
		{
			coutNumAndName(s[j], flag++);
			num[i++] = s[j].StuNum();
		}
		else if (s[j].mode == s[j].Gra  // Ϊgra������׼��, ֻ��ģʽ��gra, ������Ϣ����, û�гɼ���Ϣ��ʱ��ѧ�Ųſ��Ա�ѡ��
			&& s[j].is_info == s[j].Full)
			if (s[j].is_gra == s[j].Empty && form == 1)  // gra��ģʽ
			{
				coutNumAndName(s[j], flag++);
				num[i++] = s[j].StuNum();
			}
			else if (s[j].is_gra == s[j].Full && form == 0)  // gra ɾ�Ĳ� ģʽ
			{
				coutNumAndName(s[j], flag++);
				num2[i++] = s[j].StuNum();  // # 1
			}
	if (num2[0] != -1)  // �ж� # 1 �Ƿ�ִ��
		for (int i = 0; i < 100; i++)
			num[i] = num2[i];
	cout << "�������ѧ����ѧ��: ";
	while (cin >> temp)
	{
		for (int i = 0; i < 100; i++)
		{
			if (temp == num[i])
				return temp;
		}
		cout << "�����ڿɲ���ѧ��, ����������: ";
	}
	return 999;  // �����ܵķ���ֵ, ���������
}

void SiDaYuJu(void (&yuju)(Student *), Student * s)
{
	int num;
	if (yuju == Add && s->mode == s->Gra)  // gra��ģʽ
		num = getNum(s, 1);
	else
		num = getNum(s);
	for (; s->StuNum() != num; s++);  // Ѱ��ѡ��ѧ����λ��
	yuju(s);  // ִ��ѡ����Ĵ����֮һ
	cout << "ok!\n";
}

void Delete(Student * s)
{
	if (s->mode == s->Info)
		s->is_info = s->Empty;
	else if (s->mode == s->Gra)
		s->is_gra = s->Empty;
}

void stuArrayDESC(Student * s)
{
	Student temp;
	for (int i = 0; i < 99; i++)
		for (int j = i; j < 100; j++)
			if (s[i].StuNum() > s[j].StuNum())
			{
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
}