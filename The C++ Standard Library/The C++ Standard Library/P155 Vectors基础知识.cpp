			// ע��, vector�ĵ���������ʵ���汾������, Ҳ������һ��һ���ָ��

// 1.	vector ʸ��		ģ�ܳ�һ����̬����, �������: "��Ԫ�����ڶ�̬�����м��Թ���"	PS: C++Standard��δҪ������Զ�̬����ʵ��vector, ֻ�ǹ涨����Ӧ�����Ͳ������Ӷ�
// 2.	vector��Ԫ�ؿ�������������T, ���Ǳ���߱�assignable��copyable��������
// 3.	Vectors������:
		// 1.	vectors��Ԫ�ظ��Ƶ��ڲ���dynamic array��, Ԫ��֮�����Ǵ���ĳ��˳��, ������(ordered collection)
		// 2.	֧�������ȡ(����ʱ��), vector�ĵ������������ȡ������, ���Զ��κ�һ��STL�㷨����Ч
		// 3.	��ĩ����ӻ�ɾ��Ԫ��ʱ, vector�������൱��, ǰ�˻��в��Ͳ���ô����
// 4.	��С(Size)������(Capacity)
		// 1.	������С�ĺ���	
			// 1.	size()		���������е�Ԫ������
			// 2.	empty()		�ж������Ƿ�Ϊ��(�൱��size() == 0, �����ܸ���)
			// 3.	max_size()	����Ԫ�ص�����������
			// 4.	capacity()	����vectorʵ�������ɵ�Ԫ������, ��������������, vector���б�Ҫ���������ڲ��洢��
		// 2.	vector����������Ҫ
			// 1.	һ���ڴ���������, ��vectorԪ����ص�����references, pointers, iterators����ʧЧ
			// 2.	�ڴ����·���ܺ�ʱ��	�������vector������references, pointers, iterators����ִ���ٶȺ���Ҫ, �ͱ��뿼�Ǽ���������
			// 3.	��ǰ�����ʵ�����, ����һ�����������ڴ�:
				// 1.	std::vector<int> v;	v.reserve(80);	reserve(����, ����, Ԥ��) ����һ����vectorȻ��Ԥ����80��Ԫ�صĿռ��С Ԥ���ڴ治��������ʹ��!
				// 2.	std::vector<T> v(5);	����һ��vectorȻ����5��values��ʼ����, ����T���͵Ĺ��캯��5��, ��Ȼ, Ҫ�����������, ����Ԫ�ر����ṩһ��default���캯��, ��Ȼ, ��ܺ�ʱ, ���ֻ��Ϊ�˱����㹻�ڴ�, ������ʹ��reserve()	 PS: ע��, ���T��int�Ȼ����ͱ�, ���Ĺ��캯�����ѻ����ͱ��ʼ��Ϊ��, ��: int i1; int i2 = int();
				// 3.	Vectors�����������Ϻ�strings����, ������һ����ͬ��, vector����ʹ��reserve()����������, �������reserve()�����Ĳ����ȵ�ǰvector��������С, ���������κη�Ӧ
				// 4.	std::vector<int> v; ����һ����vector, ���ǵ���һ�ΰ���Ԫ��ʱ��һ�������������ڴ�(����2k, ����ʵ��????������reserve()�Լ��ֵ�??????), ����, �������һ���vectors, ÿ��Vectorsʵ��Ԫ��ȴ�����޼�, ��ô�˷ѵ��ڴ潫��ǳ��ɹ�
				// 5.	��Ϊvectors��������������, ���Լ�ʹɾ��Ԫ��, ��references, pointers, interatorҲ�������Ч, Ȼ���������ȴ����ʹreferences, pointer, iteratorsʧЧ(��Ϊ������ܵ���vector���������ڴ�ռ�)
		// 3.	�������vector������С����
			// 1.	����vectors����������, ���ߵ�����Ҳ�ụ��
				// 1.	template<class T>
				//		void shrinkCapacity(std::vector<T> & v)
				//		{ std::vector<T> temp(v);	// copy elements into a new vector // ������ʱtemp����v��ʱ��ֻ����Ԫ��, �����͵�ַ������
				//		  v.swap(temp);}			// swap internal vector data	internal �ڲ���		// �ٰ�temp��v�Ի�, ʵ�������ǵĶ�ָ�뻥��Ե���
				// 2.	�ϱ�ʹ��references, pointers, iterators��ʧЧ��
			// 2.	��������ֱ����������
				// 1.	std::vector<T>(v).swap(v);	// ���ϱߵ�����������һ�������
