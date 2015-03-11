#ifndef �����嵥14_17
#define �����嵥14_17
#include <iostream>
#include <cstdlib>
				// ���ʽ����ֻ��������, ö��, ����, ָ��, ����double n�Ǵ��, ����double * n�ǶԵ�.
template <class T, int n>  // ģ����벻���޸Ĳ�����ֵ, Ҳ����ʹ�ò����ĵ�ַ, ���Բ���ʹ��n++��&n�ȱ��ʽ, ʵ����ģ���ʱ����ʽ������ֵ�����ǳ������ʽ
class ArrayTP
{
private:
	T ar[n];
public:
	ArrayTP() {}
	explicit ArrayTP(const T & v);  // ��ÿ��Ԫ�ض���ʼ��Ϊ�βε���ֵ
	virtual T & operator[](int i);
	virtual T operator[](int i) const;
};

template <class T, int n>
ArrayTP<T, n>::ArrayTP(const T & v)
{
	for (int i = 0; i < n; i++)
		ar[i] = v;
}

template <class T, int n>
T & ArrayTP<T, n>::operator[](int i)
{
	if (i < 0 || i >= n)
	{
		std::cerr << "Error in array limits: " << i << " is out of range\n";
		std::exit(EXIT_FAILURE);
	}
	return ar[i];
}

template <class T, int n>
T ArrayTP<T, n>::operator[](int i) const
{
	if (i < 0 || i >= n)
	{
		std::cerr << "Error in array limits: " << i << " is out of range\n";
		std::exit(EXIT_FAILURE);
	}
	return ar[i];
}

#endif