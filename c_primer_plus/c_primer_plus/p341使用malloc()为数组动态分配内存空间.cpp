// p341 �����嵥 12.14
#include <stdio.h>
#include <stdlib.h>         // Ϊmalloc(), free()��exit()�ṩ����ԭ��

int main (void)
{
	double * ptr;
	int max;
	int number;
	int i = 0;

	puts ("�����������������:");
	scanf ("%d", &max);
	ptr = (double *) malloc (max * sizeof (double));

	if (NULL == ptr)
	{
		puts ("�ڴ�������!");
		exit (EXIT_FAILURE);      // �쳣��ֹ����
	}
	// ptr����ָ����max��Ԫ�ص�����
	puts ("����������Ԫ��(q�˳�)");
	while (i < max && scanf ("%lf", &ptr[i]))
		i++;
	puts ("�����������:");
	number = i;                  // �������������������˶��ٸ�����ʾ���ٸ�
	for (i = 0; i < number; i++)
	{
		printf ("%7.2f", ptr[i]);
		if (i % 7 == 6)          // ��ʾ��ʱ��6��һ��
			puts ("\n");
	}
	puts ("ok!");
	free (ptr);

	return 0;
}