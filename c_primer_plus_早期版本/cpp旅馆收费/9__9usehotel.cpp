// ��Դ�����ļ�����ı���
// c primer plus  �����嵥 9.9 p231
// usehotel.c -- �ùݷ����շѳ���
// ������嵥 9.10 һ�����
#include <stdio.h>
#include "9__11hotel.h"
#include "9__10hotel.cpp"                // ˫���ű�ʾ���������ļ�λ�ڵ�ǰ����Ŀ¼��(��Ŀ¼��һ�����Դ����)
int main (void)
{
	int nights;
	double hotel_rate;
	int code;

	while ((code = menu ()) != QUIT)
	{
		switch (code)
		{
			case 1: hotel_rate = HOTEL1;
			        break;
			case 2: hotel_rate = HOTEL2;
			        break;
			case 3: hotel_rate = HOTEL3;
			        break;
			case 4: hotel_rate = HOTEL4;
			        break;
			default: hotel_rate = 0.0;
				     printf ("Oops!\n");
					 break;
		}
		nights = getnights ();
		showprice (hotel_rate, nights);
	}
	printf ("Thank you and goodbye. ");
	
	return 0;
}