// p156 ָ�����鱣��monday-sunday
#include <stdio.h>
#define SIZE 7

int main (void)
{
	char * week[SIZE] = {"Sunday",
					     "Monday", 
					     "Tuesday", 
					     "Wednesday",
						 "Thursday",
					     "Friday", 
					     "Saturday"};

	for (int i = 0; i < SIZE; i++)
		printf ("%s\n", week[i]);  // ����Ӧ��д����week[i]������*week[i] ��Ϊ��%sʱ������Ӧ����һ��ָ������Ǿ����ֵ!!!

	return 0;
}