// p360 �����嵥 13.2
// ͨ������ÿ�����ַ��еĵ��������ļ�ѹ��Ϊԭ��������֮һ
#include <stdio.h>
#include <stdlib.h>      // Ϊ�˵���exit();
#include <string.h>      // Ϊstrcpy()��strcat()�����ṩԭ��
#define LEN 1000

int main (int argc, char * argv[])
{
	FILE * in, * out;    // ��������fileָ��
	int ch;
	char name[LEN];      // ���ڴ���������ļ���
	int count = 0;
	// ��������в���
	if (argc < 2)
	{	
		fprintf (stderr, "δ�ܳɹ���%sָ���ļ�!\n", argv[0]);
		
		exit (EXIT_FAILURE);
	}

	// ʵ������
	if ((in = fopen (argv[1], "r")) == NULL)
	{
		fprintf (stderr, "�Ҳ��ܴ�\"%s!\"\n", argv[1]);
		system("pause");
		exit (EXIT_FAILURE);
	}

	// ����ѹ���ļ�
	strncpy (name, argv[1], strlen (argv[1]) - 4);      // ���ļ������Ƶ�������
	name[strlen (argv[1]) - 4] = '\0';                  // ע��name[4]ʵ���ǵ����Ԫ��!!!!!!!!!!!!!!!!!!
	strcat (name, ".red.txt");   // ���ļ������.red    // strcat����.��name�еĵ�һ��'\0'�滻�� ����������'\0'
	printf (name);
	if ((out = fopen (name, "w")) == NULL)
	{
		fprintf (stderr, "���ܴ���ѹ���ļ�!\n");
		system("pause");
		exit (EXIT_FAILURE);
	}

	// ��������
	while ((ch = getc(in)) != EOF)
		if (count++ % 3 == 0)
			putc (ch, out);  // ��ӡÿ�����ַ��е�һ��

	// ��β����
	if (fclose(in) != 0 || fclose (out) != 0)
		fprintf (stderr, "�޷��ر�����ļ�!\n");

	return 0;
}