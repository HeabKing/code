 // һ������ͳ���ı��е�����,��ĸ����ƽ��ÿ�����ʵ���ĸ����С����
// c primer plus �����ϰ 8.11 p211
#include <stdio.h>
#include <ctype.h>

int get_num_letters (char cr);  // ����ĸ������ԭ��
int get_num_words (char cr);    // �󵥴�������ԭ��

// �Զ��庯���в�����whileѭ���г�ʼ���Ķ���
int n_l;                        // ���뵽while()ѭ����ǧ������˳�ʼ�������� // ���ǲ�����ѭ�������ʼ��
int n_w = 0;
int is_word = 0;                // �жϵ��ʵı�־ ��ʼΪ0,�Ӷ�ȡ���ʵ�����֮ǰΪ1,�����˻ָ�Ϊ0

int main (void)
{
	char ch;             // �ַ����е�ÿ���ַ�
	int num_letters = 0; // ������
	int num_words = 0;   // ��ĸ��
	float avg = 0;           // average ƽ����

	printf ("�����һ���ı�(���еĿ�ʼ����|������): \n");
	while ((ch = getchar()) != '|')
	{   
		num_letters = get_num_letters (ch);
		num_words = get_num_words (ch);
	}
	avg = (float)num_letters / (float)num_words;  // ����ת��
	printf ("һ����%d����ĸ,%d������,ƽ��"
		    "ÿ������%.2f����ĸ.\n",
			num_letters, num_words, avg);

	return 0;
}

int get_num_letters (char cr)
{
	

	if (isalnum(cr))                        // �����һ����ĸ������
		n_l++;				
	
	return n_l;
}

int get_num_words (char cr)
{


	if (isalnum(cr))                     
		is_word = 1;                     
	if (1 == is_word && isspace(cr))        // ��һ�����ʵ����һ����ĸ�Ϳո�Ľ��㴦Ϊn_w��1
	{	
		n_w++;
		is_word = 0;                        // ��ֹ��һ�����ʺ�����������ո��м����ж�Ϊһ������ 
	}
	
	return n_w;
}