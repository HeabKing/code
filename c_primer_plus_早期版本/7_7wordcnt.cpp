// һ��ͳ����������,����,�������ĳ���
// c primer plus �����嵥 7.7
// wordcnt.c -- ͳ���ַ�,���ʺ���
#include <stdio.h>
#include <ctype.h>                // Ϊisspace()�ṩ����ԭ��
#define STOP '|'                  // ���߳����������
int main (void)
{
	char c;                       // �����ַ�
	char prev;                    // STOP ǰ���һ���ַ�
	long n_char = 0L;             // �ַ���
    int n_lines = 0;              // ����
	int n_words = 0;              // ������
	int p_lines = 0;              // ������������
	int inword = 0;               // ��־

	printf ("Enter text to be analyzed (| to terminate): \n");
	prev = '\n';
	while ((c = getchar()) != STOP)// ���Ϊ'|'������ѭ��
	{
		n_char++;                 // �ַ�������          //�س���Ҳ�ᵱ��һ���ַ��ӽ�ȥ
		if (c == '\n')             // �ж�����
		{
			n_lines++;
		}
		if (!isspace (c)          // ���������ַ����ǿո�
			&& inword == 0)           // ��־Ϊ0 �����ڶ��������ʱһֱ����0
		{
			inword = 1;
			n_words++;
		}
		if (isspace (c) && inword == 1)
		{
			inword = 0;
		}
		prev = c;
	}
	if (prev != '\n')
	{
		p_lines = 1;
	}
	printf ("characters = %ld, words = %d, lines = %d", n_char, n_words, n_lines);
	printf (" ,partial lines = %d\n", p_lines);
	return 0;
}