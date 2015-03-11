// c primer plus �����ϰ 8.11 p211 �ڰ���
// һ���򵥵ؼ�����
#include <stdio.h>
int menu (void);                // ��ѡ��, �ж�choice
float get_factor (int);         // ��ò�������
float changezero (void);        // ������Ϊ0ʱ���û���������Ļ���
int main (void)
{
	int choice;
	float fir, sec, result;

	while ((choice = menu()) != 5)
	{
		fir = get_factor (1);
		sec = get_factor (2);
		switch (choice)
		{
			case 1: result = fir + sec;
					printf ("%.2f + %.2f = %.2f\n", fir, sec, result);
					break;
			case 2: result = fir - sec;
					printf ("%.2f - %.2f = %.2f\n", fir, sec, result);
					break;
			case 3: result = fir * sec;
					printf ("%.2f * %.2f = %.2f\n", fir, sec, result);
					break;
			case 4: if(0 == sec)
						sec = changezero ();
					result = fir / sec;
					printf ("%.2f / %.2f = %.2f\n", fir, sec, result);
					break;
			default: printf ("error!");
					break;
		}
		
	}
	printf ("Bye!\n");

	return 0;
}

// �г��˵�, �ж�����
int menu (void)
{
	int input;

	printf ("Ҫ������������?\n");
	printf ("1. +	2. -\n3. *	4. /\n5. quit!\n");
	// �ж�����
	while (scanf ("%d", &input) != 1             // ������Ϊ������ʱ
			|| input <1  || input > 5)           // �����벻��1-5������ʱ
	{
		while (getchar() != '\n')                // ɾ�������ַ�
			continue;
		printf ("������1-5������!\n");
	}
	while (getchar() != '\n')                    // ��ʹ����1 23ͨ����ҲҪɾ��23��ֹ����Ϊ��һ�����������ȥ
			continue;
	return input;	
}

// �ж����������
float get_factor (int n)
{
	float input;
	
	printf ("�������%d����:", n);
	while (scanf ("%f", &input) != 1)            // ������Ϊ��doubleʱ
	{
		while (getchar() != '\n')                // ɾ�������ַ�
			continue;
		printf ("������double���͵�����:\n");
	
	}

	return input;
}

float changezero (void)
{
	float r;
	printf ("��������Ϊ0,�������0��double���͵�����:\n");
	while (scanf ("%f", &r) != 1 || 0 == r)
	{
		while (getchar() != '\n')                // ɾ�������ַ�
			continue;
		printf ("��������Ϊ0,�������0��double���͵�����:\n");
	}
	return r;
}