// �����ϰ 11.13 (12)
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	int i = argc;
	int count;
	if (argc < 2)
	{
		puts("�������");
		exit(EXIT_FAILURE);
	}
	else
		for (i = argc; i > 1;)
			puts(argv[--i]);
	getchar();
	return 0;
}