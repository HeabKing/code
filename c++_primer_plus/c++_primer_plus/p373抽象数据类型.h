// �����嵥 10.10 ͷ�ļ� -- �Լ�������ջ
#ifndef STAKC_H_
#define STAKC_H_

typedef unsigned long Item;  // �����Ҫdoubleջ���߽ṹ���͵�ջ, ��ֻ���޸�typedef���, ���������ͷ������屣�ֲ��� 14�µ���ģ���ṩ�˹��ܸ�ǿ��ķ���, �����������������������Ƹ��뿪��

class Stack  // �����ж��������(�������ݳ�Ա�����Ա������)��������Ϊ������, ������������δ֪��. ���ʹ�ò��ܴ��ⲿֱ�ӷ�����ĳ�Ա, ���г�Ա����Ҳ�����. Ҳ����˵, Ҫ���ù��г�Ա����, ����ͨ������, ���ڶ����Ա������ʱ��Ҳ����ʹ�������������
{
private:
	//const int max = 12;  // error C2864: ��Stack::max��: ֻ�о�̬�����������ݳ�Ա�ſ��������г�ʼ��    ����ԭ��: ������ֻ�������˶������ʽ, ��û�д�������, ����ڴ�������ǰ, ��û�����ڴ���ֵ�Ŀռ�
	//static const int max = 10;		// �⽫�ᴴ��һ����Ϊmax�ĳ���, �ó���������������̬����������һ��, �����Ǵ��ڶ�����
	enum {MAX = 10};  // constant specific to class  // �����ַ�ʽ����ö�ٲ����ᴴ�������ݳ�Ա, Ҳ����˵���ж����ж�������ö��, MAXֻ��һ����������, ��������Ϊ������Ĵ�����������ʱ, ��������30������
		// ö��: ��������һ���µ�"����", ���������������Ծ��е�ֵ, ������û�д����µı���(��enum aaa = MAX), ����������Ҫ�洢ֵ�Ŀռ�
	Item items[MAX];   // holds stack items		// ˽�в���˵��ջ��ʹ������ʵ�ֵ�, ���ǹ��в�����������һ��, ��˿���ʹ�ö�̬��������������, ������ı���Ľӿ�, ����ζ���޸�ջ��ʵ�ֺ�, ����Ҫ���±�дʹ��ջ�ĳ���
	int top;		     // index for top stack item
public:
	Stack();
	bool isempty() const;
	bool isfull() const;
	// push() returns false if stack already is full, true otherwise
	bool push(const Item & item);  // add item to stack
	// pup() returns false if stack already is empty, true otherwise
	bool pop(Item & item);  // pop top into item
};
#endif