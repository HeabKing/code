// p356 �����嵥 13.1
#include <stdio.h>
#include <stdlib.h>     // exit ();��ԭ��

int main (int argc, char * argv[])
{
	int ch;            // ��ȡʱ����ÿ���ַ���λ��
	FILE * fp;         // �ļ�ָ��
	long count = 0;

	if (argc != 2)
	{
		printf ("δ�ܸ�%s�ɹ�ָ���ļ�!\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen (argv[1], "r")) == NULL)
	{
		printf ("���ܴ�%s!", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc (fp)) != EOF)
	{
		putc (ch, stdout);       // �൱��putchar(ch);
		count++;
	}
	fclose (fp);
	printf ("�ļ�%s��%d���ַ�.\n", argv[1], count);
	scanf ("%d", &count);
	
	return 0;
}