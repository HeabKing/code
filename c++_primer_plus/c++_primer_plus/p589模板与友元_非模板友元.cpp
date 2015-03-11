
// ��������ܷ�ģ����Ԫ ���⻹��Լ��(bound)ģ����Ԫ ��Լ��(unbound)ģ����Ԫ

#include <iostream>

using std::cout;
using std::endl;

template<class T>
class HasFriend
{
private:
	T item;
	static int ct;  // ÿ�����͵�HasFriend�����Լ���ct
public:
	HasFriend(const T & i) : item(i) {ct++;}
	~HasFriend() {ct--;}
	friend void counts();  // �������͹������Ԫ
	friend void reports(HasFriend<T> &);  // ���ڵ������͵���Ԫ(��Ϊ���������������������͹���, ������ͷ��ϲ�����, �ǰ�)  ֱ��дHasFriend & �ǲ��е�, ��ΪHasFriend������, ֻ���ڸ������͵�ʵ��
	// ǰ�沢û��template<typename T>˵��������ģ�庯��, ��ֻ��һ��ʹ��һ��ģ���������ĺ���, ����ζ�ű���Ϊ�������ʾ���廯(��Ϊû�б���ָ��template <>)
};

template<typename T>
int HasFriend<T>::ct = 0;

void counts()
{
	cout << "int count: " << HasFriend<int>::ct << "; ";
	cout << "double count: " << HasFriend<double>::ct << endl;
}

void reports(HasFriend<int> & hf)
{
	cout << "HasFriend<int>: " << hf.item << endl;
}

void reports(HasFriend<double> & hf)
{
	cout << "HasFriend<double>: " << hf.item << endl;
}

int main()
{
	cout << "No objects declared: ";
	counts();
	HasFriend<int> hfi1(10);
	cout << "After hfi1 declared: ";
	counts();
	HasFriend<int> hfi2(20);
	cout << "After hfi2 declared: ";
	counts();
	HasFriend<double> hfdb(10.5);
	cout << "After hfdb declared: ";
	counts();
	reports(hfi1);
	reports(hfi2);
	reports(hfdb);


	return 0;
}