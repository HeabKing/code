#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * argv[])  // �ڶ���������ָ��char��ָ���ָ��, ����ָ��char��ָ��
{
	FILE * fp;
	char ch;  // EOF��һ������, charû�и���, ������Ϊ������ch������ת����int������ִ��
	int count = 0;
	
	if (argc != 2)
	{
		printf ("�������������\n");
		getchar();
		exit(EXIT_FAILURE);
	}

	if (NULL == (fp = fopen(argv[1], "r")))
	{
		puts ("�ļ����ܱ���");
		getchar();
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}
	putc('\n', stdout);

	if (fclose(fp) != 0)  // �ɹ��رշ���0 ���򷵻�-1
		printf ("δ�ܳɹ��ر��ļ�\n");

	fprintf (stdout, "�ļ�%sһ����%d���ַ�\n", argv[1], count);
	getchar();

	return 0;
}