// ָ����������ȼ�                        *ar++ *++ar 
// c primer plus �����嵥 10.12 p259
// order.c -- ָ����������ȼ�
#include <stdio.h>
int data[2] = {100, 200};
int moredata[2] = {300, 400};
int main (void)
{
	int * p1, * p2, * p3, * p4;

	p1 = p2 = data;
	p3 = moredata;
	printf (" *p1 = %d, *p2 = %d, *p3 = %d\n", *p1, *p2, *p3);// һԪ�����*��++������ͬ�����ȼ�,���ڽ��ʱ�� �������� ���е�
	printf ("*p1++= %d, *++p2=%d,(*p3)++=%d\n", *p1++, *++p2, (*p3)++);
	printf (" *p1 = %d, *p2 = %d, *p3 = %d\n", *p1, *p2, *p3);
	
	return 0;
}