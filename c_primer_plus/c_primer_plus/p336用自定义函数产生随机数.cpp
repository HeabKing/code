// p335 �����嵥 12.7 (һ)
#include <stdio.h>
#include <time.h>

extern int rand1 (void);
extern void srand1 (unsigned int);

int main (void)
{
	int count;
	unsigned int seed;

	//puts ("������������:");
	//while (1 == scanf_s ("%u", &seed))
	//{
		srand1 ((unsigned int)time(0));  // ��������
		for (count = 0; count < 5; count++)
			printf ("%hd\n", rand1 ());  // %hd short int����
		//puts ("������������:");
	//}
	printf ("���!\n");

	return 0;
}