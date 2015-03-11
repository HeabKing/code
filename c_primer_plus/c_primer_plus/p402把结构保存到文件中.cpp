// p402 �����嵥 14.14
#include <stdio.h>
#include <stdlib.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS  5

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;                      // !!!!!!!!!!!!!!����д��double�ǲ��Ե�!!!!!!!!!!!!!!!!!!!!
};

int main (void)
{
	struct book library[MAXBKS];                      // �ṹ����
	int count = 0;
	int index, filecount;
	FILE * pbook;
	int size = sizeof (struct book);

	// �����ƴ��ļ�
	if (NULL == (pbook = fopen ("p402book.dat", "a+b")))  // a+b �Զ����ƽ������һ���ɹ�����д���ļ�����ļ��Ѿ�������, ����ӵ��ļ�β��
	{
		puts ("�޷����ļ�!");
		exit (EXIT_FAILURE);
	}
	// ���ļ�
	rewind (pbook);                                   // ��λ����ʼ��
	while (count < MAXBKS && fread (&library[count],
									size, 1, pbook))
	{
		if (count == 0)
			puts ("�ļ�����������:");
		printf ("%s by %s values $%g.\n", library[count].title, 
						library[count].author, library[count].value);
		count++;
	}
	filecount = count;
	if (count == MAXBKS)
	{
		puts ("�ļ��Ѿ�����!");
		exit (EXIT_FAILURE);
	}

	// д���ṹ
	puts ("�������ļ���(���н���):");
	while (count < MAXBKS && (gets (library[count].title) != NULL)
						  && (library[count].title[0] != '\0'))
	{
		puts ("��������:");
		gets (library[count].author);
		puts ("����۸�:");
		scanf ("%f", &library[count++].value);
		while (getchar() != '\n')
			continue;
		if (count < MAXBKS)
			puts ("������һ������(���н���):");
		else
			puts ("�ļ��Ѿ�����,�����ڽ�������!!!");
	}

	// д���ļ�
	if (count > 0)
	{
		puts ("������book.dat������:");
		for (index = 0; index < count; index++)
			printf ("%s by %s values $%g.\n", library[index].title, 
							library[index].author, library[index].value);
		fwrite (&library[filecount], size, count - filecount, pbook);
	}
	else
		puts ("û����.");
	
	// ��β
	puts ("ok!");
	fclose (pbook);

	return 0;
}