// �����嵥 10.6
// ����Ϊʲôc������������߽��ʹ�õ�����ķ���: �ڳ�������֮ǰ, ������ֵ�п�����δ��ȫȷ������, ���Ա�������ʱ�����ҳ����������Ĵ���
// Ϊ��֤������ȷ����, �����������ڳ�������ʱ��Ӽ��ÿ�������Ƿ�Ϸ��Ĵ���, ��ص��³���������ٶȼ���
#include <stdio.h>
#define SIZE 4
int main(void)
{
	int value = 44;
	int arr[SIZE]; // �������ڴ� �����ڴ�����û��ֵ
	int value2 = 88;
	int i;

	printf("%p %p %p %p", &value, &arr[0], &arr[1] , &value2);
	printf("value = %d, value2 = %d\n", value, value2);
	for (i = -1; i <= SIZE; i++)  // ��ֵ��ʱ��Խ�����ʹ��������Χ��ջ�⵽�ƻ�, c�������Գ��������, ����vs2012���ڽ��и�ֵ��
								// ���б���, Run-Time Check Failure #2 - Stack around the variable'arr' was corrupted
								// Run-Time: �̶����� ph. 1.���е��Ե�ʱ��;��������������˼1.�ӹ�(����)ʱ��2.ִ��ʱ��3.��������ʱ
								// Check Failure ���ʧ�� variable���� corrupted �� stack ջ
		arr[i] = 2 * i + 1;
	//arr[-3] = 111;                // ע�⵽������������ֱ����value��value2��ֵ���Ҳ��Ե�ʱ������ȴ����Ұֵ8�ֽ�, ���������ܹ���ֵ���Ҳ��ܸ�Ұֵ��ֵȴ�ܸ���value��ֵ
	//arr[-4] = 222;                 // Ҳ�ܸ��������ֵ, �����ƶ����ļ�������Ǳ���arr��Χ��8�ֽ�Ұֵ    
	for (i = -5; i < 9; i++)
		printf("%2d %d\n", i, arr[i]);
	printf("value = %d, value2 = %d\n", value, value2);

	return 0;
}