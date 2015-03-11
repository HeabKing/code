#include "05dxList.h"
#include <stdlib.h>

List::List()
{
	ItemIni(nilNode.item);
	nilNode.next = &nilNode;
	length	= 0;
	linkTail = &nilNode;
}

void List::Travel(void (*fun)(link))
{
	for (List::link x = GetHead(); x != GetSentinel(); x = x->next)
		fun(x);
}

List::link List::Search(Item item)	// Search���ص���Ŀ��ڵ�ǰһ���ڵ������
{
	for (List::link x = GetSentinel(); x->next != GetSentinel(); x = x->next)
		if (ItemIsEqual(x->next->item, item))
			return x;
	return nullptr;
}

// �������node�ĺ��������������������������ӽ�ȥ
void List::AddNext(link li, link li1)
{
	if (li == linkTail)	// ���Ҫ��β�ڵ��߲����½ڵ�, ��ôβ�ڵ�����Ӧ��ָ���½ڵ�
		linkTail = li1;
	li1->next	= li->next;
	li->next	= li1;
	length++;
}

void List::AddNext(link li, Item item)
{
	link t = (link)malloc(sizeof *t);
	ItemAssign(t->item, item);
	t->next = nullptr;
	AddNext(li, t);
}

void List::AddHead(link newLi)
{
	AddNext(GetSentinel(), newLi);
}

void List::AddHead(Item newItem)
{
	AddNext(GetSentinel(), newItem);
}

void List::AddTail(link li)
{
	AddNext(GetTail(), li);
}

void List::AddTail(Item item)
{
	AddNext(GetTail(), item);
}

bool List::RemoveNext(link li, link & t)
{
	if (GetSentinel() == li->next || !li)	// �����β�ڵ���߿�����, ������ɾ����һ����
		return false;
	t = li->next;
	li->next = li->next->next;
	length--;
	if (li->next == GetSentinel())			// ����Ƴ���β�ڵ�, ����linkTail
		linkTail = li;
	return true;
}

bool List::DelNext(link li)
{
	link t;
	if (!RemoveNext(li, t))
		return false;
	delete t;
	return true;
}

bool List::RemoveItem(Item item, link & t)
{
	link li;
	if (!(li = Search(item)))	// ���û���ҵ�(nullptr), ��ֱ�ӷ���false ע��: Search���ص���Ŀ��ڵ�ǰһ���ڵ������
		return false;
	RemoveNext(li, t);
	return true;
}

bool List::DelItem(Item item)
{
	link li;
	if (!(li = Search(item)))	// ���û���ҵ�(nullptr), ��ֱ�ӷ���false ע��: Search���ص���Ŀ��ڵ�ǰһ���ڵ������
		return false;
	DelNext(li);
	return true;
}

bool List::RemoveHead(link & t)
{
	if (GetSentinel()->next == GetSentinel())	// ���ֻ���ڱ��ڵ�, ���Ƴ�ʧ��
		return false;
	RemoveNext(GetSentinel(), t);
	return true;
}

bool List::DelHead()
{
	if (GetSentinel()->next == GetSentinel())	// ���ֻ���ڱ��ڵ�, ��ɾ��ʧ��
		return false;
	DelNext(GetSentinel());
	return true;
}

bool List::RemoveTail(link & t)
{
	if (GetSentinel()->next == GetSentinel())	// ���ֻ���ڱ��ڵ�, ���Ƴ�ʧ��
		return false;
	RemoveNext(Search(linkTail->item), t);
	return true;
}

bool List::DelTail()
{
	if (GetSentinel()->next == GetSentinel())	// ���ֻ���ڱ��ڵ�, ��ɾ��ʧ��
		return false;
	DelNext(Search(linkTail->item));
	return true;
}

List::~List()
{
	for (List::link x = GetHead(); x != GetSentinel(); x = GetHead())
		DelHead();
}

void List::SetItem(link li, Item item)
{
	ItemAssign(li->item, item);
}