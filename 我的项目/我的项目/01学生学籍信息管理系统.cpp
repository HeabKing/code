// ѧ��ѧ����Ϣ����ϵͳ1.0 by: ��ʿ�� ����8�� 2012484119
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NAMELEN     20    // ѧ����γ̵����ֳ���
#define SEX         4     // �Ա𳤶�
#define STUNUM      20   // ѧ������
#define SCORE_TABLE 3     // ��Ŀ�� 
#define FILENAME    "01StuInfo.dat"
#define FILENAME1   "01StuGraInfo.dat"

struct StuInfo {
	int number;
	char name[NAMELEN];
	char sex[SEX];
	int domNum;
	char tel[NAMELEN];
};
struct StuGraInfo {
	char courseNum;
	char courseName[NAMELEN];
	int creditHour;        // ѧ��
	struct {
		int number;
		int triGrade;      // ƽʱ�ɼ�
		int examGrade;     // ����ɼ�
		float totalGrade;  // �ۺ������ɼ�
	}score_table[STUNUM];
}s;

int getmenu (struct StuGraInfo * [], struct StuInfo * []);        // �ṩ����ѡ��
	int getlet (const char *); // ��һ���ַ���Ϊ����,�������е�һ���ַ�
	int menuinfo (void);           // �ṩ���������ɾ���޸Ĳ鿴ѡ��
	int menugra (void);
int showinfo (struct StuInfo * [], int);         
						  // ������Ϣ�鿴ģ�� �����ļ���ѧ������
void addinfo (struct StuInfo * [], int n);
						  // ������Ϣ����ģ��
void deleteinfo (struct StuInfo * [], int num);
						  // ������Ϣɾ��ģ��
void changeinfo (struct StuInfo * [], int num);
						  // ������Ϣ�޸�ģ��
void searchinfo (struct StuInfo * []);
						  // ������Ϣ����ģ��
void initializeGra (struct StuGraInfo * [], struct StuInfo * []);
						  // ����ѧ��������Ϣ��ʼ���ɼ���Ϣ
void readGra (struct StuGraInfo * []);
						  // ��ѧ���ɼ���Ϣ���浽�ṹ������
void showgrade (struct StuGraInfo * [], struct StuInfo * []);
						  // �ɼ���Ϣ�鿴ģ��
void showDESC (struct StuGraInfo * [], struct StuInfo * []);
						  // ����������ʾgra
void addgrade (struct StuGraInfo * [], struct StuInfo * [], int n);
						  // �ɼ���Ϣ����ģ��
void deletegra (struct StuGraInfo * [], struct StuInfo * [], int n);
void changegra (struct StuGraInfo * [], struct StuInfo * [], int n);

int main (void)
{
	int choice, i;
	struct StuInfo info[STUNUM];
						 // ѧ��������Ϣ�ṹ����
	struct StuGraInfo grade[SCORE_TABLE];
						 // ѧ���ɼ���Ϣ�ṹ����
	struct StuInfo * infoPtr[STUNUM];
						 // ѧ��������Ϣ�ṹָ������
	struct StuGraInfo * gradePtr[SCORE_TABLE];
						 // ѧ���ɼ���Ϣ�ṹָ������
	
	printf ("%45s", "ѧ���ɼ�����ϵͳ\n");
	printf ("%55s", "by ��8����\n\n");

	// �Ѹ����ṹ��ָ�븳��ָ������
	for (i = 0; i < STUNUM; i++)
		infoPtr[i] = &info[i];
	for (i = 0; i < SCORE_TABLE; i++)
		gradePtr[i] = &grade[i];
	// �ɼ���Ϣ�ĳ�ʼ��
	initializeGra (gradePtr, infoPtr);

	// ѡ��������
	choice = getmenu (gradePtr, infoPtr);
	
	switch (choice)
	{
		case '0' : showinfo (infoPtr, 0); 
				   break;
		case '1' : addinfo (infoPtr, showinfo (infoPtr, 1)); 
				   break;
		case '2' : deleteinfo (infoPtr, showinfo (infoPtr, 0)); 
				   break;
		case '3' : changeinfo (infoPtr, showinfo (infoPtr, 0)); 
			       break;
		case '4' : searchinfo (infoPtr); 
			       break;
		case '5' : showDESC (gradePtr, infoPtr); 
			       break;
		case '6' : readGra (gradePtr); 
			       addgrade (gradePtr, infoPtr, showinfo (infoPtr, 0)); 
				   break;
		case '7' : readGra (gradePtr); 
			       deletegra (gradePtr, infoPtr, showinfo (infoPtr, 0)); 
				   break;
		case '8' : readGra (gradePtr); 
			       changegra (gradePtr, infoPtr, showinfo (infoPtr, 0)); 
				   break;
		case '9' : exit (EXIT_SUCCESS);
		default  : puts ("switch����!"); 
			       break;
	}
	system ("pause");
	return 0;
}

