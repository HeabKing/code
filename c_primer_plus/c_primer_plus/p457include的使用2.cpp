// �����嵥 16.7
#include <stdio.h>
#include "p456include��ʹ��1.h"  // ����ͷ�ļ�

// ��������
void get_names (names * pn)
{
	int i;

	printf ("Please enter your first name: ");
	fgets (pn->first, SLEN, stdin); // ����Ŀ���������
	i = 0;
	while (pn->first[i] != '\n' && pn->first[i] != '\0')
		i++;
	if ('\n' == pn->first[i])
		pn->first[i] = '\0';
	else  // ���������ַ���������slen
		while (getchar () != '\n')
			continue;
	
	printf ("Please enter your last name: ");
	fgets (pn->last, SLEN, stdin); // ����Ŀ���������
	i = 0;
	while (pn->last[i] != '\n' && pn->last[i] != '\0')
		i++;
	if ('\n' == pn->last[i])
		pn->last[i] = '\0';
	else  // ���������ַ���������slen
		while (getchar () != '\n')
			continue;
}
void show_names (const names * pn)
{
	printf ("%s %s", pn->first, pn->last);
}
