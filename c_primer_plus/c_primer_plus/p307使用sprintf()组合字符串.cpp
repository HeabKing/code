// p307 �����嵥 11.24
#include <stdio.h>
#include <string.h>
#define SIZE 20

int main (void)
{
	char first[SIZE];
	char sp[SIZE * 2 + 10];// * sp; ������ָ���ǲ��Ե�.��ָ��ֻΪָ�����һ����ַ�ռ�, �������ǽ���Ϻ���ַ����ŵ�����spΪ��Ԫ�ص�һ���ڴ�����
	char last[SIZE];
	float prize;

	puts ("���������?");
	gets (first);
	puts ("���������?");
	gets (last);
	puts("���õĽ����Ƕ���?");
	scanf ("%f", &prize);
	sprintf (sp, "%s, %-19s%: $%6.2f\n", first, last, prize);
	puts (sp);

	return 0;
}