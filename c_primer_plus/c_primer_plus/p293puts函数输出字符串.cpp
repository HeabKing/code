// p293 �����嵥 11.8
#include <stdio.h>
#define DEF "I am a #defined string."

int main (void)
{
	
	char str[80] = "An array was initialized to me!";
	char s[] = {'w', 'o', 'w'};
	char * str2 = "A pointer was initialized to me!";

	puts ("I am an argument of puts()!");  // argument ����
	printf("...%d...", puts (DEF));                            // puts ���������ʱ���Զ����ϻ��з�
	puts (str);
	puts (str2);
	puts (&str[5]);
	puts (str2 + 4);
	puts (s);                              // �Ҳ�����ȷ��'\0'!!!

	return 0;
}