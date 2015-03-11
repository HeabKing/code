// p364 �����嵥 13.5
#include <stdio.h>
#include <stdlib.h>
#define CNTL_Z '\032'    // dos�ı��ļ����ļ���β���
	// ��������ʽ��ʱ��EOF(Ctrl+z)�ᱻ�����ַ���ȡ, ������Ϊ�����ı��
#define SLEN 50
int main (void)
{
	char file[SLEN];     // ���ڴ����ļ���
	char ch;
	FILE * fp;
	long count, last;

	puts ("������Ҫ���в��Ե��ļ���:");     // Microsoft Visual C++ ����Դ�ļ��ļ�����Ѱ���ļ�
	gets (file);

	// ���ļ�
	if ((fp = fopen (file, "rb")) == NULL)  // rb �Զ�������ʽ��һ������ȡ���ļ�
	{
		puts ("���ܴ�ָ���ļ�!");
		exit (1);
	}

	// ���ļ����������ȡ
	fseek (fp, 0L, SEEK_END);               // ��λ���ļ���β��  ����ִ�з���0 �쳣����-1
	last = ftell (fp);                      // ftell()ͨ�����ؾ����ļ���ʼ�����ֽ�����ȷ���ļ���λ��(�������ö����ƴ򿪵��ı�, �������ı�ģʽ�򿪵��ļ�������һ������)
	for (count = 1L; count <= last; count++)
	{
		fseek (fp, -count, SEEK_END);       // ����
		ch = getc (fp);
		// ���dos ��unix��Ҳ���Թ���
		if (ch != CNTL_Z && ch != '\r')
			putchar (ch);
	}
	
	// �ر��ļ�
	putchar ('\n');
	fclose (fp);

	return 0;
}