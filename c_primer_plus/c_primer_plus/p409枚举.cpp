// p409 �����嵥 14.15
// ������ͬһ���������г�������enum�е�ͬ���ı��, ����enum�е��໥��Ӱ��, �������Ǵ�0��ʼ��ֵ
#include <stdio.h>
#include <string.h>          // strcmp()
// #include <stdbool.h>		 // c99����
#define LEN 30

enum sprctrum {red, orange, yellow, green, blue, violet};
const char * colors[] = {"red", "orange", "yellow", "green",
						 "blue", "violet"};

int main (void)
{
	char choice[LEN];
	int color;// c++   ...   enum sprctrum color;// c
	bool color_is_found = false;

	puts ("����һ����ɫ(�����˳�):");
	while (gets (choice) != NULL && choice[0] != '\0')
	{
		for (color = red; color <= violet; color++)
			if (strcmp (choice, colors[color]) == 0)
			{
				color_is_found = true;
				break;
			}
		if (color_is_found)
			switch (color)
			{
				case red    : puts ("Roses are red.");
						      break;
				case orange : puts ("Poppies are orange.");
						      break;
				case yellow : puts ("Sunflowers are yellow.");
							  break;
				case green  : puts ("Grass is green.");
							  break;
				case blue   : puts ("Bluebells are blue.");
							  break;
				case violet : puts ("Violents are violent.");
							  break;
			}
		else
			puts ("�޷�ʶ�����ɫ!");
		color_is_found = false;
		puts ("����һ����ɫ(�����˳�):");
	}
	puts ("ok!");

	return 0;
}