int getmenu (struct StuGraInfo * p [], struct StuInfo * ptr [])
{
	int choice;

	puts ("a) ѧ��������Ϣ����    b) ѧ���ɼ���Ϣ����"
		"       c) �˳�");
	choice = getlet("abc");
	switch (choice)
	{
		case 'a' : choice = menuinfo (); break;
		case 'b' : showgrade (p, ptr); choice = 5 + menugra (); break;
		case 'c' : exit (EXIT_SUCCESS); break;
		default  : puts ("switch ����!"); break;
	}

	return choice;
}

int getlet (const char * str)
{
	char ch;
	
	ch = getchar ();
	while (NULL == strchr (str, ch))
							// strchr();����ch��*str�е�һ�γ��ֵ�ָ��
	{
		puts ("�����������б��е�һ���ַ�:");
		puts (str);
		while (getchar () != '\n')
			continue;
		ch = getchar ();
	}
	while (getchar() != '\n')
			continue;

	return ch;
}

int menuinfo (void)
{
	int choice;

	puts ("0) �鿴    1) ����    2) ɾ��");
	puts ("3) �޸�    4) ����");
	choice = getlet("01234");

	return choice;
}

int menugra (void)
{
	int choice;

	puts ("0) ��ѧ�Ž�������    1) ¼��ɼ�    2) ɾ���ɼ�");
	puts ("3) �޸ĳɼ�          4) �˳�");
	choice = getlet("01234");

	return choice;
}

int showinfo (struct StuInfo * ptr[], int n)
{
	int num = 0; 
	FILE * name;
	if (NULL == (name = fopen (FILENAME, "rb")))
	{
		printf ("�޷���ѧ��������Ϣ�ļ�%s.", FILENAME);
		system ("pause");
		exit (EXIT_FAILURE);
	}
	if (0 == fread (ptr[0], sizeof (struct StuInfo), 1, name) && 1 != n)
	{
		puts ("��ʱ��û��ѧ��������Ϣ¼���ļ�.");
		system ("pause");
		exit (EXIT_FAILURE);
	}
	else
	{
		rewind (name);  // �ص��ļ���ʼλ��!!!����Ҫ
		for (num = 0; 0 != fread (ptr[num], sizeof (struct StuInfo), 1, name); num++)
		{
			if (ptr[num]->name[0] == '\0')
				printf ("ѧ��: %-3d   ��ѧ���Ѿ���ѧ(��ѧ).\n", ptr[num]->number);
			else
				printf ("ѧ��: %-3d ����: %-10s �Ա�: %-4s ����: %-4d �绰: %-11s\n",
				ptr[num]->number, ptr[num]->name, ptr[num]->sex, ptr[num]->domNum,
				ptr[num]->tel);
		}
	}
	fclose (name);
	return num;
}

void addinfo (struct StuInfo * ptr[], int n)
{	
	puts ("����(�����˳�):"); 
	FILE * name;

	while (NULL != gets (ptr[n]->name) && ptr[n]->name[0] != '\0')
	{
		ptr[n]->number = n + 1;
		puts ("�Ա�: ");
		gets (ptr[n]->sex);
		puts ("�����: ");
		while (1 != scanf ("%d", &ptr[n]->domNum))
		{
			puts ("�������!�����:");
			scanf ("%*s");
		}
		while (getchar () != '\n')
			continue;
		puts ("�绰: ");
		gets (ptr[n]->tel);
		puts ("����(�����˳�):");
		n++;
	}
	if (NULL == (name = fopen(FILENAME, "wb")))
	{
		printf ("�޷���ѧ��������Ϣ�ļ�%s.", FILENAME);
		system ("pause");
		exit (EXIT_FAILURE);
	}
	fwrite (ptr[0], sizeof (struct StuInfo), n, name);
	puts ("�����Ѿ��ɹ������ȥ.");
	fclose (name);
}

