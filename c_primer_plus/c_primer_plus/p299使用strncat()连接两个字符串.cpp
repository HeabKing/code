// p299 �����嵥 11.15
#include <stdio.h>
#include <string.h>
#define SIZE 30
#define BUGSIZE 13

int main (void)
{
	char flower[SIZE];
	char addon[] = "s smell like old shoes!";
	char bug[BUGSIZE];
	int available;                    // ���õ�,���е�

	puts("Whats your favorite flower?");
	gets(flower);                     // gets()�����ȡ'\n'
	if (strlen (flower) + strlen (addon) + 1 < SIZE)
		strcat (flower, addon);
	puts (flower);
	puts("Whats your favorite bug?");
	gets (bug);
	available = BUGSIZE - strlen (bug) -1;
	strncat (bug, addon, available);
	puts (bug);

	return 0;
}