// �����嵥 16.16
#include <stdio.h>
//#define NDEBUG      // ���Գɹ��Ժ���assert.hǰ��д�����ϵͳ���������assert()
#include <assert.h> // assert ά�� ��ϴ����С�Ϳ�
#include <math.h>
#include <stdlib.h>

int main (void)
{
	double x, y, z;
	puts ("Enter a pair of numbers (0 0 to quit):");
	while (2 == scanf ("%lf %lf", &x, &y) && (x != 0 || y != 0))
	{
		z = x * x - y * y; // Ӧ���ǣ���д����-
		assert (z >= 0);  // ��ʾ��������ĳ������ӦΪ��Ĺؼ�λ��, ��������Ϊ��ʱ��assert()�����ֹ�ó���
		/*if (z < 0)
		{
			puts ("z less than 0");
			abort ();
		}*/
		printf ("Answer is %f\n", sqrt(z));
		puts ("Next pair of numbers:");
	}
	puts ("done!");

	return 0;
}