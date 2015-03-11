// ���б����ͽӿ��ļ�
// �����嵥 17.3
#ifndef LIST_H_
#define LIST_H_

// ����û��stdbool.h
#define bool int
#define true 1
#define false 0

// �ض��ڳ��������
#define TSIZE 45
struct film
{
	char title[TSIZE];
	int rating;
};

// һ����������
typedef struct film Item;

typedef struct node
{
	Item item;
	struct node * next;
}Node;

typedef Node * List;
// ����ԭ��
// ����:   ��ʼ��һ���б�
// ����ǰ: plistָ��һ���б�
// ������: ���б���ʼ��Ϊ���б�
void InitializeList (List * plist);

// ����:   ȷ���б��Ƿ�Ϊ���б�
// ����ǰ: plistָ��һ���ѳ�ʼ�����б�
// ������: ������б�Ϊ���򷵻�true; ���򷵻�false
bool ListIsEmpty (const List * plist);  // *plist���б���׵�ַconstָ����plistָ����б���׵�ַ���ܱ��޸�, ����������Ķ��������޸�

// ����:   ȷ���б��Ƿ�����
// ����ǰ: plistָ��һ���ѳ�ʼ�����б�
// ������: ������б�����(�ڴ�ľ�)�򷵻�true; ���򷵻�false
bool ListIsFull (const List * plist);

// ����:   ȷ���б�����Ŀ�ĸ���
// ����ǰ: plistָ��һ���ѳ�ʼ�����б�
// ������: ���ظ��б��е���Ŀ����
unsigned int ListItemCount (const List * plist);

// ����:   ���б�β�����һ����Ŀ
// ����ǰ: item��Ҫ�����ӵ��б����Ŀ
//         plistָ��һ���ѳ�ʼ�����б�
// ������: ������ܵĻ�, ���б�β�����һ������Ŀ,
//         ��������true; ����������false
bool AddItem (Item item, List * plist);

// ����:   ��һ�������������б��е�ÿ����Ŀ
// ����ǰ: plistָ��һ���ѳ�ʼ�����б�
//         pfunָ��һ������, �ú�������һ��
//         Item���������޷���ֵ
// ������: pfunָ��ĺ��������õ��б��е�ÿ����Ŀһ��
void Traverse (const List * plist, void (* pfun)(Item item));

// ����:   �ͷ��ѷ�����ڴ� (�����)
// ����ǰ: plistָ��һ���ѳ�ʼ�����б�
// ������: Ϊ���б������ڴ��ѱ��ͷ�
//         ���Ҹ��б���Ϊ���б�
void EmptyTheList (List * plist);

#endif