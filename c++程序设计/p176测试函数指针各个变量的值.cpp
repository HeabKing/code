// ���Ժ���ָ�����������ֵ
#include <stdio.h>
#include <iostream.h>
int f (char);                     // ����һ������
int main ()
{
	int (* fp)(char);             // ����һ������ָ��
	int arr[] = {1, 2};
	int num = 3;

	printf ("f��Ӧ�������׵�ַ,f == %p\n"
		     "arr��Ӧ������׵�ַ,arr == %p\n"
			 "num == %p\n", f, arr, num);
	printf ("f�ĵ�ַ,&f == %p\n"
		    "arr�ĵ�ַ,&arr == %p\n"
			"num�ĵ�ַ,&num == %p\n", &f, &arr, &num);

	printf ("%p, %p\n", arr, &arr/*(&arr)[0]*/);  // ??????????????????????// ��Ȼ���ǵ�ֵ��ͬ,��������ָ��Ķ����ǲ�ͬ��,arr�Ǳ�����Ϊ�������������������������Ϊ��һ������ĵ�ַ�����������һ��Ϊһ��ֵ?????/
	printf ("....%d.......", *arr);
	
	fp = f;
	printf ("fp=f��fp��Ӧ��ֵ,fp == %p\n", fp);
	return 0;
}

int f (char c)
{
	printf ("%c", c);
	
	return 1;
}