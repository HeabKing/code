//	1. ˫������ doubly linked list ������ singly linked	ͷ head	β tail	circular listѭ������
//	2. �ڱ�:
//		1. �������ӱ�ͷ�ͱ�β�ı߽�����, �����ĵ�����һ�������˫������ת�����һ�����ڱ���˫��ѭ������;
//		2. ʹ���ڱ��ĺô���ʹ�ô��������������ٶ�;
//		3. ����ʹ���ڱ��ռ�ɱ������������֮���ƽ��;
typedef struct node * link;
struct node
{
	int		key;	// �ؼ���key
	link	prev;
	link	next;
};

//#define ���ڱ�

#ifdef ���ڱ�
struct list
{
	link head;
};
#else
struct list
{
	node nil;
};
#endif

#ifdef ���ڱ�
link ListSearch(list & L, int k)
{
	link x = L.head;
	while (x != nullptr && x->key != k)
		x = x->next;
	return x;
}
#else
link ListSearch(list & L, int k)
{
	link x = L.nil.next;
	while (x != &L.nil && x->key != k)
		x = x->next;
	return x;
}
#endif

#ifdef ���ڱ�
// ���뵽�����ǰ��
void ListInseart(list & L, link x)
{
	x->prev = nullptr;
	x->next = L.head;
	if (nullptr != L.head)
		L.head->prev = x;
	L.head = x;
}
#else
void ListInseart(list & L, link x)
{
	x->prev = &L.nil;
	x->next = L.nil.next;
	L.nil.next->prev = x;
	L.nil.next = x;
}
#endif

#ifdef ���ڱ�
// �����ɾ��
void ListDelete(list & L, link x)
{
	if (nullptr != x->prev)
		x->prev->next = x->next;
	else
		L.head = x->next;
	if (nullptr != x->next)
		x->next->prev = x->prev;
}
#else
void ListDelete(list & L, link x)
{
	x->prev->next = x->next;
	x->next->prev = x->prev;
}
#endif