void deleteinfo (struct StuInfo * ptr[], int n)
{
	int i, in;
	FILE * name;
	
	puts ("������Ҫɾ��ѧ����ѧ��:");
	while (1 != scanf ("%d", &in) || in <= 0 || in > n)
	{
		printf ("������1 - %d������.", n);
		puts ("������Ҫɾ��ѧ����ѧ��:");
	}
	for (i = 0; i < n; i++)
		if (ptr[i]->number == in)
			ptr[i]->name[0] = '\0';
	if (NULL == (name = fopen(FILENAME, "wb")))
	{
		printf ("�޷���ѧ��������Ϣ�ļ�%s.", FILENAME);
		system ("pause");
		exit (EXIT_FAILURE);
	}
	fwrite (ptr[0], sizeof (struct StuInfo), n, name);
	puts ("ɾ���ɹ�!");
	fclose (name);
}

void changeinfo (struct StuInfo * ptr[],  int n)
{
	int i, in;
	FILE * name;

	puts ("������Ҫ�޸�ѧ����ѧ��:");
	while (1 != scanf ("%d", &in) || in <= 0 || in > n)
	{
		while (getchar () != '\n')
				continue;
		printf ("������1 - %d������.", n);
		puts ("������Ҫ�޸�ѧ����ѧ��:");
	}
	while (getchar () != '\n')
				continue;
	for (i = 0; i < n; i++)
		if (ptr[i]->number == in)
		{
			puts ("����(�����˳�):");
			gets (ptr[i]->name);
			puts ("�Ա�: ");
			gets (ptr[i]->sex);
			puts ("�����: ");
			scanf ("%d", &ptr[i]->domNum);
			while (getchar () != '\n')
				continue;
			puts ("�绰: ");
			gets (ptr[i]->tel);
			break;
		}
	if (NULL == (name = fopen("StuInfo.dat", "wb")))
	{
		printf ("�޷���ѧ��������Ϣ�ļ�%s.", "StuInfo.dat");
		system ("pause");
		exit (EXIT_FAILURE);
	}
	fwrite (ptr[0], sizeof (struct StuInfo), n, name);
	puts ("�޸ĳɹ�.");
	fclose (name);
}

void searchinfo (struct StuInfo * ptr[])
{
	int num, in;
	FILE * name;

	if (NULL == (name = fopen(FILENAME, "rb")))
	{
		printf ("�޷���ѧ��������Ϣ�ļ�%s.", FILENAME);
		system ("pause");
		exit (EXIT_FAILURE);
	}
	for (num = 0; 0 != fread (ptr[num], sizeof (struct StuInfo), 1, name); num++);
	if (0 == num)
	{
		puts ("���������һ��ѧ��������Ϣ�ٽ��в���.");
		system ("pause");
		exit (EXIT_FAILURE);
	}
	printf ("����Ҫ��ѯѧ����ѧ��(1-%d):\n", num);
	while (1 != scanf ("%d", &in) || in > num || in <= 0)
	{
		while (getchar () != '\n')
			continue;
		printf ("������1-%d������:\n", num);
	}
	rewind (name);
	in -=1;
	for (num = 0; 0 != fread (ptr[num], sizeof (struct StuInfo), 1, name); num++)
		if (num == in)
		{	
			if (ptr[in]->name[0] == '\0')
				printf ("ѧ��: %-3d   ��ѧ���Ѿ���ѧ(��ѧ).\n", ptr[in]->number);
			else
				printf ("ѧ��: %-3d ����: %-10s �Ա�: %-4s ����: %-4d �绰: %-11s\n",
				ptr[in]->number, ptr[in]->name, ptr[in]->sex, ptr[in]->domNum,
				ptr[in]->tel);
		}
	fclose (name);
}

