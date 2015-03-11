// �����嵥 14.14
#include <stdio.h>
#include <stdlib.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS  5

struct book
{
	char title[MAXTITL];
	char author[MAXAUTL];
	double value;
};

int main(void)
{
	struct book library[MAXBKS];
	int count = 0;
	int index, filecount;
	FILE * pbook;
	int size = sizeof(struct book);

	// �������ļ���
	if (NULL == (pbook = fopen("p402book.dat", "a+b")))  // a+b ��׷�ӵĶ�������ʽ���ļ�, �Թ���д
	{
		puts("Error: Can't open the file.");
		exit(EXIT_FAILURE);
	}
	// ���ļ�
	while (count < MAXBKS && fread(&library[count], size, 1, pbook))
	{
		if (count == 0)
			puts("�ļ���������:");
		printf("%s by %s values $%g.\n", library[count].title, library[count].author, library[count].value);
		count++;
	}
	filecount = count;
	if (count == MAXBKS)
	{
		puts("File Full!");
		exit(EXIT_FAILURE);
	}

	// д���ṹ
	puts("�������ļ���(���н���):");
	while (count < MAXBKS && gets(library[count].title)!= NULL && library[count].title[0] != '\0')
	{
		puts("Author:");
		gets(library[count].author);
		puts("Price:");
		scanf("%lf", &library[count++].value);
		while (getchar() != '\n')
			continue;
		if (count < MAXBKS)
			puts("Next file name(Empty line quit):");
		else
			puts("File Full");
	}
	// д���ļ�
	if (count > 0)
	{
		puts("File book.dat content:");
		for (index = 0; index < count; index++)
			printf("%s by %s values $%g.\n", library[index].title, library[index].author, library[index].value);
		fwrite(&library[filecount], size, count - filecount, pbook);
	}
	else
		puts("No data.");
	puts("ok");
	fclose(pbook);

	return 0;
}