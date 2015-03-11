#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

int main(void)
{
	using namespace std;

	int casts[10] = {6, 7, 2, 9, 4, 11, 8, 7, 10, 5};

	// STL sort()��������ָ��������һ��Ԫ�صĵ�������ָ��β�ĵ�����
	// ָ���������е�������Ҫ��, ��֧���������(��߼��������Ĺ���)
	cout << "����������ݽ�����������: \n";
	sort(casts, casts + 10);
	for (auto x: casts)
		cout << x << " ";
	cout << endl;

	vector<int> dice(10);
	// capyfrom array to vector
	copy(casts, casts + 10, dice.begin());  // �������ǹ���ָ��, ��ָ���������е�����Ҫ��, ��������STL�㷨�Ľӿ�, ��ָ���ǵ�����, ���STL�㷨����ʹ��ָ�����Ծ���ָ��ķ�STL�������в���, ����, ���Խ�STL�㷨��������
	// copy()��ǰ����������������ʾҪ���Ƶķ�Χ[), ���һ����������ʾҪ����һ��Ԫ�ظ��Ƶ�ʲôλ��, copy()�������Ḳ��Ŀ�������е�����, ͬʱĿ�����������㹻��, �Ա������ɱ����Ƶ�Ԫ��

	cout << "Let the dice be cast!\n";
	// creator an ostream iterator
	ostream_iterator<int, char> out_iter(cout, ", ");
	// int: ָ���˱����͸����������������
	// char: ָ����������ʹ�õ��ַ�����
	// cout: ָ����Ҫʹ�õ������, Ҳ�����������ļ��������
	// ", ": �ڷ��͸��������ÿ�����������ʾ�ķָ���
	cout << "*(out_iter++) = 15: ";
	*(out_iter++) = 15;  // works like cout << 15 << ", ";
	// ���ڳ���ָ��, ����ζ�Ž�15����ָ��ָ���λ��, Ȼ��ָ���1, ���Ƕ���ostream_iterator, ����ζ�Ž�15��", "��ɵ��ַ������͵�cout������������, ��Ϊ��һ���������������׼��
	cout << endl;
	
	// copy from vector to output
	copy(dice.begin(), dice.end(), out_iter);  // ����ζ�Ž�dice�������������䷢�͵��������, ��Ϊ��ʾ�������ڴ�
	cout << endl;
	cout << "Implicit use of recerse iterator.\n";
	copy(dice.rbegin(), dice.rend(), out_iter);
	cout << endl;

	// ���������
	cout << "Explicit use of recerse iterator.\n";
	vector<int>::reverse_iterator ri;
	for (ri = dice.rbegin(); ri != dice.rend(); ++ri)
		cout << *ri << ' ';
	cout << endl;

	return 0;
}