// �����ϰ 3
// ͳ��std�����ļ��еĴ�д��Сд��ĸ����
#include <stdio.h>
#include <ctype.h>
int main(void)
{
	int big = 0, little = 0;
	char ch;
	while(EOF != (ch = getchar()))
		if(isupper(ch))
			big++;
		else if(islower(ch))  // else�������һ��if������, ����������ʹwhileû���û�����Ҳ�ǿ��Ե�
			little++;
	printf("��д��ĸ��%d��, Сд��ĸ��%d��\n",
		big, little);

	return 0;
}