void initializeGra (struct StuGraInfo * p[], struct StuInfo * ptr[])
{
	FILE * name, * name1;
	int i, j, num;

	if (NULL == (name = fopen (FILENAME, "rb")))
	{
		
		fclose (fopen (FILENAME, "wb")); // �����ļ�
		if (NULL == (name = fopen (FILENAME, "rb")))
		{	
			printf ("�޷����ļ�%s.\n", FILENAME);
			exit (EXIT_FAILURE);
		}
	}
	// �ڻ�û��ѧ����Ϣ��ʱ����г�ʼ��
	if (0 == fread (ptr[0], sizeof (struct StuInfo), 1, name))
	{   // �γ̱��, �γ�����ѧ�ֵ����
		for (i = 0; i < SCORE_TABLE; i++)
			p[i]->courseNum = 'A' + i;
		for (i = 0; i < SCORE_TABLE; i++)
			p[i]->creditHour = i + 4;
		strcpy (p[0]->courseName, "��ѧ");
		strcpy (p[1]->courseName, "Ӣ��");
		strcpy (p[2]->courseName, "�������");
		// �ɼ���Ϣ�ĳ�ʼ��
		for (j = 0; j < SCORE_TABLE; j++)
			for (i = 0; i < STUNUM; i++)
			{
				p[j]->score_table[i].number     = i + 1;
				p[j]->score_table[i].examGrade  = -1;
				p[j]->score_table[i].triGrade   = -1;
				p[j]->score_table[i].totalGrade = -1;
			}
		if (NULL == (name1 = fopen (FILENAME1, "wb")))
		{
			printf ("�޷���ѧ���ɼ���Ϣ�ļ�%s.", FILENAME1);
			exit (EXIT_FAILURE);
		}
		fwrite (p[0], sizeof (struct StuGraInfo), SCORE_TABLE, name1);
		puts ("��ʼ��ѧ���ɼ��ɹ�(������ӵ�һ��ѧ����Ϣ��֮ǰ�һ���г�ʼ��).");
		fclose (name1);
	}

	fclose (name);
	//showgrade (p, ptr);
}

void readGra (struct StuGraInfo * ptr [])
{
	FILE * name1;

	if (NULL == (name1 = fopen (FILENAME1, "rb")))
	{
		printf ("�޷���ѧ���ɼ���Ϣ�ļ�%s.", FILENAME1);
		exit (EXIT_FAILURE);
	}
	fread (ptr[0], sizeof (struct StuGraInfo), SCORE_TABLE, name1);
	fclose (name1);
}

void showgrade (struct StuGraInfo * p[], struct StuInfo * ptr [])
{
	int i, j, num;
	FILE * name1;
	FILE * name;

	if (NULL == (name = fopen(FILENAME, "rb")))
	{
		printf ("�޷���ѧ��������Ϣ�ļ�%s.", FILENAME);
		system ("pause");
		exit (EXIT_FAILURE);
	}
	if (0 == fread (ptr[0], sizeof (struct StuInfo), 1, name))
	{
		puts ("ѧ��������ϢΪ��, ������������һ��ѧ���Ļ�����Ϣ.");
		system ("pause");
		exit (EXIT_FAILURE);
	}
	rewind (name);
	for (num = 0; 0 != fread (ptr[num], sizeof (struct StuInfo), 1, name); num++);
	
	
	if (NULL == (name1 = fopen (FILENAME1, "rb")))
	{
		printf ("�޷���ѧ���ɼ���Ϣ�ļ�%s.", FILENAME1);
		system ("pause");
		exit (EXIT_FAILURE);
	}
	fread (p[0], sizeof (struct StuGraInfo), SCORE_TABLE, name1);
	for (j = 0; j < SCORE_TABLE; j++)
	{
		printf ("%s(�γ̺�:%c ѧ��:%d)�ĳɼ�����:\n", 
		p[j]->courseName, p[j]->courseNum, p[j]->creditHour);
		for (i = 0; i < num; i++)
		{	
			if (ptr[i]->name[0] == '\0')
				printf (" ѧ��: %3d   ��ѧ���Ѿ���ѧ(��ѧ).\n", ptr[i]->number);
			else if (p[j]->score_table[i].triGrade == -1)
				printf (" ѧ��: %3d       �ɼ���û��¼��\n", p[j]->score_table[i].number);
			else if (p[j]->score_table[i].triGrade == -2)
				printf (" ѧ��: %3d       �ɼ���ɾ����\n", p[j]->score_table[i].number);
			else
				printf (" ѧ��: %3d ƽʱ�ɼ�: %3d ����ɼ�: %3d �ۺϳɼ�: %.2f\n",
				p[j]->score_table[i].number, p[j]->score_table[i].triGrade, 
				p[j]->score_table[i].examGrade, p[j]->score_table[i].totalGrade);
		}
	}
	fclose (name);
	fclose (name1);
	
	
}

