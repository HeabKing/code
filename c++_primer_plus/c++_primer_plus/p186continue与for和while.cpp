// �Լ��ܽ�
// continue����for��while����΢��ͬ
// continue��䵼�¸ĳ�������ѭ�����ʣ�ಿ�ֵ��ǲ�������ѭ���ĸ��±��ʽ
#include <iostream>
int main()
{
	int i;
	for ( i = 0; i <= 10; i++)
		continue; // ֱ���������б��ʽ��, Ȼ���������Ա��ʽ��
	std::cout << "for:" << i << std::endl;
	i = 0;
	while ( i < 10 )
	{
		static int b = 0;
		b++;
		if ( 20 == b )
			break;
		continue; // ֱ���������±��ʽ��, �п��������˲��Ա��ʽ�������´���
		i++;
	}
	std::cout << "while:" << i << std::endl;

	return 0;
}