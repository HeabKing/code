// �����ϰ 10.10 (8) ͷ�ļ�
#ifndef AAA
#define AAA
typedef int Item;  // Item ��Ŀ
class List
{
private:
	enum{LEN = 5};
	Item list[LEN];
	int top;
public:
	List();
	void show() const;
	bool add(Item);
	bool isempty() const;
	bool isfull() const;
	void visit(void (*pf)(Item &));  // pfָ��һ����Item������Ϊ�����ĺ���(���ǳ�Ա����)
		// visit���ú��������б��е�ÿ��������
};
#endif