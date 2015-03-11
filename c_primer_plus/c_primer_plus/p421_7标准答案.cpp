// ʵ�ֶ��ļ����ݵ�ɾ�����޸�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS  10
#define CONTINUE 0
#define DONE     1
#define YES      1
#define NO       0
struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
	int del;
};

int getlet (const char * s);       // ��ɾ�����޸ĵ�ѡ��
	// ���������ַ���intֵ
int getbook (struct book * pb);
void update (struct book * item);

int main (void)
{
	struct book library[MAXBKS];   // ��ṹ
	int count = 0;                 // ���ȡ����
	int deleted = 0;               // �����ɾ������ĸ���
	int index, open;
	int filecount;                 // δ����ʾɾ������ĸ���
	FILE * pbooks;                 // ָ�򱻴򿪵��ļ�
	int size = sizeof (struct book);

	// ���ļ�
	if (NULL != (pbooks = fopen ("p421_7book.dat", "r")))
	{
		// ��ȡ�ļ�
		while (count < MAXBKS && 1 == fread (&library[count], size, 1, pbooks))
		{
			// ����ļ�
			if (0 == count)
				puts ("Current contents of book.dat:");
			printf ("%s by %s: $%.2f\n", library[count].title,
				library[count].author, library[count].value);
			// ���ɾ����ֱ�Ӹ����ļ�
			printf ("Do you wish to change or delete this entry?<y / n>");
			if ('y' == getlet("yn"))
			{
				puts ("Enter c go change, d to delete entry : ");
				if  ('d' == getlet ("cd"))
				{
					library[count].del = YES;
					deleted++;
					puts ("Entry maked for deletion.");
				}
				else
					update (&library[count]);
			}
			// ׼����ȡ��һ����
			count++;
		}
		// �ر��ļ�
		fclose (pbooks);
	}
	filecount = count - deleted; // ��ȥɾ���Ļ��м���
	// ɾ��֮ǰ�����Ѿ����� ��ʾ����д������
	if (filecount == MAXBKS)
	{
		fputs ("The book.dat file is full.", stderr);
		exit (2);
	}
	// �����
	puts ("Please add new book title.");
	puts ("Press [Enter] at the start of a line to stop.");
	open = 0;
	// ���֮ǰ�Ȱ�֮ǰ���Ҫɾ����ɾ����
	while (filecount < MAXBKS)  
	{
		// �����ɾ����ǵĻ�
		if (filecount < count)  // ����ѭ����û��ɾ����ǵ�ʱ������������
		{
			// Ѱ�Ҵ���ɾ����ǵ��ļ�
			while (NO == library[open].del)
				open++;
			// �������ݴ���Ҫɾ��������
			if (DONE == getbook (&library[open]))
				break;
		}
		// ���ʵ�����ݵ��˽�β
		else if (getbook (&library[filecount]) == DONE)
			break;

		filecount++;
		if (filecount < MAXBKS)
			puts ("Enter the next book title.");
	}
	puts("Here is the list of your books:"); 

      for (index = 0; index < filecount; index++) 

           if (library[index].del == NO) 

              printf("%s by %s: $%.2f\n",library[index].title, 

                   library[index].author, library[index].value); 

      if ((pbooks = fopen("p421_7book.dat", "w")) == NULL) 

      { 

           fputs("Can't open book.dat file for output\n",stderr); 

           exit(1); 

      } 

      for (index = 0; index < filecount; index++) 

           if (library[index].del == NO) 

              fwrite(&library[index], size, 1, pbooks); 

      fclose(pbooks); 

      puts("Done!"); 
	

	return 0;
}

int getlet (const char * s)
{
	char c;

	c = getchar ();
	while (NULL == strchr (s, c))
	{
		printf ("Enter a character in the list %s\n", s);
		while ('\n' != getchar())
			continue;
		c = getchar ();
	}
	while ('\n' != getchar ())
		continue;

	return c;
}

void update (struct book * item)
{
	struct book copy;
	char c;

	copy = * item;
	puts ("Enter the letter that indicates your choice:");
							  // indicates ָʾ ����
	puts ("t) modify title      a) modify author");
							  // modify �ı�
	puts ("v) modify value      s) qiut, saving changes");
	puts ("q) qiut, ignore changes");
	while ('s' != (c = getlet ("tavsq")) && 'q' != c)
	{
		switch ( c )
		{
			case 't' : puts ("Enter new title: ");
					   gets (copy.title);
					   break;
			case 'a' : puts ("Enter new author: ");
					   gets (copy.author);
				       break;
			case 'v' : puts ("Enter new value: ");
					   while (1 != scanf ("%f", &copy.value))
					   {
						   puts ("Enter a numeric value:");
						   scanf ("%*s");
					   }
				       while ('\n' != getchar ())
					    	continue;
				       break;
			default :  break;
		}
		puts ("Enter the letter that indicates your choice:");
							  // indicates ָʾ ����
		puts ("t) modify title      a) modify author");
							  // modify �ı�
		puts ("v) modify value      s) qiut, saving changes");
		puts ("q) qiut, ignore changes");
	}
	if ('s' == c)
		*item = copy;
}

int getbook (struct book * pb)
{
	int status = CONTINUE;  // ��״
	if (gets (pb->title) == NULL || pb->title[0] == '\0') 
	// 1.����������ж��û��Ƿ�������������������жϵ� 
	// 2.gets();����'\n'����'\0'�����
		status = DONE;
	else
	{
		printf ("Now enter the author: "); 
        gets (pb->author); 
		printf ("Now enter the value: "); 
		while (scanf("%f", &pb->value ) != 1) 
        { 
			puts("Please use numeric input"); 
            scanf("%*s"); 
		} 
        while (getchar() != '\n') 
			continue; /*clear input line */
		pb->del = NO;
	}
	return status;
}