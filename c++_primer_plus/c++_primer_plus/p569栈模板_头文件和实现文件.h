// ��ģ��ͳ�Ա����ģ�岢������ͳ�Ա��������, ������c++������ָ��, ˵�������������ͳ�Ա��������, ʵ����(���廯)��ʱ����ɱ��������ɾ���Ĵ���
// ����ģ�岻�Ǻ���, ���ǲ��ܵ�������, ģ��������ض���ģ��ʵ��������һ��ʹ��, Ϊ��, ��򵥵ķ����ǽ����е�ģ����Ϣ����һ��ͷ�ļ���, ����Ҫʹ����Щģ����ļ��а�����ͷ�ļ�
#ifndef �����嵥14_13
#define �����嵥14_13
// ���԰�class��typename�������͵�˵����, �͸�int�Ǳ�����˵����һ��
template <class Type>  // template<Typename Type> ���ͱ�ʾ��Type���ﱻ��Ϊ���Ͳ���, �����ڱ���, ���Ǹ�ֵ�����ǵ������Ͷ�������ֵ
// �������������Ϊ�������ݸ������
class Stack
{
private:
	enum{MAX = 10};
	Type items[MAX];
	int top;
public:
	Stack();
	bool isempty() {return top == 0;}  // ������������ж����˷���(��������), �����ʡ��ǰ׺�����޶���
	bool isfull();
	bool push(const Type & item);  // add
	bool pop(Type & item);  // decerate
};

template <class Type> Stack<Type>::Stack()
{
	top = 0;
}

//template <class Type>
//bool Stack<Type>::isempty()
//{
//	return top == 0;
//}

template <class Type> bool Stack<Type>::isfull()
{
	return top == MAX;
}

template <class Type> bool Stack<Type>::push(const Type & item)
{
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}

template <class Type> bool Stack<Type>::pop(Type & item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}

#endif