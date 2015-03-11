#include "dxDigit.h"

	// �Ǿ�̬���ݳ�Ա�������ⶨ��, ��̬���ݳ�Ա�����ⶨ�岻�ü��Ϲؼ���static

		// ���ڿ�����ʾ�ĸ�����
const BOOL	BaseDigit::fSevenSegment[10][7] ={
				1, 1, 1, 0, 1, 1, 1,  // 0
				0, 0, 1, 0, 0, 1, 0,  // 1
				1, 0, 1, 1, 1, 0, 1,  // 2
				1, 0, 1, 1, 0, 1, 1,  // 3
				0, 1, 1, 1, 0, 1, 0,  // 4
				1, 1, 0, 1, 0, 1, 1,  // 5
				1, 1, 0, 1, 1, 1, 1,  // 6
				1, 0, 1, 0, 0, 1, 0,  // 7
				1, 1, 1, 1, 1, 1, 1,  // 8
				1, 1, 1, 1, 0, 1, 1	};// 9

		// ���ڿ����������ֵ�����
const POINT BaseDigit::ptSegment[7][6] = {
	7, 6, 11, 2, 31, 2, 35, 6, 31, 10, 11, 10,
	6, 7, 10, 11, 10, 31, 6, 35, 2, 31, 2, 11,
	36, 7, 40, 11, 40, 31, 36, 35, 32, 31, 32, 11,
	7, 36, 11, 32, 31, 32, 35, 36, 31, 40, 11, 40,
	6, 37, 10, 41, 10, 61, 6, 65, 2, 61, 2, 41,
	36, 37, 40, 41, 40, 61, 36, 65, 32, 61, 32, 41,
	7, 66, 11, 62, 31, 62, 35, 66, 31, 70, 11, 70 };

BaseDigit::BaseDigit(HWND _hwnd, int _x, int _y, int _digit)
{
	digit		= _digit;
	hwnd		= _hwnd;
	point.x		= _x;
	point.y		= _y;
	hdc			= GetDC(hwnd);
	hBrush		= CreateSolidBrush(RGB(255, 0, 0));
	hPen		= CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	SelectObject(hdc, hBrush);
	SelectObject(hdc, hPen);
}

BaseDigit::~BaseDigit()
{
	ReleaseDC	(hwnd, hdc);
	DeleteObject(hBrush);
	DeleteObject(hPen);
}

void BaseDigit::ShowDigit ()
{
		// �����ӿ�ԭ��λ��
	SetViewportOrgEx(hdc, point.x, point.y, NULL);

		// ��ʾ

	for (int iSeg = 0; iSeg < 7; iSeg++)
		if (fSevenSegment[digit][iSeg])
			Polygon(hdc, ptSegment[iSeg], 6);
}

void BaseDigit::SetColor(COLORREF color)
{
	HBRUSH hBrushPrev = hBrush;
	hBrush = CreateSolidBrush(color);
	hBrushPrev = (HBRUSH)SelectObject(hdc, hBrush);
	DeleteObject(hBrushPrev);
	ShowDigit();
}

void BaseDigit::SetColor(int r, int g, int b)
{
	SetColor(RGB(r, g, b));
}

void BaseDigit::HideDigit()
{
	SaveDC(hdc);
	HPEN hPenTemp = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	SelectObject(hdc, hPenTemp);		// ��ɫ����ѡ���豸����, Ĭ�ϵĿ��ɫ���ʲ��ܸ�������, ֻ���Լ�����
	SelectObject(hdc, (HBRUSH)GetStockObject(WHITE_BRUSH));	// ��ɫ��ˢѡ���豸����
	ShowDigit();	// ��ɫ����
	RestoreDC(hdc, -1);	// �ָ�ԭ�����豸����
	DeleteObject(hPenTemp);
}

void BaseDigit::OffsetDigit(int x, int y)
{
	point.x += x;
	point.y += y;
	ShowDigit();
}

	// ZoomDigit Class

int ZoomDigit::WidthToHeigh()
{
	return (GetOriHeight() * ZoomWidth / GetOriWidth());
}

ZoomDigit::ZoomDigit(HWND hwnd, int x, int y, int _digit, int width) : BaseDigit(hwnd, x, y, _digit)
{
	ZoomWidth = width;
	ZoomHeigh = WidthToHeigh();	// ���ø�ֵ����ʽ��Ϊ�˱����Ķ�
	if (ZoomWidth != GetOriWidth())	// �����������������, ִ�����ź���
	{
		//MessageBox(NULL, NULL, NULL, NULL);
		Zoom(ZoomWidth - GetOriWidth());
	}
}

void ZoomDigit::ShowDigit()
{
	//HideDigit();	// ��ԭ�������ص�
	SaveDC(hdc);
	SetMapMode(hdc, MM_ISOTROPIC);	// ��ӳ��ģʽ�ı�
	SetWindowExtEx(hdc, GetOriWidth(), GetOriHeight(), NULL);	// ���ڴ�С����Ϊһ��Digit��ԭʼ��С
	SetViewportExtEx(hdc, ZoomWidth, ZoomHeigh, NULL);
	BaseDigit::ShowDigit();
	RestoreDC(hdc, -1);
}

void ZoomDigit::Zoom(int xOff)
{
	HideDigit();
	ZoomWidth += xOff;
	ZoomHeigh = WidthToHeigh();
	ShowDigit();
}