void showDESC (struct StuGraInfo * p[], struct StuInfo * ptr [])
{
	int i, j, num;
	FILE * name1;
	FILE * name;

	if (NULL == (name = fopen(FILENAME, "rb")))
	{
		printf ("�޷���ѧ��������Ϣ�ļ�%s.", FILENAME);
		system ("pause");
		exit (EXIT_FAILURE);
	}
	for (num = 0; 0 != fread (ptr[num], sizeof (struct StuInfo), 1, name); num++);
	
	
	if (NULL == (name1 = fopen (FILENAME1, "rb")))
	{
		printf ("�޷���ѧ���ɼ���Ϣ�ļ�%s.", FILENAME1);
		system ("pause");
		exit (EXIT_FAILURE);
	}
	fread (p[0], sizeof (struct StuGraInfo), SCORE_TABLE, name1);
	for (j = 0; j < SCORE_TABLE; j++)
	{
		printf ("%s(�γ̺�:%c ѧ��:%d)�ĳɼ�����:\n", 
		p[j]->courseName, p[j]->courseNum, p[j]->creditHour);
		for (i = num - 1; i >= 0; i--)
		{	
			if (ptr[i]->name[0] == '\0')
				printf (" ѧ��: %3d   ��ѧ���Ѿ���ѧ(��ѧ).\n", ptr[i]->number);
			else if (p[j]->score_table[i].triGrade < 0)
				printf (" ѧ��: %3d       �ɼ���û��¼��\n", p[j]->score_table[i].number);
			else
				printf (" ѧ��: %3d ƽʱ�ɼ�: %3d ����ɼ�: %3d �ۺϳɼ�: %.2f\n",
				p[j]->score_table[i].number, p[j]->score_table[i].triGrade, 
				p[j]->score_table[i].examGrade, p[j]->score_table[i].totalGrade);
		}
	}
	fclose (name);
	fclose (name1);
}

void addgrade (struct StuGraInfo * p[], struct StuInfo * ptr[], int n)
{
	int i, in, index;
	FILE * name1;
	
	puts ("������Ҫ��ӳɼ���ѧ����ѧ��:");
	while (1 != scanf ("%d", &in) || in <= 0 || in > n)
	{
		printf ("������1 - %d������.", n);
		puts ("������Ҫ��ӳɼ���ѧ����ѧ��:");
	}
	
	for (i = 0; i < n; i++)
	{
		if (ptr[i]->number == in)
		{	
			if (ptr[i]->name[0] == '\0')
			{
				puts ("��ѧ���Ѿ���ѧ(��ѧ), ������ӳɼ�!");
				system ("pause");
				exit (EXIT_FAILURE);
			}
			else
			{
				printf ("������ж�%s(ѧ��:%d)�ĳɼ�����¼��:\n", 
					ptr[i]->name, ptr[i]->number);
				for (index = 0; index < SCORE_TABLE; index++)
				{
					if (p[index]->score_table[i].triGrade > 0)
					{
						puts ("��ѧ���ĳɼ��Ѿ�¼����.");
						system ("pause");
						exit (EXIT_FAILURE);
					}
					printf ("\n  %s�ɼ�¼��:\n", p[index]->courseName);
					printf ("    ƽʱ�ɼ�:");
					while (1 != scanf ("%d", &p[index]->score_table[i].triGrade)
						|| p[index]->score_table[i].triGrade < 0 
						|| p[index]->score_table[i].triGrade > 100)
					{
						printf ("������1 - 100������.", n);
						printf ("    ƽʱ�ɼ�:");
					}
					printf ("    ����ɼ�:");
					while (1 != scanf ("%d", &p[index]->score_table[i].examGrade)
						|| p[index]->score_table[i].triGrade < 0 
						|| p[index]->score_table[i].triGrade > 100)
					{
						printf ("������1 - 100������.", n);
						printf ("    ����ɼ�:");
					}
					p[index]->score_table[i].totalGrade = 0.3 * p[index]->score_table[i].triGrade
						+ 0.7 * p[index]->score_table[i].examGrade;
				}
			}
		}
	}
	if (NULL == (name1 = fopen (FILENAME1, "wb")))
	{
		printf ("�޷���ѧ���ɼ���Ϣ�ļ�%s.", FILENAME1);
		system ("pause");
		exit (EXIT_FAILURE);
	}
	fwrite (p[0], sizeof (struct StuGraInfo), SCORE_TABLE, name1);
	puts ("��ӳɹ�!");
}

