// �����嵥 16.5 �������������Ŀɱ��
// ע��: ���ʹ����c���Եĺ�ִ�������ƺ����Ĺ���, ��ôӦ�ÿ��ǽ�����ת��Ϊc++����������, c++��������������Ĭ���ڲ����ӵ�, ������extern����Ϊ�ⲿ����, ����ֵ���ݶ����Ǻ��������ı�����
#include <stdio.h>
#include <math.h>
#define PR(x, ...) printf("Message" #x ": " __VA_ARGS__);
#define Min(x, y) ((x) < (y) ? (x) : (y))
//#define EVEN_GT(x, y) ((x)%2 == 0 ? ((x)>(y) ? 1 : 0) : 0)  // ��xΪż�����Ҵ���y��ʱ�򷵻�0
#define EVEN_GT(x, y) ((x)>(y) && (x) % 2 == 0 ? 1 : 0)
#define PRINT2(x, y) printf(#x " is  %d and " #y " is %d\n", x, y)  // ����һ���꺯��, ���ڴ�ӡ�����������ʽ����ֵ
#define WRITE_IN(x) printf("���������ַ������ɶ�λ�ı�, ��������(" #x "), ���ɹ���\n")
int main(void)
{
	double x = 48;
	double y;

	y = sqrt(x);
	PR(1, "x = %g\n", x);
	PR(2, "x = %.2f, y = %.2f\n", x, y);
	printf("5 �� 2 �н�С���� %d\n", Min(2, 5));
	printf("..%d..\n", EVEN_GT(6, 7));
	printf("..%d..\n", EVEN_GT(6, 5));
	printf("..%d..\n", EVEN_GT(7, 6));
	PRINT2(2, 3 * 4);
	`ZWRITE_IN(heshixiong);  // ��������ֻ�ܷ��ó���, ��Ԥ����׶δ���һ��


	return 0;
}