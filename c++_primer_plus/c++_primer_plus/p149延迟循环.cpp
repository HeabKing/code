// �����嵥 5.14
#include <iostream>
#include <ctime>    // describes clock() function, clock_t type
int main()
{
	using namespace std;
	cout << "Enter the delay time in seconds: \n";
	float secs;
	cin >> secs;
	clock_t delay = secs * CLOCKS_PER_SEC; // convert(ת��, ʹת��) to clock ticks(�Ǻ�)
		// CLOCKS_PER_SEC ÿ���Ӱ�����ϵͳʱ�䵥λ��
		// clock_t delay �����������ת����long, unsigned int ���������ʺ�ϵͳ������
		// secs * CLOCKS_PER_SEC ����õ�ϵͳʱ�䵥λΪ��λ��ʱ��
		// clock_t clock()�������͵ı���
	cout << "starting\a\n";
	clock_t start = clock();
	while(clock() - start < delay)
		;
	cout << "done \a\n";

	return 0;
}
// ###### �ĳ�����ϵͳʱ�䵥λΪ��λִ�ж���������Ϊ��λִ��, ����������ÿ��ѭ������ʱ�䶼ת������ #####