// p333 �����嵥 12.5 (һ)
#include <stdio.h>

void report_count ();
void accumulate (int k);

int count = 0;        // �ļ�������, �ⲿ���� ��̬����, δ��ʼ���Ļ��Զ���0

int main (void)
{
	int value;        // �Զ�����, δ��ʼ���Ļ�ֵ�������
	register int i;   // �Ĵ�������, ����ȡ���ַ

	puts ("����һ��������(0�˳�).");
	while (1 == scanf ("%d", &value) && value > 0)
	{
		++count;     // ʹ���ļ����������
		for (i = value; i >= 0; i--)
			accumulate (i);
	}
	report_count ();

	return 0;
}

void report_count ()
{
	printf ("һ��������%d��ѭ������!\n", count);
}