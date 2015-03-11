class List
{
public:
	typedef int			Item;
	typedef struct node
	{
		Item	item;
		node    * next;
	} * link;
private:
	node nilNode;	// �ڱ��ڵ�
	link linkTail;	// ָ��β�ڵ� ��ʼ��ָ������ڱ��ڵ�
	void ItemIni	(Item & item){ item = 0; }				// �ض����� ��ʼ��
	void ItemAssign	(Item & L, Item & R){ L = R; }			// �ض����� ��ֵ
	bool ItemIsEqual(Item & L, Item & R) { return L == R; }	// �ض����� �ж��Ƿ����
	int  length;
public:
	List();
	~List();

			// ��

	// ��������, ���ܽ�һ������������ÿ���ڵ�
	void Travel(void (*fun)(link));

	// ��������, ����ָ����Ŀ�Ľڵ��ǰһ���ڵ��ҳ�
	link Search(Item);

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