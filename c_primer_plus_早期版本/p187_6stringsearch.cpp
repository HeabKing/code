// ���� -> ������ -> ����'#' -> ����'ei'���ֵĴ���
// c primer plus �����ϰ p187 6
#include <stdio.h>
int main ()
{
	char ch;
	int num = 0;
	int flag = 0;  // ��־

	printf ("������һ���ַ�,�ҽ�Ϊ��Ѱ��һ�����ٸ�ei(#��������):\n");
	while ((ch = getchar()) != '#')
	{
		if ('e' == ch)
		{
			flag = 1;
			continue;                           // ���������ж�
		}
		else if ('i' != ch)
		{
			flag = 0;                          // ����ϵͳ�ж�eaiҲΪһ��ei ��e�ı��־Ϊ1ʱa�ָĻ�ȥ��Ϊ0
		}
		if ('i' == ch && 1 == flag)
		{
			num++;
			flag = 0;                          // �����˻�0 
		}
		if ('\n' == ch)                        // ���õ�س����һ�����ٸ�ei
		{
			printf ("һ����%d��ei.\n", num);
			num = 0;                            // ������- -!
		}
	}
	return 0;
}