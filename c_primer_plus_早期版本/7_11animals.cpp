// switch����ʹ��
// c primer plus �����嵥 7.11
// animals.c -- ʹ��switch���
#include <stdio.h>
#include <ctype.h>
int main (void)
{
	char ch;
	printf ("Give me a letter(��ĸ) of alphabet, and I will give ");
	printf ("an animal name\nbeginning with that letter.\n");
	printf ("Please type in a letter: type # to end my act.\n");
	while ((ch = getchar()) != '#')  // ��ϵ�����!=�����ȼ����ڸ�ֵ�����= �������û��ch = getchar()�������ŵĻ������ch=1
	{ 
		if ('\n' == ch)   // ��������Ժ�������������ֱ�Ӵ�س�������ʾI recognize only lowercase letters.
			continue;
		if (islower(ch))  // ֻʶ��Сд��ĸ
			switch (ch)
			{
				case 'a':
					printf ("argali, a wild sheep of Asia.\n");
					break;
				case 'b':
					printf ("babirusa, a wild pig of Malay.\n");
					break;
				case 'c':
					printf ("coati, racoonlike mammal.\n");
					break;
				default:
					printf ("That's a stumper(����)!\n");
			}                // switch������
		else
			printf ("I recognize only lowercase letters.\n");
	//	while (getchar () != '\n')  
	//		continue;        // ���������е�ʣ�ಿ��
		while (getchar () != '\n') // �������abc��ô�ϸ�ѭ����ȡa ���ѭ����ȡbc ����������
			;                // ˵��continue����ֻ�Ǹ�ռλ��
		printf ("Please type another letter or a #.\n");
	}                        // whileѭ������
	printf ("Bye!\n");
	return 0;                
}