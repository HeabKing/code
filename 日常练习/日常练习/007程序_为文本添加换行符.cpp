// ָ��һ���ı�ÿ�������ַ���, �Զ���ɻ���
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define BYTE 75
#define SOURCE_F "007�������غ�ħ��ʯ.txt"
#define GOAL_F "007�������غ�ħ��ʯ_����.txt"

FILE * openfile(char *, char *);
void r_and_w(FILE * source, FILE * total, int byte);
char * gett(FILE *, char *); // �Լ�д�Ķ��뺯��

int main(void)
{
	FILE * source_f;
	FILE * goal_f;
	SetConsoleTitleA("by:���۸��");

// ��/�����ļ�
	if (source_f = openfile(SOURCE_F, "r"))
		goal_f = openfile(GOAL_F, "w");
	
	r_and_w(source_f, goal_f, BYTE);
	puts("ok!");

	return 0;
}

FILE * openfile(char * file, char * s)
{
	FILE * f;
	if ((f = fopen(file, s)) == NULL)
	{
		printf("Can't open the file \"%s\"!\n", file);
		getchar();
		exit(EXIT_FAILURE);
	}
	else
		printf("�ɹ����ļ�:%s\n", file);
	return f;
}

void r_and_w(FILE * source, FILE * goal, int byte)
{
	char ar[500];
	char temp[500];
	int i = 0;
	printf("��ʼ����");
	while (NULL != fgets(ar, 500, source))
	{
		while(ar[i])
			i++;
		printf("%d���ַ�:\n", i);
		printf("%s\n", ar);
		if (i > byte)
		{
			for (i = 0; i < byte; i++)
				temp[i] = ar[i];
			temp[i] = '\n';
			temp[i+1] = '\0';
			puts("����ת�����.");
			fputs(temp, goal);
			fputs(&ar[i+1], goal);
			puts("�ɹ�д�븱��!\n");
			i = 0;
		}
		else{
			puts("����ֱ��д�븱��...");
			fputs(ar, goal);
			puts("ֱ��д�븱���ɹ�!\n");
		}
		printf("��ʼ����:");
	}
}