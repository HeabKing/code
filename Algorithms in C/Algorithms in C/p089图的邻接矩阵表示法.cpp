#include <stdio.h>
#define V 9		// ������

int main(void)
{
	int x, y, adj[V][V];

		// �ڽӾ����ʼ��
	for (y = 0; y < V; y++)
		for (x = 0; x < V; x++)
			adj[y][x] = 0;
	for (x = 0; x < V; x++)	// ���ʹ���, �Խ���ֵ����һ
		adj[x][x] = 1;

		// ��ȡ�û�����
	while (scanf("%d %d", &x, &y) == 2)
	{
		adj[x][y] = 1;
		adj[y][x] = 1;
	}

	return 0;
}