// p383 �����嵥 14.2
#include <stdio.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100              // ���������ɵ�ͼ�����

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int main (void)
{
	struct book libary[MAXBKS]; // book�ṹ����
	int count = 0;
	int index;

	puts ("����������(�����˳�):");
	while (count < MAXBKS && gets (libary[count].title) != NULL   // ���gets ()��ͼԽ���ļ���β��ȡ���᷵��NULL
						  && libary[count].title[0] != '\0')      // gets ()������س�
	{
		puts ("��������:");
		gets (libary[count].author);
		puts ("����۸�:");
		scanf ("%f", &libary[count++].value);
		while (getchar () != '\n')                                // �������123.00\n ����scanf�������'\n' ����'\n'����Ϊ�´�����
			continue;          // ���������
		if (count < MAXBKS)
			printf ("������һ������:\n");
	}
	if (count > 0)
	{
		puts ("���������Ŀ¼:");
		for (index = 0; index < count; index++)
			printf ("%s by %s: $%.2f. \n", libary[index].title, 
					libary[index].author, libary[index].value);
	}
	else
		puts ("û����!");

	return 0;
}