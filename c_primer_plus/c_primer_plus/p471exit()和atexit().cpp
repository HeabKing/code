// �����嵥 16.14
// atexit(); ʹ��ָ�����
#include <stdio.h>
#include <stdlib.h>
void sign_off (void);
void too_bad (void);

int main (void)
{
	int n;

	atexit (sign_off);     // ע��sign_off();���� // �����������ַ
	puts ("Enter an integer: ");
	if (1 != scanf ("%d", &n))
	{
		puts ("That's not an integer!");
		atexit (too_bad);
		exit (EXIT_FAILURE); // ����exit()��ʱ��"�Ƚ����"��ԭ���ע�ắ�����е��� ע: main()������ʱ�����ʽ�ĵ���exit()���Լ�ʹ�������integerҲ�����sign_off
	}
	printf ("%d is %s.\n", n, (n % 2 == 0) ? "even" : "odd");

	return 0;
}

void sign_off (void)
{
	puts ("sign_off");
}

void too_bad (void)
{
	puts ("too_bad");
}