// p313 �����嵥 11.27 ���в�����main����
#include <stdio.h>

int main (int argc, char * argv[])
{
	int count;

	printf ("��������%d������.\n", argc - 1);
	printf("argc = %d", argc);
	for (count = 0; count < argc; count++)
		printf ("argv[%d]->%s\n", count, argv[count]);
	printf ("\n");
	scanf ("%d", &count);

	return 0;
}