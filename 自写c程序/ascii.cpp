//asciiֵ��ѯ��
#include <stdio.h>
int main (void)
{
	char input;

	printf ("������Ҫ��ѯascii��ķ���: \n");
	while(scanf ("%c", &input) == 1)
	{
		if(input != 10)
		{
			printf ("%c -> %d\n", input, input);
		}
	}
	return 0;
}