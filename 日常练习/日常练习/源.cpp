// char ������c��c++�еĲ�ͬ
// char ch = 'A';
// c: ����'A'������һ���С��int��ͬ���ڴ���, ��ͬ����ֵҲ�������ڱ���ch��, ������ch����ֻռ��һ���ֽ�
// c++: 'A'��ch������һ���ֽ�
#include <stdio.h>

int main(void)
{
	int x = 'ABCD';  // 'ABCD'��洢ζ��һ�����ֽڵ�intֵ, ���е�һ���ֽڴ洢��ĸA���ַ�����, �ڶ����ֽڴ洢B���ַ�����...
		// 'ABCD' ��һ���ַ�, ���Ǹ�����, ������c�����а����ֽڴ���
	char c = 'ABCD';
	char f = 'AB';
	printf("%d %d %c %c %c\n", x, 'ABCD', c, 'ABCD', f);
	printf("%d %d %d %d",sizeof('A'), sizeof('AB'), sizeof('ABC'), sizeof('ABCD'));

	return 0;
}