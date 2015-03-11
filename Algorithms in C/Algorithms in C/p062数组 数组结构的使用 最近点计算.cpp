// ƽ�����������N����, ͳ�ƾ���С��d�ĵ�Եĸ���;
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	float x;
	float y;
} point;

float distance(point a, point b);

float randFloat()
{
	return 1.0 * rand() / RAND_MAX;
}

int main(void)
{
	float d;
	printf("��̾���: ");
	scanf("%f", &d);
	int i, j, cnt = 0, N;
	printf("���ɵ�ĸ���: ");
	scanf("%d", &N);

	point * a = (point *)malloc(N * (sizeof(*a)));

	for (i = 0; i < N; i++)
	{
		a[i].x = randFloat();
		a[i].y = randFloat();
	}
	for (i = 0; i < N; i++)
		for (j = i + 1; j < N; j++)
			if (distance(a[i], a[j]) < d)
				cnt++;
	printf("%d �������Ծ���С�� %f\n", cnt, d);

	return 0;
}

float distance(point a, point b)
{
	float dx = a.x - b.x, dy = a.y - b.y;
	return sqrt(dx*dx + dy*dy);
}