#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 1024
#define SLEN 81

void append(FILE * dest, FILE * source);

int main(void)
{
	FILE * fa, * fs;  // faָ��Ŀ���ļ�, fsָ��Դ�ļ�
	int files = 0;
	char file_app[SLEN];
	char file_src[SLEN];
	char huanchong[BUFSIZE];

// ��Ŀ���ļ�
	puts("����Ŀ���ļ�������: ");
	gets(file_app);
	if (NULL == (fa = fopen(file_app, "a")))  // ׷��д��ģʽ
	{
		fprintf(stderr, "���ܴ�Ŀ���ļ�%s\n", file_app);
		exit(EXIT_FAILURE);
	}

	// int setvbuf(FILE * restrict fp, char * restrict buf, int mode, size_t size)����Ŀ���ļ��Ļ�����  // setvbuf()��������׼i/o����ʹ�õ��滻������, ���ļ��Ժ�, ��û�ж��������κβ�����ǰ, ���Ե����������, ��ָ��fp��ָ����, bufָ��ʹ�õĴ洢��, ���buf��ֵ����NULL, �ͱ��봴�����������(����: ��������һ��1024���ַ�������, Ȼ�󴫵ݸ�����ĵ�ַ.), ����, ���buf��ֵ��NULL, ������Ϊ�Լ��Զ�����һ��������, size����Ϊsetvbuf()����ָ������Ĵ�С, mode��������ѡ����ѡȡ: _IOFBF��ʾ��ȫ����(����������ʱ��ˢ��), _IOLBF��ʾ�л���(����������ʱ�����һ������д���ʱ��ˢ��), _IONBF��ʾ�޻��� ����ɹ�ִ��, �����᷵����ֵ, ���򷵻ط���ֵ
	if (setvbuf(fa, huanchong, _IOFBF, BUFSIZE) != 0)  // �ɹ���������0
	{
		fputs("���ܴ���Ŀ���ļ�������", stderr);
		exit(EXIT_FAILURE);
	}

// ��Դ�ļ�
	puts("�����һ��Դ�ļ����ļ�����(���н�������):");
	while (gets(file_src) && file_src[0])
	{
		if (!strcmp(file_app, file_src))
		{
			fputs("���ܶ��ļ��������׷��, ����������:\n", stderr);
			continue;
		}
		else if (NULL == (fs = fopen(file_src, "r")))
			fprintf(stderr, "���ܴ�%s�ļ�!\n", file_src);
		append(fa, fs);
		if (ferror(fs) != 0)  // ������һ��������÷������Ƕ�ȡ��������Ǽ�⵽���ļ���β, ��������һ������ֵ, ���򷵻���ֵ
			fprintf(stderr, "��ȡ%sԴ�ļ�ʧ��!\n", file_src);
		if (ferror(fa) != 0)
			fprintf(stderr, "д��%sĿ���ļ�ʧ��!\n", file_app);
		fclose(fs);
		files++;
		printf("huangchong: %s\n", huanchong);
		scanf("%s", huanchong);
		printf("Դ�ļ�%s�Ѿ�׷�ӵ���Ŀ���ļ�!\n", file_src);
		puts("��������һ��Դ�ļ�(�����˳�):");
	}
	printf("Done. %d files appended!\n", files);
	fclose(fa);

	return 0;
}

void append(FILE * dest, FILE * source)
{
	size_t bytes;
	static char temp[BUFSIZE];

	while (bytes = fread(temp, sizeof(char), BUFSIZE, source))
		fwrite(temp, sizeof(char), bytes, dest);  // ������������д���ļ�
}