// ����-1000 - 1000������, �������ǵ�ƽ����     Ŀ��: �ų��û��Ĵ�������,ʹ������Ѻõ���ϰ
// c primer plus �����嵥 8_7 p202
// check.c -- ����ȷ��
#include <stdio.h>
// ȷ��������һ������
int get_int (void);
// ȷ�Ϸ�Χ�����½��Ƿ���Ч
int bad_limits (int begin, int end, int low, int hight);
// �����a��b֮���������ƽ����
double sum_squares (int a, int b);
int main (void)
{
	const int MIN = -1000;  // ��Χ���½�����
	const int MAX = 1000;   // ��Χ���Ͻ�����
	int start;              // ��Χ���Ͻ�
	int stop;               // ��Χ���½�
	double answer;          // ƽ����

	printf ("This program computes the sum of squares of "
		    "integers in a rang.\nThe lower bound should not "
			"be less than -1000 and\nthe upper bound should not"
			" be more than 1000.\nEnter the limits (enter 0 for "
			"both limits to quit):\nlower limits: \n");
	start = get_int ();
	printf ("upper limit: \n");
	stop = get_int ();
	while (start != 0 || stop != 0)
	{
		if (1 == bad_limits (start, stop, MIN, MAX))
			printf ("please try again.\n");
		else
		{
			answer = sum_squares (start, stop);
			printf ("The sum of the squares of the integers from %d to %d is %g.\n",
				     start, stop, answer);
		}
		printf("Enter the limits (enter 0 for both limits to quit):\nlower limits: \n");
		start = get_int ();
	    printf ("upper limit: \n");
		stop = get_int ();
	}
	printf ("Bye!\n");
	return 0;
}
int get_int (void)
{
	int input;
	char ch;

	while (scanf("%d", &input) != 1)         // �������Ĳ���int����,��Ҫ��ͣ��ѭ��,��Ϊ�����жϾ��Ǹ�����scanf()
	{
		while ((ch = getchar()) != '\n')     // ���������ַ����ǿո�Ҫ...
			putchar (ch);                    // �޳����������    //����Ķ����������ٶ�����һ�ζ�ȡ,ɾ�����������low
		printf (" is not an integer.\nPlease enter "                 //���᲻ͣ����ʾ�����printf�����Ϊscanf����
			    "an integer value, such as 25, -178, or 3: \n");          //��l����ȥ,���Խ���ͣ��ִ��ѭ��ȥ���Զ�l,������
	}                                                                    //��仰�����getchar����low��ʲô������,����
	return input;                                                           //low������һ�κ󽫲������´α�������
}
int bad_limits (int begin, int end, int low, int high)
{
	int not_good = 0;

	if (begin > end)             // �������ĵ�һ����С�ڵڶ�����
	{
		printf ("%d isn't smaller than %d.\n", begin, end);
		not_good = 1;
	}
	if (begin < low || end < low)             // ���������С����߽�
	{
		printf ("Values must be %d or greater.\n", low);
        not_good = 1;
	}
	if (begin >high || end > high)             // ��������������ұ߽�
	{
		printf ("Values must be %d or less.\n", high);
		not_good = 1;
	}
	return not_good;
}
double sum_squares (int a, int b)
{
	double total = 0;
	int i;

	for (i = a; i <= b; i++)
		total += i * i;
	
	return total;
}