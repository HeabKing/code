#include <iostream>
template<class T> T max5(const T []);
int main()
{
	int ar[5] = {1, 2, 3, 4, 5};
	double arr[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

	std::cout << max5(ar) << std::endl;
	std::cout << max5(arr) << std::endl;

	return 0;
}

template<class T> T max5 (const T ar[])
{
	T temp = ar[0];
	for (int i = 1; i < 5; i++) // ����Ͳ��ô�0��ʼ��, ��1��ʼ����
		if (ar[i] > temp)
			temp = ar[i];
	return temp;
}