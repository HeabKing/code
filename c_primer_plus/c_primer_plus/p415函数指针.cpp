// p415 �����嵥 14.16
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char showmenu (void);
void eatline (void);     // ������ĩ
void show (void (* fp) (char *), char * str);
void ToUpper (char *);   
void ToLower (char *);
void Transpose (char *); // ��Сдת��
void Dummy (char *);     // ���ı��ַ���

int main (void)
{
	char line[81];
	char copy[81];
	char choice;
	void (* pfun) (char *);   // ָ��һ������, �ú�������һ��char *����, ����û�з���ֵ

	puts ("����һ���ַ���(�����˳�):");
	while (gets (line) != NULL && line[0] != '\0')
	{
		while ((choice = showmenu ()) != 'n')
		{
			switch (choice)
			{
				case 'u' : pfun = ToUpper; break;
				case 'l' : pfun = ToLower; break;
				case 't' : pfun = Transpose; break;
				case 'o' : pfun = Dummy; break;
			}
			strcpy (copy, line);    // Ϊshow()����һ�ݿ���
			show (pfun, copy);      // ʹ���û�ѡ��ĺ���
		}
		puts ("����һ���ַ���(�����˳�):");
	}
	puts ("ok!");

	return 0;
}

char showmenu (void)
{
	char ans;

	puts ("Enter menu choice:");
	puts ("u) uppercase            l) lowercase");
	puts ("t) transeposed case     o) original case");
	puts ("n) next string");
	ans = getchar ();		// ��ȡ�û���Ӧ
	ans = tolower (ans);	// ת��ΪСд
	eatline ();				// �޳�����ʣ�ಿ��
	while (strchr ("ulton", ans) == NULL)   // ���ַ���"ulton"�в���ans���ȳ��ֵ�λ�ò��������ĵ�ַ
	{
		puts ("Please enter a u, l, t, o, n:");
		ans = getchar ();   // ��ȡ�û���Ӧ
		ans = tolower (ans);// ת��ΪСд
		eatline ();
	}

	return ans;
}

void eatline (void)
{
	while (getchar () != '\n')
		continue;
}

void ToLower (char * str)
{
	while (*str)
	{
		*str = tolower (*str);
		str++;
	}
}

void ToUpper (char * str)
{
	while (*str)
	{
		*str = toupper (*str);
		str++;
	}
}

void Transpose (char * str)
{
	while (*str)
	{
		if (islower (*str))
			*str = toupper (*str);
		else if (isupper (*str))
			*str = tolower (*str);
		str++;
	}
}

void Dummy (char *)
{
	// ���ı��ַ���
}

void show (void (* fp) (char *), char * str)
{
	(*fp) (str);  // ���û�ѡ��ĺ���������str
	puts (str);
}