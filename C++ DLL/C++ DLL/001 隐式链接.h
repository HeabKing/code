// Build: 2014-10-5 17:35:34
#ifndef HEABDLLEC
#define HEABDLLEC	extern "C" _declspec(dllimport)
#define HEABDLL		_declspec(dllimport)
#endif

HEABDLLEC int add(int a, int b);

class /*HEABDLL*/ Point	// ��������в��ܼ���extern "C"
{
public:
	void HEABDLL output(int x, int y);	// �������еķ���Ҳ����ʹ��extern "C"
	void input();
};