// p296 �����嵥 11.12
#include <stdio.h>
void puts1 (const char *);       //һ����ͬ��puts()�ĺ���ֻ��û�����Զ��ӻس�
int puts2 (const char *);        //һ����ͬ��puts()�ĺ���ֻ�ǻ᷵���ַ����ĸ���(�Զ��ӵĻس�����������)

int main (void)
{
	puts1 ("If I'd as much money");
	puts1 (" as I could spend. \n");
	printf ("I count %d characters.\n",
			puts2("I never would cry old chairs to mend.")); //  chairs ��ϯ,����,����
			// ��ȡputs2()�ķ���ֵ�Ĺ�����c������ִ��puts2()����puts2�еĲ���������ʾ����Ļ��
	return 0;
}

void puts1 (const char * string)
{
	while (*string)             // ��ͬ��*string != '\0'
		putchar (*string++);    // ++�����ȼ�����*�����ǵ�ַ��1�����ǵ�ַָ���ֵ��һ

	return;
}

int puts2 (const char * string)
{
	int num = 0;

	while (*string != '\0')
	{
		putchar (*string++);
		num++;
	}
	putchar ('\n');

	return num;
}