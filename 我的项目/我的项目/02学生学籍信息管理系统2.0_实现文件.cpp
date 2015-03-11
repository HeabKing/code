#include "02ѧ��ѧ����Ϣ����ϵͳ2.0_ͷ�ļ�.h"
Student::Student()
{
	mode = Info;
	is_info = Empty;
	is_gra = Empty;
}

void Student::set_info()
{
	cout << "ѧ��: ";
	cin >> Stu.stuInfo.number;
	cout << "����: ";
	cin >> Stu.stuInfo.name;
	cout << "�Ա�: ";
	cin >> Stu.stuInfo.sex;
	cout << "�绰: ";
	cin >> Stu.stuInfo.tel;
	cout << "����: ";
	cin >> Stu.stuInfo.domNum;
	is_info = Full;
}

void Student::set_gra()
{
	if (is_info == Empty)
		cout << "��������ѧ���Ļ�����Ϣ!\n";
	else
	{
		Stu.stuGra[0].courseName = "��ѧ";
		Stu.stuGra[1].courseName = "Ӣ��";
		Stu.stuGra[2].courseName = "�������";
		for (int i = 0; i < courseNum; i++)
		{
			cout << Stu.stuGra[i].courseName << "�ɼ�¼��:\n";
			cout << "\tƽʱ�ɼ�: ";
			cin >> Stu.stuGra[i].triGrade;
			cout << "\t����ɼ�: ";
			cin >> Stu.stuGra[i].examGrade;
			Stu.stuGra[i].totalGrade = Stu.stuGra[i].triGrade * 0.3
				+ Stu.stuGra[i].examGrade * 0.7;
			is_gra = Full;
		}
	}
}

void Student::show_info(ostream & os) const
{
	if (is_info == Full)
	{
		os << "ѧ��: " << Stu.stuInfo.number;
		os << "   ����: " << Stu.stuInfo.name;
		os << "   �Ա�: " << Stu.stuInfo.sex;
		os << "   ����: " << Stu.stuInfo.domNum;
		os << "   �绰: " << Stu.stuInfo.tel << endl;
	}
	else if (is_info == Empty)
		os << "ѧ��������Ϣ�ǿյ�.\n";

}

void Student::show_gra(ostream & os) const
{
	if (is_info == Empty)
		os << "ѧ��������ϢΪ��, �޷���ʾ�ɼ�\n";
	else if (is_gra == Full)
		for (int i = 0; i < courseNum; i++)
		{
			os << Stu.stuGra[i].courseName << "�ɼ�:\n";
			os << "   ƽʱ�ɼ�: " << Stu.stuGra[i].triGrade;
			os << "   ����ɼ�: " << Stu.stuGra[i].examGrade;
			os << "   �ۺϳɼ�: " << Stu.stuGra[i].totalGrade << endl;
		}
	//else if (is_gra == Empty)
	//	os << "ѧ���ɼ�Ϊ��.\n";
}

void Student::GetFileGra(istream & is, Student & s)
{
	string temp;
	if (is >> temp)  // ��ֹ���ļ�ִ��s.is_info = Full;
	{
		is >> s.Stu.stuInfo.number;
		is >> temp;is >> s.Stu.stuInfo.name;
		is >> temp;is >> s.Stu.stuInfo.sex;
		is >> temp;is >> s.Stu.stuInfo.domNum;
		is >> temp;is >> s.Stu.stuInfo.tel;
		s.is_info = Full;
	}
	const string tt[courseNum] = {"��ѧ", "Ӣ��", "�������"};
	for (int i = 0; is >> temp && temp != "----------------------------"; i++)
	{
		s.Stu.stuGra[i].courseName = tt[i];
		is >> temp;is >> s.Stu.stuGra[i].triGrade;
		is >> temp;is >> s.Stu.stuGra[i].examGrade;
		is >> temp;is >> s.Stu.stuGra[i].totalGrade;
		s.is_gra = Full;
		s.mode = Info_and_Gra;
	}
}

istream & operator>>(istream & is, Student & s)
{
	if (is == cin)
	{
		if (s.mode == s.Info)
			s.set_info();
		else if (s.mode == s.Gra)
			s.set_gra();
		else if (s.mode == s.Info_and_Gra)
		{
			s.set_info();
			s.set_gra();
		}
	}
	else
		s.GetFileGra(is, s);
	
	return is;
}

ostream & operator<<(ostream & os, const Student & s)
{
	if (s.mode == s.Info)
		s.show_info(os);
	else if (s.mode == s.Gra)
		s.show_gra(os);
	else if (s.mode == s.Info_and_Gra)
	{
		s.show_info(os);
		s.show_gra(os);
	}
	os << "----------------------------";  // �����ֶ�ȡ�����Ҫ����
	os << '\n';
	return os;
}