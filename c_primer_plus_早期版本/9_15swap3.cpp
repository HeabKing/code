// ʹ��ָ���ں�����ͨ��
                       // �������봫ָ�������: �����õ�ʱ���β��൱�ڸ�ʵ��������һ������,�βξ���ʵ��,�൱��û�и��β��½�һ������,����һ���ڴ�
                       // ��ָ���ʱ���β���ʵ�εĵ�ַ,�β��½���һ�������������ʵ�εĵ�ַ
// c primer plus �����嵥 9.15 p238
// swap3.c -- ʹ��ָ����ɽ���
#include <stdio.h>
void interchange (int * u, int * v);  // Ҳ������������:void interchange (int *, int *); ANSIԭ�Ϳ���ʡ�Ա�������

int main (void)
{
	int x = 5, y = 10;

	printf ("Originally x = %d and y = %d.\n", x, y);
	interchange (&x, &y);             // �������ݵ�ַ,��u = &x
	printf ("Now x = %d and y = %d.\n", x, y);

	return 0;
}

void interchange (int * u, int * v)
{
	int temp;

	temp = *u;                        // ���ܹ�д��temp = u 
	*u = *v;
	*v = temp;
}