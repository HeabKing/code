// c primer plus �����嵥4.2
//praise.c -- ʹ�ò�ͬ�����ַ���  //praise ���� ����
#include <stdio.h>
#define PRAISE "What a super marvelous name!"  //marvelous �Ƿ��� ����˼���
int main ()
{
	char name[40];

	printf ("What's your name?\n");
	scanf ("%s",&name);                                                     //scanf()������һ��blankֹͣɨ�� ����he shi xiong��ֻɨ��he
	printf ("Hello,%s.%s\n",name,PRAISE);   
	return 0;
}