// �����嵥 3.9
// ����pringf()�Ĳ�������
#include <stdio.h>
int main (void)
{
	int Int = 4;
	int Int2 = 5;
	float Float = 5.0f;

	printf ("%d\n", Int, Int2); // ����̫�ٵ�ʱ���޷���ʾ������Ĳ���
	printf ("%d %d\n", Int);    // ����̫�ٵ�ʱ��û�ж�Ӧ�ĸ�ʽ˵����Ϊ0(�е�������ֵ)
	printf ("%d %f", Float, Int);
								// ˵������������Ͳ������������ʾΪ0(�е�������ֵ)

	return 0;
}