// �Լ���˼�� ָ�����������ָ��
#include <stdio.h>
void show_st (char (* st)[5]);
int main (void)
{
	const char * str[2] = {  // ָ������ �����ڳ�ʼ����ʱ�����ָ���ֵ
		"string",
		"string1"
	};
	char (* st)[5];         // ����ָ�� �ڽ���������ʱ���õ��� ���Ը��ߺ���ָ��ָ��Ŀռ��Сvoid show_st (char (* st)[5]);��ʾΪ����stָ��5��char�Ŀռ��С
							// ����ָ�� �� ָ�뺯��Ҳ����ô������
	char s[2][5] = {
		{"str"},
		{"str1"}
	};

	puts (str[1]);
	st = s;
	show_st (s);

	return 0;
}

void show_st (char (* st)[5])
{
	puts (st[0]);
}