void deletegra (struct StuGraInfo * p[], struct StuInfo * ptr[], int n)
{
	int i, in, index;
	FILE * name1;
	
	puts ("������Ҫɾ���ɼ���ѧ����ѧ��:");
	while (1 != scanf ("%d", &in) || in <= 0 || in > n)
	{
		printf ("������1 - %d������.", n);
		puts ("������Ҫɾ���ɼ���ѧ����ѧ��:");
	}
	
	for (i = 0; i < n; i++)
	{
		if (ptr[i]->number == in)
		{	
			if (ptr[i]->name[0] == '\0')
			{
				puts ("��ѧ���Ѿ���ѧ(��ѧ), û�гɼ�!");
				system ("pause");
				exit (EXIT_FAILURE);
			}
			else
			{
				for (index = 0; index < SCORE_TABLE; index++)
				{
					if (p[index]->score_table[i].triGrade == -1)
					{
						puts ("��ѧ���ĳɼ�������û��¼��.");
						system ("pause");
						exit (EXIT_FAILURE);
					}
					else if (p[index]->score_table[i].triGrade == -2)
					{
						puts ("��ѧ���ĳɼ��Ѿ���ɾ����.");
						system ("pause");
						exit (EXIT_FAILURE);
					}
					else
					{
						p[index]->score_table[i].triGrade  =  -2;
						p[index]->score_table[i].examGrade  = -1;
				        p[index]->score_table[i].totalGrade = -1;
					}
				}
			}
		}
	}
	if (NULL == (name1 = fopen (FILENAME1, "wb")))
	{
		printf ("�޷���ѧ���ɼ���Ϣ�ļ�%s.", FILENAME1);
		system ("pause");
		exit (EXIT_FAILURE);
	}
	fwrite (p[0], sizeof (struct StuGraInfo), SCORE_TABLE, name1);
	puts ("�ɹ�ɾ��!");
}

void changegra (struct StuGraInfo * p[], struct StuInfo * ptr[], int n)
{
	int i, in, index;
	FILE * name1;
	
	puts ("������Ҫ�޸ĳɼ���ѧ����ѧ��:");
	while (1 != scanf ("%d", &in) || in <= 0 || in > n)
	{
		printf ("������1 - %d������.", n);
		puts ("������Ҫ�޸ĳɼ���ѧ����ѧ��:");
	}
	
	for (i = 0; i < n; i++)
	{
		if (ptr[i]->number == in)
		{	
			if (ptr[i]->name[0] == '\0')
			{
				puts ("��ѧ���Ѿ���ѧ(��ѧ), �����޸ĳɼ�!");
				system ("pause");
				exit (EXIT_FAILURE);
			}
			else
			{
				printf ("������ж�%s(ѧ��:%d)�ĳɼ������޸�:\n", 
					ptr[i]->name, ptr[i]->number);
				for (index = 0; index < SCORE_TABLE; index++)
				{
					printf ("\n  %s�ɼ��޸�:\n", p[index]->courseName);
					printf ("    ƽʱ�ɼ�:");
					while (1 != scanf ("%d", &p[index]->score_table[i].triGrade)
						|| p[index]->score_table[i].triGrade < 0 
						|| p[index]->score_table[i].triGrade > 100)
					{
						printf ("������1 - 100������.", n);
						printf ("    ƽʱ�ɼ�:");
					}
					printf ("    ����ɼ�:");
					while (1 != scanf ("%d", &p[index]->score_table[i].examGrade)
						|| p[index]->score_table[i].triGrade < 0 
						|| p[index]->score_table[i].triGrade > 100)
					{
						printf ("������1 - 100������.", n);
						printf ("    ����ɼ�:");
					}
					p[index]->score_table[i].totalGrade = 0.3 * p[index]->score_table[i].triGrade
						+ 0.7 * p[index]->score_table[i].examGrade;
				}
			}
		}
	}
	if (NULL == (name1 = fopen (FILENAME1, "wb")))
	{
		printf ("�޷���ѧ���ɼ���Ϣ�ļ�%s.", FILENAME1);
		system ("pause");
		exit (EXIT_FAILURE);
	}
	fwrite (p[0], sizeof (struct StuGraInfo), SCORE_TABLE, name1);
	puts ("�޸ĳɹ�!");
}