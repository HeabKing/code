// �˵����            // bug: ������븺����ʲô��������
// c primer plus �����嵥 8.8 p207
// menurttr.c -- �˵�����
#include <stdio.h>
char get_choice (void);
char get_first (void);
int get_int (void);
void count (void);
int main (void)
{
	int choice;
	void count (void);

	while ((choice = get_choice()) != 'q')
	{
		switch (choice)
		{
			case 'a': printf ("Buy low, sell high.\n");
					  break;
			case 'b': putchar ('\a');  // ANSI ������
				      break;
			case 'c': count ();
					  break;
			default : printf ("program error!");
					  break;
		}
	}
	printf ("Bye.\n");
	return 0;
}

void count (void)
{
	int n,i;

	printf ("Count how far? Enter an unsigned integer: \n");
	n = get_int ();
	for (i = 1; i <= n; i++)
		printf ("%d\n", i);
	while (getchar() != '\n')
		continue;
}

char get_choice (void)
{
	int ch;

	printf ("Enter the letter of your choice: \n");
	printf ("a. advice              b. bell\n");
	printf ("c. count               q. qiut\n");
	ch = get_first ();     //  1.��ֹ�Ѽ���a��Ļس������������Ӧ  2.���԰Ѽ���adc����������a
	while ((ch < 'a' || ch > 'c') && ch != 'q')
	{
		printf ("Please respond a,b,c, or q.\n");
		ch = get_first ();
	}
	return ch;
}

char get_first (void)
{
	char ch;

	ch = getchar ();
	while (getchar() != '\n')
		continue;
	return ch;
}

int get_int (void)
{
	unsigned int input;
	char ch;

	while (scanf ("%d", &input) != 1)  // ����д%u�ǲ��ܷ�ֹ���븺����???Ϊʲô????
	{
		while ((ch = getchar()) != '\n')
			putchar (ch);
		printf (" is not a integer.\nPlease enter an unsigned integer value, such as 25, 178, or 3: ");
	}
	return input;
}