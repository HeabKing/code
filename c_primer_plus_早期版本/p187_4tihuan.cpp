//���� -> ��̾��������,˫��̾�������̾�� -> ��������˶��ٴ��滻
//c primer plus �����ϰ p187 4
#include <stdio.h>
int main ()
{
	char ch;
	int num = 0;

	printf ("������Ҫ�����滻���ַ���(#��������):\n");
	while ((ch = getchar()) != '#')
	{
		if ('!' == ch)
		{
			printf ("!");
			num++;
		}
		if ('.' == ch)
		{
			ch = '!';
			num++;
		}
		putchar (ch);	
	}
	printf ("һ��������%d���滻\n", num);
	return 0;
}