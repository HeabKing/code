// p119 �� 5-10 ��ŵ����ݹ�
#include <stdio.h>

void moveDisk (int, char, char, char);      // diskԲ��

int main (void)
{
	int n;

	printf ("����Ҫ�ƶ���������:\n");
	scanf ("%d", &n);

	moveDisk (n, 'A', 'B', 'C');

	return 0;
}

void moveDisk (int diskNum, char sourcePole, char midPole, char targetPole)
{
	if (1 == diskNum)
		printf ("%c -> %c\n", sourcePole, targetPole);
	else
	{
		// ��n-1�����Ӵ�A���Ƶ�B��,����C��
		moveDisk (diskNum - 1, sourcePole, targetPole, midPole);

		// ��A���ϵ������Ƶ�C��
		printf ("%c -> %c\n", sourcePole, targetPole);

		// ��n-1�����Ӵ�B���Ƶ�C��,����A��
		moveDisk (diskNum - 1, midPole, sourcePole, targetPole);
	
	}

}