// ����һ������,�������С�ڻ���ڸ�������������
#include <stdio.h>
int main (void)
{
	int input, output, index, i, issushu;               //����û��ֱ�ӳ�ʼissushuΪ1 ��Ϊ�����ʼ��Ϊ1 ��ô����2��ֱ�����2 ������֤���ÿ����֮ǰ���Ǿ������жϵ�

	printf ("����һ������,�һ�����С�ڻ�������������������(#�ǽ�������):\n");
	while (1 == scanf ("%d", &input))
	{
		if (input <= 2)
		{
			printf ("�������2�����!\n");
			continue;
		}
		for (index = 3; index <= input; index++)        // ��2��ʼ��ٵ����������
		{
			for (i = 2; i < index; i++)            // ��ʼѰ���������Լ��,�ж��ǲ�������
			{
				issushu = 1;                            // �������for()�ڵĳ�ʼ������ô�൱�ڷ���while�ϵĳ�ʼ��,��ʹforһ��ûִ��Ҳ��Ϊ1
				if (0 == (index % i))                                              //����һ����Ϊ0��������ѭ���޷���ʼ��Ϊ1
				{
					issushu = 0;
					break;                              // ���breakλ��Ƕ��ѭ���� ����ֻӰ���ڲ�ѭ��
				}
			}
			if (1 == issushu)
			{
				printf ("%4d", index);
			}
		}
		printf ("\n");
	}
	return 0;
}