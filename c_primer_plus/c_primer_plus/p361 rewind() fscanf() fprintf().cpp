#include <stdio.h>  // rewind()
#include <stdlib.h>
#define FILENAME "p361word.txt"
int main(void)
{
	FILE * fp;
	char temp[100];

	if (NULL == (fp = fopen(FILENAME, "a+")))  // a+ ģʽ ���Զ�, ����׷��д, û���ļ����ᴴ���ļ�
	{
		fprintf(stderr, "�޷����ļ�%s.\n", FILENAME);
		exit(EXIT_FAILURE);
	}

// ������� ����ȷ����д���ļ�
	while (gets(temp) != NULL && temp[0] != '\0')  // EOF�������ֹ����
		fprintf(fp, "%s", temp);
	
// ������ƶ����ļ���ʼ��, ��ȡ�ļ���ʾ��stdout
	rewind(fp);
	fprintf(stdout, "File contents:\n");
	while (fscanf(fp, "%s", temp) == 1)
		puts(temp);  // ������ڻس��Ŀ���ʮ�ֵĲ���, ���֤����fputs()��fgets()�ܹ���ȡ����'\n'д���ļ��ı�Ҫ��

// ������ƶ����ļ���ʼ��, ��ȡ
	rewind(fp);
	while (fgets(temp, 100 ,fp) != NULL)
		fputs(temp, stdout);
	
	fprintf(stdout, "\nDone!");

	return 0;
}