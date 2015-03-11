#include <windows.h>

	// ����������, ֻ���ڸ���λ����ʾһ���̶���С(42 x 72)������

class BaseDigit
{
private:
	static const int DigitOriWidth = 42;
	static const int DigitOriHeight = 72;	// �����Digit�Ŀ�Ⱥ͸߶�
	int		digit;		// ��ʾ������
	HWND	hwnd;		// д�����������
	HBRUSH	hBrush;		// ��������ɫ�Ļ�ˢ, Ĭ���Ǻ�ɫ
	HPEN	hPen;		// ���ֵı߿�, Ĭ���Ǻ�ɫ
	static const BOOL	fSevenSegment[10][7];
	static const POINT	ptSegment[7][6];
protected:
	POINT	point;		// �����λ�ÿ�ʼд, ���Ͻ�����
	HDC		hdc;		// GetDC()��ȡ
public:
	BaseDigit(HWND, int x = 0, int y = 0, int _digit = 0);
	virtual ~BaseDigit();
	virtual void ShowDigit();
	void SetColor(COLORREF);	// �������ֵ���ɫ
	void SetColor(int r, int g, int b);
	void HideDigit();	// ����
	void OffsetDigit(int xOff, int yOff);
	static int GetOriWidth() { return DigitOriWidth; }
	static int GetOriHeight() { return DigitOriHeight; }
	void SetDigit(int _digit) { digit = _digit; }
};

	// ������ŵ�����

class ZoomDigit : public BaseDigit
{
private:
	int ZoomWidth;	// MM_ISOTROPICģʽ�µ��ӿڿ��	Ĭ��42
	int ZoomHeigh;	// MM_ISOTROPICģʽ�µ��ӿڸ߶�	Ĭ��72
	int WidthToHeigh();
public:
	ZoomDigit(HWND, int x, int y, int _digit = 0, int width = GetOriWidth());
	virtual ~ZoomDigit() {}
	void Zoom(int xOff);
	void ShowDigit();
};