// �ݹ�: ���������䱾��Ĺ��̱������ݹ�  �ݹ�û��ѭ��Ч�ʸ�
// c primer plus �����嵥 9.6 p225
// recur.c -- �ݹ����     recur ���� 
#include <stdio.h>
void up_and_down (int);

int main (void)
{
	up_and_down (1);
	return 0;
}

void up_and_down (int n)
{
	printf ("Level %d: n location %p\n", n, &n);  // 1
	if (n < 4)
		up_and_down (n+1);
	printf ("LEVEL %d: n location %p\n", n, &n);  // 2

}