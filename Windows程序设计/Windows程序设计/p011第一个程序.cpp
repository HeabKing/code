#include <windows.h>
int WINAPI WinMain (  // WINAPI��һ�ֺ�������Լ��, �������!����!�ڶ�ջ�з��ú������ò����Ļ�������, �������windows�������ñ������WINAPI;
	HINSTANCE hInstance, // HINSTANCE(Instance Handle)  ʵ�����: ��������������ʶĳЩ����, �������������Ψһ��ʶ�����ǵ��������
	HINSTANCE hPrevInstance,  // ǰһ��ʵ�� ����ͨ���鿴�������֪���Ƿ�������ʵ���������� ����� ����ֱ�Ӻ��Ǹ���������ֻ������ ���������32λwindows���Ѳ�������, ���WinMain�Ĳ���ͨ����NULL
	PSTR szCmdLine,  // �������г����������, ��Щ���������е�ʱ�����������ļ�װ���ڴ�;
					// ���ｫLPSTR(Long Pointer String)�ĳ���PSTR, ��ΪLP��16λwindows�Ĳ���
	int iCmdShow)  // �����������ָ��������������ʾ(������ʾ������󻯵ȵ�) sz: ����������ִ� i: int
{
	// ��ʾ����Ϣ�ĶԻ���
	MessageBox (
		NULL,  // ���ھ�� �����½��� 
		TEXT ("Hello, MFC!"),  // ��Ϣ���г��ֵ��ı��ַ��� ��Щ�ַ����������TEXT���������, �������ѳ���ת����Unicodeʱ�᷽��ܶ�
		TEXT ("First Program"),  // ����������ʾ���ı�
		0 | MB_ICONHAND);
	return 0;
}