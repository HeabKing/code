// p303 �����嵥 11.21  strcpy();�����ص�һ�������ĵ�ַ! ����ʱ��ѵڶ����ַ�����'\0'Ҳ������
#include <stdio.h>
#include <string.h>
#define LIM 3
#define SIZE 40

int main (void)
{
	char qwords[LIM][SIZE];
	char temp[SIZE];
	int i = 0;

	puts ("����3����q��ʼҪ���и��Ƶ��ַ���.");
	while (i < LIM && gets(temp))
	{
		if (temp[0] == 'q')
		{
			strcpy (qwords[i], temp);
			i++;
		}
		else
		{
			puts ("������Ĳ�����q��ͷ���ַ���,����������:");
			// gets(temp);
		}
	}

	for (i = 0; i < LIM; i++)
		puts (qwords[i]);

	return 0;
}