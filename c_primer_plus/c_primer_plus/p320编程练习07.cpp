// �����ϰ 11.13 (7)
// ��дstring_in();
#include <stdio.h>
#include <string.h>
char * string_in(char *, char *);
int main(void)
{
	char s1[80];
	char s2[80];
	char * temp = s1;

	while (temp != NULL)
	{
		puts("�����ҵ��ַ���:");
		temp = gets(s1);
		puts("Ҫ���ҵ��ַ���:");
		gets(s2);
		if (string_in(s1, s2) != NULL)
			printf("%s\n", string_in(s1, s2));
		else
			puts("��������");
	}

	return 0;
}
char * string_in(char * s1, char * s2)
{
	bool str_in = false;
	char * temp = NULL;
	int i, j = 0, fuwei;

	for (i = 0; s2[i]; i++)
		for ( ; strlen(&s1[j]) >= strlen(s2); j++) // ���������Ҫ��ס ��ǰд����s1[j], �������������s1 = fff; s2 = xxxxxf;��ʱ��Ҳ�ܹ�
		{
			if (s1[j] == s2[i])
			{
				if (str_in == false)
				{	
					fuwei = j + 1;
					temp = &s1[j];
				}
				str_in = true;
				j++;  // breakǰ���ѭ������һ��Ҫ�������ǲ��Ǽ���!!!!!!!!!!!!!
				break;
			}
			else if(str_in == true){
				str_in = false;
				temp = NULL;
				j = fuwei;
				i = 0;
			}
			else
				str_in = false;
		}
	/*if (temp != NULL)
		temp = temp - strlen(s2) + 1;*/
	return temp;
}