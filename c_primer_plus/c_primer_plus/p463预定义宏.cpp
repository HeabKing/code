#include <stdio.h>
#pragma c9x on  // ʹ֧��c99
void why_me ();
#line 4 "cool.cpp" // line ������һ�еĵ��к� // �ļ�������Ϊcool.cpp
int main ()
{
	printf ("The file is %s.\n", __FILE__);
	printf ("The date is %s.\n", __DATE__);
	printf ("The time is %s.\n", __TIME__);
	printf ("The version is %ld.\n", __STDC_SECURE_LIB__);
	printf ("This is line %d.\n", __LINE__);
	why_me ();
#if __STDC_SECURE_LIB__ != 200411
	#error Not C99
#endif
	return 0;
}
#line 100 
void why_me ()
{
	printf ("This is line %d.\n", __LINE__);
}