#include <stdio.h>
#include <stdlib.h>
#define V 9
typedef struct node * link;
struct node
{
	int v;
	link  next;
};
link New(int v, link next)
{
	link CN		= (link)malloc(sizeof *CN);
	CN->v		= v;
	CN->next	= next;
	return CN;
}
int main(void)
{
	int x, y;
	link adj[V];

		// ����һ����������
	for (x = 0; x < V; x++)
		adj[x] = NULL;

		// �������������
	while (scanf("%d %d\n", &x, &y) == 2)
	{
		adj[x] = New(y, adj[x]);
		adj[y] = New(x, adj[y]);
	}

	return 0;
}