// 5.	Vector�Ĳ�������
	// 1.	����, ����
		// 1.	vector<Elem> c;			// ����һ����vector, ����û���κ�Ԫ��, û���κ�����
		// 2.	vector<Elem> c1(c2);	// ����ͬ����vector�ĸ���(����Ԫ�ض�������, ����������, ��ַ��һ��)
		// 3.	vector<Elem> c(n);		// ����Ԫ�ص�default���캯������һ����СΪn��vector, ����������int()����0
		// 4.	vector<Elem> c(n, elem)	// ����һ����СΪn��vector, ÿһ��Ԫ�ض���elem
		// 5.	vector<Elem> c(beg, end)// ����һ��vector ������[beg, end]��ΪԪ�س�ֵ
		// 6.	c.~vector<Elem>()		// ��������Ԫ��, ���ͷ��ڴ�
	// 2.	�Ǳ䶯�Բ�������
		// c.size() c.empty() c.max_size() capacity() reserve() c1 == c2  c1 != c2  c1 < c2  c1 > c2  c1 <= c2  c1 >= c2
		// PS: reserve()��ȷ����ױ䶯(modify)vector, ��Ϊ���������references, pointers��iteratorsʧЧ, ����, ���߼���˵, ������û�з����仯, ���Ի��ǰ�����������
	// 3.	��ֵ����
		// 1.	c1 = c2 ��c2��ȫ��Ԫ�ظ�ֵ��c1, Ԥ������������, ��ַ��һ
		// 2.	c.assign(n, elem)	����n��elem, ��ֵ��c, c���n��Ԫ�ػᱻ���óɱ�������
		// 3.	c.assign(beg, end)	������[beg, end)�ڵ�Ԫ�ظ�ֵ��c, ����beg, endָ���ǵ�����
		// 4.	c1.swap(c2)			��c1��c2Ԫ�ػ���, �ڲ�ָ��ѵ�ָ��Ի�, ���Ա�������, ��ַ�����˹�ȥ�����ֲ���
		// 5.	swap(c1, c2);		ͬ��, ��Ϊȫ�ֺ���
	// 4.	Ԫ�ش�ȡ
		// 1.	c.at(idx)	����idx����ʾ��Ԫ��, ���idxԽ��, �׳�out_of_range
		// 2.	c[idx]		����idx����ʾ��Ԫ��, !�����з�Χ���
		// 3.	c.front()	���ص�һ��Ԫ��, !������һ��Ԫ���Ƿ����
		// 4.	c.back()	�������һ��Ԫ��, !��������һ��Ԫ���Ƿ����
	// 5.	��������غ���  PS: vector��������random access iterators(�����ȡ������), �����Ͻ�����ͨ�������������������STL�㷨
				// ��������ȷ���ͱ���ʵ���汾����, ����Vectors, ͨ������һ��ָ��, һ��ָ����������ȡ������	
				// ������������Ч, ���Ƿ��������������:	1. ʹ�����ڽ�С����λ�ð�����Ƴ�Ԫ�� 2. ���������仯��������ڴ����·���
		// 1.	c.begin()	����һ�������ȡ������, ָ���һ��Ԫ��
		// 2.	c.end()		����һ�������ȡ������, ָ�����Ԫ�ص� !��һ��λ��
		// 3.	c.rbegin()	����һ�����������, ָ������������ĵ�һ��Ԫ��
		// 4.	c.rend()	����һ�����������, ָ����������������Ԫ�ص���һ��λ��
	// 6.	vector�İ���, �Ƴ���ز���
		// 1.	c.insert(pos, elem)		��posλ���ϲ���һ��elem����, ��������Ԫ��λ��
		// 2.	c.insert(pos, n, elem)	��posλ���ϲ���n��elem����, �޻ش�ֵ
		// 3.	c.insert(pos, beg, end) ��posλ���ϲ�������[beg, end]�ڵ�����Ԫ�صĸ���, �޴���ֵ
		// 4.	c.push_back(elem)		��β�����һ��elem����
		// 5.	c.pop_back()			�Ƴ����һ��Ԫ��, �����ش�
		// 6.	c.erase(pos)			�Ƴ�posλ���ϵ�Ԫ��, ������һ��Ԫ�ص�λ��, ���п��ܷ��ص���pos, ��Ϊ��һ��Ԫ���油��ǰ��ȥ��
		// 7.	c.erase(beg, end)		�Ƴ�[beg, end)�����ڵ�����Ԫ��, ������һ��Ԫ�ص�λ��
		// 8.	c.resize(num)			��Ԫ��������Ϊnum(���size()�����, �������Ԫ�ض���Ҫ��default���캯���������)
		// 9.	c.resize(num, elem)		��Ԫ��������Ϊnum(���size()�����, �������Ԫ�ض���elem�ĸ���)
		// 10.	c.clear()				�Ƴ�����Ԫ��, ���������
