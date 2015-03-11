// ��Ŭ��-Ī��˹-�������㷨 ��� KMP�㷨
#define KMP

#ifndef KMP
	
	// �����㷨����ַ�����ƥ��

#include <iostream>
int main(void)
{
	char * str = "daxionggege";
	char cinStr[100] = {0};
	std::cin >> cinStr;

	// ��ʼ�����Ƚ�
	char * temp = str;
	while(temp)
	{
		int i;
		for (i = 0; temp[i] && cinStr[i] && temp[i] == cinStr[i]; i++)
		{
			std::cout << temp[i];
		}
		if (!cinStr[i])	// ����Ǳ���������, ��˵���ɹ�ƥ��
		{
			std::cout << "����";
			return 0;
		}
		temp++;
	}

	std::cout << "������";
	return 0;
}

#else

#include <iostream>
using namespace std;

void get_next(string T, int *next);
int  Index_KMP(string S, string T, int pos);

int main(void)
{


	return 0;
}

void get_next(string T, int *next)
{
	int i = 1, j = 0;
	next[1] = 0;
	while (i < T[0])	// �˴�T[0]��ʾ�ַ���T�ĳ���
	{
		if (0 == j || T[i] == T[j])	// T[i] ��ʾ��׺�ĵ����ַ�
									// T[j] ��ʾǰ׺�ĵ����ַ�
		{
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];	// ���ַ�����ͬ, ��jֵ����
	}
}

int  Index_KMP(string S, string T, int pos)
{
	int i = pos;	// i ��������S��ǰλ���±�ֵ, ��pos��Ϊ1, ���posλ�ÿ�ʼƥ��
	int j = 1;		// j �����Ӵ�T�е�ǰλ���±�ֵ
	int next[255];	// ����һ�� next ����
	get_next(T, next);	// �Դ� T ������, �õ�next����
	while (i <= S[0] && j <= T[0])	// ��iС��S�ĳ�����jС��T�ĳ���ʱ, ѭ������
	{
		if (0 == j || S[i] == T[j])	// ������ĸ��������, �������㷨������ j = 0�ж�
		{
			i++;
			j++;
		}
		else	// ָ��������¿�ʼƥ��
		{
			j = next[j];	// j�˻غ���λ��, iֵ����
		}
	}
	if (j > T[0])
		return i - T[0];
	else
		return 0;
}

#endif