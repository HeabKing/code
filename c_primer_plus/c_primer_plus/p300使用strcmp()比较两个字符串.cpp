// p300 �����嵥 11.16 strcmp("A", "D"):����ֵΪ����(int(A - B))ascii��Ĳ���
// string comparison
// ע��: ��д��ĸ��ascii����Сд��ĸǰ��, ��c��ʵ��ֻ����-1, 0, 1������ֵ
#include <stdio.h>
#include <string.h>
#define ANSWER "heshixiong"

int main (void)
{
	char ty[40];
	int num;

	puts ("Who writes this program ?");
	gets (ty);
	while ((num = strcmp (ty, ANSWER)) != 0)  // ���ֱ��дANSWER == try�Ǵ�� ��Ϊ����������ַ
	{
		printf ("%d", num);
		puts ("Wrong, try again!");
		gets (ty);
	}
	puts ("Right!");

	return 0;
}