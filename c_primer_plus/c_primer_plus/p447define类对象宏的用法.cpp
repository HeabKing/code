// �����嵥 16.1 �򵥵�Ԥ������������
#include <stdio.h>
#define TWO 2  
#define OW "Consistency is the last refuge of the unimagina\
tive. -Oscar Wilde" // ��б�߰����������������һ��
#define FOUR TWO*TWO
#define PX printf ("X is %d.\n", x)// PX Ϊ������ ������������ֵ ���ǵ��м䲻���пո�
#define FMT "x is %d.\n" // �󲿷ֱ����������嵱�����Է��������ַ����������ַ����ַ���. �ո������Է��ŵļ���������м����ո��������ַ�

int main (void)
{
	int x = TWO;
	const char * fmt = "x is %d.\n"; // Ҳ�������ַ����������ֶ��巽ʽ

	PX;
	x = FOUR;
	printf (FMT, x);
	printf ("%s\n", OW);
	printf ("TWO: OW\n");
	printf (fmt, x);

	return 0;
}
