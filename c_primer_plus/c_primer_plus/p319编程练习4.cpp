// �����ϰ 11.13 (4)
#include <stdio.h>
char * find(char *, char);
int main(void)
{
	char ar[] = "I'm not a loser!";
	printf("%c\n", *find(ar, 'm'));
	printf("%s\n", find(ar, 'o'));
	printf("%c\n", *("heshixiong" + 2));
	printf("%s\n", find(ar, 'z'));
	printf("%c\n", *find(ar, 'z')); // ����ᵼ�³����쳣��ֹ, ��Ϊ��NULL����������޷�������

	return 0;
}
char * find(char * ar, char ch)
{
	while (*ar++ != '\0')
		if (*ar == ch)
			return ar;
	return NULL;
}