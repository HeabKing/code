// �����ϰ 6.16
// ����ѭ��: ������������ �ڲ�����ͬ�� һ�����ƿո� һ��������ĸ
#include <stdio.h>
int main(void)
{
	char ch;
	
	puts("Please enter a letter:");
	ch = getchar();

	for(int i = 'A'; i <= ch; i++)
	{
		
		for(int j = i; j < ch; j++)
			putchar(' ');
		for(int k = 'A'; k <= i; k++)
			putchar(k);
		for(int k = i - 1; k >= 'A'; k--)
			putchar(k);

		putchar('\n');
	}
	return 0;
}