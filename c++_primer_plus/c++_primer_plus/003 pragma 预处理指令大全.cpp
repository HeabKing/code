// ����: 2014-8-18 19:42:46

// #pragma para
// 1. message	����	�ڱ�����Ϣ������������Ӧ����Ϣ eg: ����Ĵ�����
// 2. code_seg	����	���ܹ����ó����к��������д�ŵĴ����, �������������ʱ����õ� #pragma code_seg(["section-name"["section-class"]])
// 3. once		����	ֻҪ��ͷ�ļ����ʼ����������ָ����ܹ���֤ͷ�ļ�������һ��, ���ǵ������Ժ�#ifndef �� �ĸ��Ӱ�ȫ��, ����������
// 4. hdrstop	����    ��ʾԤ����ͷ�ļ�����Ϊֹ, �����ͷ�ļ�������Ԥ����, BCB����Ԥ����ͷ�ļ��Լӿ����ӵ��ٶ�. ��ʱ��Ԫ֮����������ϵ, ���絥ԪA������ԪB, ���Ե�ԪBҪ���ڵ�ԪA����, ������#pragma startupָ���������ȼ�, ���ʹ����#pragma package(smart_init), BCB�ͻ�������ȼ��Ĵ�С�Ⱥ����
// 5. resource "*.dfm"	��*.dfm�ļ��е���Դ���빤��, *.dfm�а���������۵Ķ���
// 6. warning(disable: 4507 34; once: 4385; error: 164)
	// #pragma warning(disable: 4507 34) ����ʾ4507��34�ž�����Ϣ
	// #pragma warning(once: 4385) 4385�ž�����Ϣֻ��ʾһ��
	// #pragma warning(error: 164) ��164�ž�����Ϣ��Ϊһ������
	// #pragma warning(push, n) #pragma warning(pop)�Ȳ�������....
// 7. comment	����	��һ��ע�ͼ�¼����һ�������ļ����ִ���ļ��� eg: #pragma (lib, "winmm.lib")
// 8. #pragma loop_opt(on)	����ѭ���Ż����� #pragma loop_opt(off)	��ֹ
// ...

#include <iostream>
using namespace std;

#define MESSAGE

int main()
{
	// 1
#ifdef MESSAGE
#pragma message("Ԥ����ָ���ж�����MESSAGE��!")
#endif

	int iTemp = 0.23;

	// 6
#pragma warning(disable: 4244)	// ����һ�п�ʼ, ��ߵ�4244�ž���ȫ������ʾ
	int itemp = 1.23;	// warning C4244: ����ʼ����: �ӡ�double��ת������int�������ܶ�ʧ����

	
}