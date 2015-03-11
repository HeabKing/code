#include <windows.h>
class List
{
public:
	typedef RECT	Item;
	typedef struct	node
	{
		Item	item;
		node    * next;
	} * link;
	
private:
	node nilNode;	// �ڱ��ڵ�
	link linkTail;	// ָ��β�ڵ� ��ʼ��ָ������ڱ��ڵ�
	void ItemIni	(Item & item){ SetRect(&item, 0, 0, 0, 0); }				// �ض����� ��ʼ��
	void ItemAssign	(Item & L, Item & R){ L = R; }			// �ض����� ��ֵ
public:
	BOOL ItemIsEqual(Item & L, Item & R) { const int SNAKEWIDTH = L.right - L.left; POINT ptTemp = {R.left + SNAKEWIDTH / 2, R.top + SNAKEWIDTH / 2}; return ((PtInRect(&L, ptTemp))); }	// �ض����� �ж��Ƿ����
	int  length;

	List();
	~List();

			// ��

	// ��������, ���ܽ�һ������������ÿ���ڵ�
	void Travel(void (*fun)(link));

	// ��������, ����ָ����Ŀ�Ľڵ��ǰһ���ڵ��ҳ�
	link Search(Item, link beg = NULL);

	// ��ȡ�ڱ�/��ͷ/��β�ڵ������
	link GetSentinel()	{ return &nilNode; }
	link GetHead()		{ return nilNode.next; }
	link GetTail()		{ return linkTail; }

			// ��

	// ���������ָ��λ�����ӽڵ�
	void AddNext(link, link);
	void AddNext(link, Item);

	// ����ͷ���ӽڵ�
	void AddHead(link);
	void AddHead(Item);

	// ����β���ӽڵ�
	void AddTail(link);
	void AddTail(Item);

			// ɾ

	// �Ƴ�/ɾ������ָ�����Ӻ�ߵĽڵ�
	bool RemoveNext(link, link &);
	bool DelNext(link);

	// �Ƴ�/ɾ�����е�һ��ָ��item�ڵ�
	bool RemoveItem(Item, link &);
	bool DelItem(Item);

	// �Ƴ�/ɾ������ͷ�ڵ�
	bool RemoveHead(link &);
	bool DelHead();

	// �Ƴ�/ɾ������β�ڵ�
	bool RemoveTail(link &);
	bool DelTail();

			// ��

	// ����ָ���ڵ������Item
	void SetItem(link, Item);
};