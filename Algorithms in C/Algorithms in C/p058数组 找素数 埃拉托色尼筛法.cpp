// ����: ��СΪ2, ����1, ֻ�ܱ�1�ͱ�������
// ����: ��СΪ4, ����1, ��������ʣ�µ�
// 0, 1: �Ȳ�������Ҳ���Ǻ���;
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#define N	1000000000  // ��NΪ10W��ʱ��, �Լ�д�ĵȹ����˸6�³����, ��������ɸһ����˸������
#define N 100
//#define	������ɫ��ɸ��_��̬�ڴ�
//#define �Լ�д��
#define windows�������p934
int main(void)
{
#if defined ������ɫ��ɸ��

	int i, j;
	int a[N];	// ������Ϊ100w��ʱ��, ������Щ������Ҫ30M, ����ջ�в��ܱ�����ô��

	for (i = 2; i < N; i++)
		a[i] = 1;
	for (i = 2; i < N; i++)
		if (a[i])
			for (j = i; (long long)j * i < N; j++) // �������longlong�Ļ�, i * j�ڼ���10w����ʱ�������������
				a[i*j] = 0;

	int Num = 0;
	for (i = 2; i < N; i++)
		if (a[i])
		{
			printf("%4d ", i);
			Num++;
		}
	printf("\n��%d������", Num);

#elif defined ������ɫ��ɸ��_��̬�ڴ�
	int i, j;
	//int a[N];	// ������Ϊ100w��ʱ��, ������Щ������Ҫ30G;
	int * a;
	if (!(a = (int *)malloc(sizeof (int) * N)))
	{
		printf("û����ô���ڴ�!\n");
		return 0;
	}

	for (i = 2; i < N; i++)
		a[i] = 1;
	for (i = 2; (long long)i * i < N; i++)	// �����i < N�ĳ�(long long)i * i < N;��1�����ڵļ��㼸��ûӰ��, ���ǹ����˸5��
		if (a[i])
			for (j = i; (long long)j * i < N; j++) // �������longlong�Ļ�, i * j�ڼ���10w����ʱ�������������
				a[i*j] = 0;

	int Num = 0;
	for (i = 2; i < N; i++)
		if (a[i])
		{
			printf("%4d ", i);
			Num++;
		}
	printf("\n��%d������", Num);


#elif defined �Լ�д��	// �Լ�д��
	
	int * ar;
	if (!(ar = (int *)malloc(sizeof (int) * N)))
	{
		printf("û����ô���ڴ�!\n");
		return 0;
	}

	for (int i = 0; i < N; i++)
		ar[i] = 0;

	int j;
	for (int i = 2; i < N; i++)
	{
		for (j = 2; j < i / 2; j++)	// �Ż� 1: �����ж�����Լ���ķ�Χֻ�ü�鵽i/2����
			if (i % j == 0)
				break;
		if (j >= i / 2)	// �Ż� 2: ����Ҳ�ͽ�i�ĳ���i/2, ����==�ĳ���>=, Ϊ���ǰ�2, 3������ȥ
			ar[i] = 1;
		ar[4] = 0;		// �Ż� 3: �����������4������ȥ, �����������������ֹ�������
	}
	int Num = 0;
	for (int i = 0; i < N; i++)
		if (ar[i] == 1)
		{
			printf ("%d ", i);
			Num++;
		}
	printf("\n��%d������\n", Num);

#elif defined windows�������p934
	int * ar;
	if (!(ar = (int *)malloc(sizeof (int) * N)))
	{
		printf("û����ô���ڴ�!\n");
		return 0;
	}
	for (int i = 0; i < N; i++)
		ar[i] = 0;

	int iNum = 1, iSqrt, i;
	for (int ii = 0; ii < 100; ii++)
	{
		do
		{ 
			if (++iNum < 0) 
				iNum = 0 ; 
			iSqrt = (int) sqrt (double(iNum)) ; 

			for (i = 2 ; i <= iSqrt ; i++) 
				if (iNum % i == 0) 
			break ; 
		} while (i <= iSqrt) ; 
		printf("%d ", iNum);
	}

#endif
	return 0;
}