// 6.	�쳣����(Exceptional Handling): ������ϸ����, ����P156

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
bool jiangxu(int &, int &);
int main()
{
	int i0 = int();	// �����ͱ�� "����������, ��ȷ�Ĺ��캯������" , �����ͱ��ʼ��Ϊ0
		// ����Ա�֤׫дtemplate��������ʱ��, �κ��ͱ���һ��ȷ�еĳ�ֵ
		// ������ʾ����default���캯�����г�ʼ��ʱ���Ե�

	// ������ʽ���û����ͱ��default���캯���ǲ����Ե�
	// int i1(); error LNK2019: �޷��������ⲿ���� "int __cdecl i1(void)" (?i1@@YAHXZ)���÷����ں��� _main �б�����
	std::cout << "�����ͱ�Ĭ�Ϲ����ʼ��i0 = " << i0 << std::endl;

	// ����, ����
	std::vector<int> c;	// ����һ����vector, ����û���κ�Ԫ��
	//std::cout << c[0];	// ���������ڼ��warning, ��ʾԽ��
	//std::cout << c.at(0);	// �׳��쳣, �����ڼ�abort()
	std::cout << "c��������: " << c.capacity() << std::endl;
	std::cout << "c��������������: " << c.max_size() << std::endl << std::endl;
	std::vector<int> c1(1);	// ��ʼ��һ��Ԫ�ػᵼ�¶�����ڴ���? ����
	std::cout << "c1[0] = " << c1[0] << std::endl;	// ��ʾ���û������͵Ĺ��캯��int(), ��ʼ��Ϊ0
	//std::cout << c1[1];	// ���������ڼ��warning, ��ʾԽ��
	//std::cout << c1.at(1);	// �׳��쳣, �����ڼ�abort()
	std::cout << "c1��������: " << c1.capacity() << std::endl << std::endl;
	
	std::vector<int> c2(1);
	c2.reserve(20);	// �������� �ɹ�
	std::cout << "c2��Ԫ��������: " << c2.size() << "   c2��������: " << c2.capacity() << "    ��ַ��: " << (void *)&(c2[0]) << std::endl;
	c2.reserve(10);	// reserve() ��С���� ʧ��
	std::cout << "c2��Ԫ��������: " << c2.size() << "   c2��������: " << c2.capacity() << "    ��ַ��: " << (void *)&(c2[0]) << std::endl << std::endl;

	std::cout << "c1��Ԫ��������: " << c1.size() << "   c1��������: " << c1.capacity() << "    ��ַ��: " << (void *)&(c1[0]) << std::endl;
	c2.swap(c1);	// ������С���� �ɹ�	// ������c2ָ����c1�Ķ�λ��, c1ָ����c2�Ķ�λ��
	std::cout << "c2��Ԫ��������: " << c2.size() << "   c2��������: " << c2.capacity() << "    ��ַ��: " << (void *)&(c2[0]) << std::endl;
	std::cout << "c1��Ԫ��������: " << c1.size() << "   c1��������: " << c1.capacity() << "    ��ַ��: " << (void *)&(c1[0]) << std::endl << std::endl;

	c2.reserve(5);	// ��ֳ������ǲ�����δ��ʼ����
	std::cout << "c2��������������: " << c2.max_size() << std::endl;
	std::cout << "c2��Ԫ��������: " << c2.size() << "   c2��������: " << c2.capacity() << "    ��ַ��: " << (void *)&(c2[0]) << std::endl << std::endl;

	std::vector<int> c3(3);	// ���е�����Ԫ�س�ʼ��Ϊint()��0
	c3.reserve(20);
	c3.at(2) = 2;	// ��ʼ���������ڴ��ǳ���Ա��������������õ�
	//c3.at(4) = 4;	// Ԥ�����ڴ���Ϊ���Զ������ʱ��ʡ�����·����ڴ�, ����Ա�Լ������ʹ�õ�ֻ�г�ʼ��ʱָ�����ڴ��С
	//std::cout << c3.at(1);����ʹ��δ��ʼ����
	std::cout << c3.at(2) << std::endl;
	std::cout << "c3��Ԫ��������: " << c3.size() << "   c3��������: " << c3.capacity() << "    ��ַ��: " << (void *)&(c3[0]) << std::endl << std::endl;
	c3.swap(c3);	// �����Ľ�������ʵ����С����
	std::cout << "c3��Ԫ��������: " << c3.size() << "   c3��������: " << c3.capacity() << "    ��ַ��: " << (void *)&(c3[0]) << std::endl << std::endl;
	std::vector<int>(c3).swap(c3);	// �����Ľ���������С����	����һ����ʱ����, ������c3������Ȼ����c3����   ʵ��������ʱ�������ɿ�����ʱ���������С��, ����, �������ִ�����Ժ�, !!!!c3�ĵ�ַҲ�����˸ı�!!!
	std::cout << "c3��Ԫ��������: " << c3.size() << "   c3��������: " << c3.capacity() << "    ��ַ��: " << (void *)&(c3[0]) << std::endl << std::endl;

	std::vector<int> c4(c2);	// ��ʼ����ʱ��Ŀ�����c4ֻ����c2��Ԫ��, �����͵�ַ����һ��
	std::cout << "c4��Ԫ��������: " << c4.size() << "   c4��������: " << c4.capacity() << "    ��ַ��: " << (void *)&(c4[0]) << std::endl << std::endl;

	std::vector<int> c5(5, 6);
	std::cout << "c5�е�����Ԫ�ض�����ʼ��Ϊ: " << std::endl;
	for (std::vector<int>::iterator i = c5.begin(); i < c5.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
	std::cout << "c5��Ԫ��������: " << c5.size() << "   c5��������: " << c5.capacity() << "    ��ַ��: " << (void *)&(c5[0]) << std::endl << std::endl;

	//std::vector<int> c6(); ���캯���еķ�Χ��ֵ>>>>>>>???????????????????????????
	std::vector<int> c7;
	c5.reserve(10);
	std::cout << "c5��Ԫ��������: " << c5.size() << "   c5��������: " << c5.capacity() << "    ��ַ��: " << (void *)&(c5[0]) << std::endl;
	c7 = c5;
	std::cout << "c7��Ԫ��������: " << c7.size() << "   c7��������: " << c7.capacity() << "    ��ַ��: " << (void *)&(c7[0]) << std::endl;
	for (std::vector<int>::iterator i = c7.begin(); i != c7.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
	c7.assign(3, 4);
	for (std::vector<int>::iterator i = c7.begin(); i != c7.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
	std::cout << "c7��Ԫ��������: " << c7.size() << "   c7��������: " << c7.capacity() << "    ��ַ��: " << (void *)&(c7[0]) << std::endl;
	std::vector<int> c8(10);
	std::cout << "c8������: ";
	int j = 0;
	for (std::vector<int>::iterator i = c8.begin(); i != c8.end(); ++i, ++j)
	{
		*i = j;
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	c7.assign(c8.begin(), c8.end());	// [beg, end)
	std::cout << "c7.assign(c8.begin(), c8.end());֮���c7����: ";
	for (std::vector<int>::iterator i = c7.begin(); i != c7.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
	std::cout << "c7.front() = " << c7.front() << std::endl;
	std::cout << "c7.back() = " << c7.back() << std::endl << std::endl;

	std::vector<int> c9;
	// std::cout << c9.front(); ���г���, ˵����ʱ��Ч��    !!!!����˵�ķ���Խ������δ������Ϊ

	std::vector<int> c10(4);
	c10.reserve(20);
	j = 0;
	std::cout << "c10��������: \n";
	for (std::vector<int>::iterator i = c10.begin(); i != c10.end(); ++i, ++j)
	{
		*i = j;
		std::cout << &(*i) << "��ַ�µ�: " << *i << " \n";
	}
	std::cout << std::endl;
	std::cout << *c10.erase(c10.begin()) << std::endl;	// �ѵ�����c10.begin()λ�� �� ��Ԫ���Ƴ���, Ȼ��۲��ַ���Կ�����ߵ�Ԫ�ز�����ǰ���ȱ��λ��
		// erase������pos��һ��Ԫ�صĵ����� ���ں�һ��Ԫ���油�����Ƴ�Ԫ�ص�λ��, ���Է��صĻ���pos��λ��, �����ؾɵ�c10.begin(), �µ�c10.begin()==�ɵ�
		// ��Ȼ ������ϱߵĶ�begin�ĳ�end�ͳ�����, RUNTIMEERROR: δ�������Ϊ

	std::cout << "c10.erase(c10.begin()): \n";
	for (std::vector<int>::iterator i = c10.begin(); i != c10.end(); ++i)
		std::cout << &(*i) << "��ַ�µ�: " << *i << " \n";
	std::cout << *c10.insert(c10.begin(), 0) << std::endl;
	std::cout << "c10.insert(c10.begin(): \n";
	for (std::vector<int>::iterator i = c10.begin(); i != c10.end(); ++i)
		std::cout << &(*i) << "��ַ�µ�: " << *i << " \n";
	std::vector<int>temp(c10.begin(), c10.begin() + 3);	// ����c10��Ҫ�Ƴ��Ĳ���
	std::cout << *c10.erase(c10.begin(), c10.begin() + 3) << std::endl;	// ��[beg, end)�Ƴ���
	std::cout << "c10.erase(c10.begin(), c10.begin() + 3)\n";
	for (std::vector<int>::iterator i = c10.begin(); i != c10.end(); ++i)
		std::cout << &(*i) << "��ַ�µ�: " << *i << " \n";
	std::cout << *c10.insert(c10.begin(), 3, -1);	// ˵��û�з���ֵ, ʵ�ʲ��Է����˵�һ����Ԫ�ص�λ��std::cout << &(*c10.insert(c10.begin(), 3, -1));
	std::cout << "c10.insert(c10.begin(), 3, -1):\n";
	for (std::vector<int>::iterator i = c10.begin(); i != c10.end(); ++i)
		std::cout << &(*i) << "��ַ�µ�: " << *i << " \n";
	std::cout << *c10.insert(c10.begin(), temp.begin(), temp.end()) << std::endl;	// ˵��[beg, end]����ʵ�ʲ�����[beg, end)
	std::cout << "c10.insert(c10.begin(), temp.begin(), temp.end()):\n";
	for (std::vector<int>::iterator i = c10.begin(); i != c10.end(); ++i)
		std::cout << &(*i) << "��ַ�µ�: " << *i << " \n";
	
	std::cout << "����pop_back()ɾ��c10���е�Ԫ��: \n";
	j = (int)c10.size();	// ��Ϊpop_back()��ͬʱ, c10.size()�ǲ��ϱ仯��, ���Բ���ֱ�ӷ���forѭ���е�j��λ��
	for (int i = 0; i < j; i++)
		c10.pop_back();
	for (std::vector<int>::iterator i = c10.begin(); i != c10.end(); ++i)
		std::cout << &(*i) << "��ַ�µ�: " << *i << " \n";
	std::cout << "c10��û��Ԫ����\n";

	std::cout << "����c10.resize(5)��size()���: \n";	// ���Ĳ�����Ԫ�ص�default���캯�����
	c10.resize(5);
	for (std::vector<int>::iterator i = c10.begin(); i != c10.end(); ++i)
		std::cout << &(*i) << "��ַ�µ�: " << *i << " \n";
	std::cout << "����c10.resize(10, 1)��size()���: \n";	// ���Ĳ�����1�ĸ������
	c10.resize(10, 1);
	for (std::vector<int>::iterator i = c10.begin(); i != c10.end(); ++i)
		std::cout << &(*i) << "��ַ�µ�: " << *i << " \n";
	std::cout << "����c10.clear()���Ԫ��: \n";
	c10.clear();
	for (std::vector<int>::iterator i = c10.begin(); i != c10.end(); ++i)
		std::cout << &(*i) << "��ַ�µ�: " << *i << " \n";
	std::cout << "c10��û��Ԫ����\n";

	std::vector<int> c11;
	for (int i = 0; i < 6; i++)
	{
		c11.insert(c11.begin(), i);
		c11.push_back(i);
	}
	std::vector<int> c12(c11);
	std::cout << "\nc11�е�����Ԫ������: \n";
	for (std::vector<int>::iterator i = c11.begin(); i != c11.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;

		// algorithm �е�remove(beg, end, elem)�㷨ɾ�������е� !����! ��elem��ȵ�������
		// algorithm �е�find(beg, end, elem)Ѱ�ҵ������е�һ����elem��ȵ�λ��, ���vector<T>::earse()����ʵ��ɾ����һ����Ч��
		// algorithm �е�diatance(beg, end)��������������֮��ľ���

	std::cout << "�����㷨��c11������value == 3��Ԫ��ɾ��: \n";
	remove(c11.begin(), c11.end(), 3);	// Ԫ��3��������, ��������4 5 ����Ԫ��û��Ԫ�ظ�������
		// ʵ����remove()��û�иı�Ⱥ���е�Ԫ������, ���Ǵ��߼��Ͻ�, 4 5�Ѿ����������Ⱥ����
		// ����, ����㷨������һ���µ��յ�(���һ��Ԫ�صĺ�һ��λ��), �������ø��յ����µ�����, �����������Ĵ�С, ���Ǳ�ɾ��Ԫ�صĸ���
		// remove������eraseֱ��ɾ����������� 4 5 ��STLΪ�˻�ȡ����Զ������Ĵ���, STL�����ݺ��㷨���뿪��, Ȼ��, ������ֻ��"�����е�ĳһλ��"�ĳ������, ����, ���������Լ�����������һ����֪, ����, end��ߵ�Ԫ������˭��Ҳ��֪��, ���������ǰ��(���֪�����������erase()������, ��������֪��), Ҳ������Ϊ����, �κ�"�Ե�������������Ԫ��"���㷨������(�޷�)͸��������������������ṩ���κγ�Ա����(������erase()), ������Ƶ�һ����Ҫ�����: �㷨�Ĳ�������һ����"�����ڵ�ȫ��Ԫ��"���γɵ�����, ����������ЩԪ�ص��Ӽ�, �����㷨����������һ��"��δ�ṩ��Ա����erase()"������(array����һ������), ����, Ϊ�˴���㷨�������, ��Ҫ��"�����������˽���������ϸ��"���Ǻ��е����...

	for (std::vector<int>::iterator i = c11.begin(); i != c11.end(); ++i)
		std::cout << *i << " ";

	std::cout << "\nremove�㷨�ĸĽ��汾:\n";
	std::cout << "c12�е�����Ԫ������: \n";
	for (std::vector<int>::iterator i = c12.begin(); i != c12.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
	std::vector<int>::iterator end = remove(c12.begin(), c12.end(), 3);	// remove�����µ��յ�
	std::cout << "��ɾ���� " << distance(end, c12.end()) << " ��Ԫ��\n";
	c12.erase(end, c12.end());
	for (std::vector<int>::iterator i = c12.begin(); i != c12.end(); ++i)
		std::cout << *i << " ";
	std::cout << "\nֻ���Ƴ�c12�еĵ�һ��4: \n";
	std::vector<int>::iterator pos;
	pos = find(c12.begin(), c12.end(), 4);	// ���û���ҵ��Ļ����ص���end��ֵ
	if (pos != c12.end())	// ����ҵ��˾Ͳ���
		c12.erase(pos);
	for (std::vector<int>::iterator i = c12.begin(); i != c12.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;

	// algorithm �е� fill(beg, end, elem) ʵ����һ���ض���ֵ��װһ������
	std::cout << "algorithm �е� fill ʵ����һ���ض���ֵ��װһ������: \n";
	std::fill(c12.begin(), c12.end(), 9);
	for (std::vector<int>::const_iterator i = c12.begin(); i != c12.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;

	// algorithm �е� copy(c1.beg, c1.end, c2.beg) ʵ�ֽ�һ���������ֵ���Ƶ���һ��(��ͬһ��, ֻҪ���䲻�ص�)������
	std::cout << "algorithm �е� copy ������c13: \n";
	std::vector<int> c13;
	std::cout << "c13����������: \n";
	for (int i = 0; i < 10; ++i)
	{
		c13.push_back(i);
		std::cout << c13.at(i) << " ";
	}
	std::cout << "\ncopy�Ժ�Ľ������:\n";
	std::copy(c13.begin(), c13.begin() + 4, c13.end() - 4);
	for (std::vector<int>::const_iterator i = c13.begin(); i != c13.end(); ++i)
		std::cout << *i << " ";
	std::cout << "\n";

	// algorithm �е� sort() ���������������е���
	std::cout << "std::sort(c13.begin(), c13.end()):\n";
	std::sort(c13.begin(), c13.end());
	for (std::vector<int>::const_iterator i = c13.begin(); i != c13.end(); ++i)
		std::cout << *i << " ";
	// ��Ϊ����
	std::cout << "\nstd::sort(c13.begin(), c13.end(), jiangxu): \n";
	std::sort(c13.begin(), c13.end(), jiangxu);
	for (std::vector<int>::const_iterator i = c13.begin(); i != c13.end(); ++i)
		std::cout << *i << " ";

	// string
	std::string str;
}

bool jiangxu(int & i1, int & i2)
{
	return i1 > i2;
}