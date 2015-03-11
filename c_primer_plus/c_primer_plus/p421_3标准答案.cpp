#include <stdio.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS  100     // ����������
struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

void sortt (struct book * pb[], int n); // sort ����, ��ѡ
						// struct book * pb[] �ṹָ������
void sortv (struct book * pb[], int n);

int main (void)
{
	struct book library[MAXBKS];
	struct book * pbk[MAXBKS];         // �ṹָ������
	int count = 0;
	int index;

	puts ("��������:(���н���)");
	while (count < MAXBKS && gets (library[count].title) != NULL
						  && library[count].title[0] != '\0')
	{
		puts ("��������:");
		gets (library[count].author);
		puts ("����۸�:");
		scanf ("%f", &library[count].value);
		pbk[count] = &library[count];
		count++;
		while (getchar () != '\n')
			continue;
		if (count < MAXBKS)
			puts ("��������:(���н���)");
	}
	
	puts ("����������б�:");
	for (index = 0; index < count; index++)
		printf ("%s by %s: $%.2f\n", library[index].title, library[index].author, 
		library[index].value);
	
	puts ("�����ǰ��������������б�:");
	sortt (pbk, count);
	for (index = 0; index < count; index++)
		printf ("%s by %s: $%.2f\n", pbk[index] -> title, (*(pbk[index])).author, 
		pbk[index] -> value);
	
	puts ("�����ǰ��۸����������б�:");
	sortv (pbk, count);
	for (index = 0; index < count; index++)
		printf ("%s by %s: $%.2f\n", pbk[index] -> title, (*(pbk[index])).author, 
		pbk[index] -> value);
	return 0;
}

void sortt (struct book * pb[], int n)  // �����ַ������� abcd...
{
	int top, search;
	struct book * temp;

	for (top = 0; top < n - 1; top++)
		for (search = top + 1; search < n; search ++)
			if (strcmp (pb[search] -> title, pb[top] -> title) < 0)
			{
				temp = pb[search];
				pb[search] = pb[top];
				pb[top] = temp;
			}
}

void sortv (struct book * pb[], int n)  // ���ռ۸���С��������
{
	int top, search;
	struct book * temp;

	for (top = 0; top < n - 1; top++)
		for (search = top + 1; search < n; search++)
			if (pb[search] -> value < pb[top] -> value)
			{
				temp = pb[search];
				pb[search] = pb[top];
				pb[top] = temp;
			}
}