//Ƕ��ѭ�� 
//c primer plus �����嵥 6.17 
//rows.c -- ʹ��Ƕ��ѭ��  //��ѭ��Ϊ��,��ѭ��Ϊ��
#include <stdio.h>
#define ROWS 6 //������
#define CHARS 10 //��ʮ���ַ� ʮ��
int main (void)
{
	int rows;
	char ch;

	for (rows = 1; rows <= ROWS; rows++)
	{
		for (ch = 'A'; ch < ('A'  + CHARS); ch++)
		{
			printf ("%c",ch);
		}
		printf ("\n");
	}

}