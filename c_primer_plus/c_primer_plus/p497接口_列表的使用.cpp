// �����嵥 17.4
#include <stdio.h>
#include <stdlib.h>      // Ϊexit()�ṩԭ��
#include "p495�ӿ�_�б�.h"    // ����list, item
#include "daxiong.h"

void showmovies (Item item);

int main (void)
{
	List movies;
	Item temp;

	// ��ʼ�� (���б�����ΪNULL)
	InitializeList (&movies);
	if (ListIsFull (&movies))  // ���ж��ڴ��Ƿ�����, �ܲ���Ϊ�����ռ�
	{
		fprintf (stderr, "No memory available! Bye!\n");
		exit (1);
	}

	// �ռ����洢
	puts ("Enter first movie title: ");
	while (gets (temp.title) != NULL && temp.title[0] != '\0')
	{
		puts ("Enter your rating <0-10>: ");
		scanf ("%d", &temp.rating);
		eatline ();
		if (AddItem (temp, &movies) == false)
		{
			fprintf (stderr, "Problem allocating memory\n");
			break;
		}
		puts ("Enter next movie title (empty line to stop): ");
	}

	// ��ʾ
	if (ListIsEmpty (&movies))
		printf ("No data entered. ");
	else
	{
		printf ("Here is the movie list: \n");
		Traverse (&movies, showmovies);
	}
	printf ("You entered %d movies.\n", ListItemCount (&movies));

	// ���
	EmptyTheList (&movies);
	printf ("Bye!\n");

	return 0;
}

void showmovies (Item item)
{
	printf ("Movie: %s Rating: %d\n", item.title,
		item.rating);
}