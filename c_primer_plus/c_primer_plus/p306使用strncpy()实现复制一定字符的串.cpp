// p306 �����嵥 11.23  
#include <stdio.h>
#include <string.h>
#define LIM 3
#define SIZE 7
#define CPYSIZE 

int main (void)
{
	char qwords[LIM][SIZE];
	char temp[40];
	int i = 0;
	char aaaaa[6] = "week";
	char te[20];

	gets (te);
	strncpy (aaaaa, te, 9);   // ��δ���˵����strncpy()ʱ�����ԭ����Ȼ����и���
		// ����������n>=Դ�ַ���(����'\0'),��Ŀ���ַ�������'\0'����û��, ����һ���������, ����aaa�ǳ�ʼ����ʱ������ֵ, ��ʱ���λֵ����0, �������n���������ɵ�С, ���治��Ӱ���λ�û���0, ���Գ䵱'\0'
	puts (aaaaa);

	puts ("����3����q��ʼҪ���и��Ƶ��ַ���.");
	while (i < LIM && gets(temp))
	{
		if (temp[0] == 'q')
		{                           // SIZE - 1�˴���ʾ����ֻ�ܸ�����������ַ�
			strncpy (qwords[i], temp, SIZE - 1);  // ��������ʱ�����������һ��Ԫ�غ����Ԫ���ϼ�һ��'\0' ��������SIZE - 1д��SIZEҲ�е���д�ɱ�SIZE���������????
			qwords[i][SIZE - 1] = '\0';
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