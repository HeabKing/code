// p393 �����嵥 14.9
#include <stdio.h>
#include <string.h>
#define LEN 20

struct namect {
	char fname[LEN];
	char lname[LEN];
	int letter;
};

struct namect getinfo (void);
struct namect makeinfo (struct namect);
void showinfo (struct namect);

int main (void)
{
	struct namect person;

	person = getinfo ();         // ���ڱ����ú����д��� һ��person�ĸ���
	person = makeinfo (person);
	showinfo (person);

	return 0;
}

struct namect getinfo (void)
{
	struct namect temp;

	puts ("First name:");
	gets (temp.fname);
	puts ("Last name:");
	gets (temp.lname);

	return temp;	
}

struct namect makeinfo (struct namect temp)
{
	temp.letter = strlen (temp.fname) +
				  strlen (temp.lname);
	return temp;
}
void showinfo (struct namect temp)
{
	printf ("%s%s, your name have %d letters!\n", temp.fname, temp.lname, temp.letter);
}