//c primer plus �����嵥4.4
//pizza.c  --  �������������������ʹ�ö��峣��
#include <stdio.h>
#define PI 3.14159
int main ()
{
	float area,circum,radius;  //area ��� circum �ܳ� radius �뾶

	printf ("What is the radius of your pizza?\n");
	scanf ("%f",&radius);
	area = PI * radius * radius;
	circum = 2.0 * radius * PI;
	printf ("Your basic pizza parameters are as follows:\n");
	printf ("circumference = %1.2f,area = %1.2f \n",circum,area);
	return 0;
}