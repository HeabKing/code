// ����������ֺ��ַ� ����һ���ַ��������� �ַ�������Ϊ���д�ӡ��
// c primer plus �����嵥 8.5 p198
// showchar.c -- ����һ���ϴ��I/O����ĳ���
#include <stdio.h>
void display (char cr, int lines, int width);
int main (void)
{
	int ch;
	int rows, cols;

	printf ("Enter a character and two integers: \n");
	while ((ch = getchar()) != '\n')
	{
		scanf ("%d %d", &rows, &cols);
		display (ch, rows, cols);
		while (getchar() != '\n')      // �޳�scanf()�����������ַ�,�������з�,getchar���뻻�з�(���κ�����c 2 3��Ӧ��ֱ���˳����ܼ�������)
			continue;
		printf ("Enter another character and two integers: \n");
		printf ("Enter a new line to quit.\n");
	}
	printf ("Bye.\n");
	return 0;
}
void display (char cr, int lines, int width)
{
	int row, col;

	for (row = 1; row <= lines; row++)
	{
		for (col = 1; col <= width; col++)
			putchar (cr);
		putchar ('\n');               // �������� ��ʼ�µ�һ��
	}
}