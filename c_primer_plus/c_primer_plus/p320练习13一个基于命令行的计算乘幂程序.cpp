// p320 �����ϰ 13
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[])
{
	int i = 0;
	float num = 1;

	
	if (3 == argc)
 		for (i = 0; i < atoi(argv[argc - 1]); i++)  // ���ﲻ��ֱ��д��argv[2] ��Ϊ��û��ȷ�����׻��м����ַ�������ֻ��д��argv[argc - 1]!!!!!!!
			num *= atof (argv[argc - 2]);
	else 
		puts ("�������!");
	
	printf ("%0.4f", num);
	scanf ("%d", &i);

	return 0;
}