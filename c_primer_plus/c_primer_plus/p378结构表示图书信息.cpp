// p378 �����嵥 14.1 �ṹ
#include <stdio.h>
#define MAXTITL 41         // ��������󳤶� + 1
#define MAXAUTL 31         // ���ߵ���󳤶� + 1

struct book {              // �ṹģ��, ���Ϊbook
	char title[MAXTITL];   // ����
	char author[MAXAUTL];  // ����
	float value;           // �۸�
};                         // �ṹģ�����

int main (void)
{
	struct book library;   // ��library����Ϊkook�ṹ���ͱ���
	struct book chushihua = {
		"title",
		"author",
		1.23
	};

	puts ("����������:");
	gets (library.title);  // ����title����
	puts ("����������:");
	gets(library.author);  // ����author����
	puts("����۸�:");
	scanf ("%f", &library.value);
	printf ("%s by %s: $%.2f. \n", library.title, library.author, library.value);
	puts ("��ʼ����chushihua�ṹ����:");
	printf ("%s %s %f \n", chushihua.title, chushihua.author, chushihua.value);

	return 0;
}