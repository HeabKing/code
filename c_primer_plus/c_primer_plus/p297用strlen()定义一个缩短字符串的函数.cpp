// p297 �����嵥 11.13
#include <stdio.h>
#include <string.h>
void fit (char *, unsigned int);

int main (void)
{
	char mesg[] = "Hold on to your hats, hacter!";

	puts (mesg);
	fit (mesg, 7);  // ��"on to"�м�Ŀո񻻳���'\0'
	puts (mesg);
	puts ("Let's look at more of the string. ");
	puts (mesg + 8);

	return 0;
}

void fit (char * string, unsigned int n)
{
	if (strlen(string) > n)
		*(string + n) = '\0';

	return;
}