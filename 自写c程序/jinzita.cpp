//Ƕ��ѭ�� -- ������
#include <stdio.h>
int main (void)
{
	int i,i1,i2,i3,num;
	char ch;

	printf ("����һ����д��ĸ:");
	scanf ("%c", &ch);

	num = ch - 'A' + 1;
	for(i = 0; i < num; i++) //�����е�ѭ��,ÿһ��i����һ���̶�ֵ
	{
		for (i1 = 0; i1 < num - 1 - i; i1++) //����ÿ�еĿո���
		{
			printf (" ");
		}
		for (i2 = 0; i2 <= i; i2++)  //����ÿ�е�������ĸ
		{
			printf ("%c", ch - num + 1 + i2);
		}
		for (i3 = 0; i3 < i; i3++)
		{
			printf ("%c", ch - num - 1 + i2 - i3);
		}

		printf ("\n");
	}
	return 0;
}