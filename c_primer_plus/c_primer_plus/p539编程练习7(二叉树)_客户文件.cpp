// �����ϰ 17.12
#include <stdio.h>
#include <stdlib.h>
#include "p539�����ϰ7(������).h"
#define FILENAME "p539�����ϰ7(������).txt"

enum CHOICE {show, find, quit};

int GetChoice();
void ShowTree(Node *);
Item GetItem();

int main(void)
{
	FILE * fp;
	Tree Words;
	Item temp;
	
	if (NULL == (fp = fopen(FILENAME, "r")))
	{
		fprintf(stderr, "Can't open the file.\n");
		exit(1);
	}
	puts("�ɹ����ļ�...");
	Ini(&Words);
	puts("�ɹ���ʼ����...");
	while (fscanf(fp, "%s", temp.wrd) == 1)
		AddItem(&temp, &Words);
	puts("�ɹ������ݶ�������...");
	
	int choice = GetChoice();
	Node * pn;
	switch (choice)
	{
	case show:
		Travel(&Words, ShowTree);
		break;
	case find:
		if (pn = IsInTree(&GetItem(), &Words))
			printf("%s : %d\n", pn->item.wrd, pn->count);
		else
			puts("����������");
		break;
	case quit:
		break;
	default:
		puts("Switch Error!");
	}
	
	fclose(fp);

	return 0;
}

static void ShowTree(Node * pn)
{
	printf("%s : %d\n", pn->item.wrd, pn->count);
}

int GetChoice()
{
	int ch;
	puts("1> �г����е��ʼ����ִ���   2> ���ҵ���   3>�˳�");
	ch = getchar();
	if (ch == '1')
		return show;
	else if (ch == '2')
		return find;
	else if (ch == '3')
		return quit;
	else
	{
		puts("�������");
		exit(1);
	}
}

Item GetItem()
{
	Item temp;
	while (getchar() != '\n');
	puts("������һ������: ");
	gets(temp.wrd);
	return temp;
}