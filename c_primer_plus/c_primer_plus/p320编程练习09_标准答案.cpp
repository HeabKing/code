// �����ϰ 11.13 (9) ��׼��
#include <stdio.h>
#define LEN 81
int drop_space(char *);
int main(void)
{
	char orig[LEN];

	while (gets(orig) && orig[0] != '\0')
	{
		printf("һ��ɾ����%d���ո�\n", drop_space(orig));
		puts(orig);
	}
	puts("Bye!");

	return 0;
}
int drop_space(char * s)
{
	int ct = 0;
	char * pos;
	while (*s)
	{
		if (*s == ' ')
		{
			ct++;
			pos = s;
			do
			{
				*pos = *(pos + 1);
				pos++;
			}while (*pos);
		}
		else
			s++;
	}
	return ct;
}