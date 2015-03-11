#include "����2048��Ϸ1.0.h"
#include <ctime>
void Box::CreateBox(HWND hwnd, const int iBoxID , const int BoxSumNum)
{
	_hwndMain	= hwnd;
	_iBoxID		= iBoxID;
	srand((unsigned int)time(0));
	if (BoxSumNum <= 0)
		_iBoxSumNum = rand() % 2 * 2 + 2;	// ���û�и���ֵ, ��ô�����2��4
	else
		_iBoxSumNum	= BoxSumNum;
	wsprintf(_szBoxSumNum, TEXT("%d"), _iBoxSumNum);	// ������ת�����ַ�����ʽ
	_hwnd = CreateWindow(TEXT("button"), _szBoxSumNum,
						 WS_CHILDWINDOW,		// Ĭ���Ӵ��ڲ���ʾ
						 0, 0, 0, 0,
						 hwnd, (HMENU)(_iBoxID), 
						 (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
}

Box::Box()
{
	_iBoxSumNum		= -1;
	_szBoxSumNum[0] = 'N';
	_szBoxSumNum[1] = '\0';
	_iBoxID			= -1;
	_hwnd			= (HWND)-1;
	_isShow			= false;
	SetRect(&_rcBoxPos		, -1, -1, -1, -1);
	SetRect(&_rcMainClient	, -1, -1, -1, -1);
	_hwndMain		= (HWND)-1;
}

void Box::MoveBox(const RECT & _rcClient)
{
	int x = _iBoxID & 0xff;
	int y = _iBoxID >> 8;

		// Box���Ͻǵ�λ��
	POINT	ptPos;
	ptPos.x = _rcClient.right	/ DIVISION * x;
	ptPos.y = _rcClient.bottom	/ DIVISION * y;

		// Box�Ĵ�С
	int cx = _rcClient.right	/ DIVISION;
	int cy = _rcClient.bottom	/ DIVISION;
	MoveWindow(_hwnd, ptPos.x + 3,	 ptPos.y + 3, cx - 4, cy - 4,TRUE);

	SetRect(&_rcBoxPos, ptPos.x, ptPos.y, ptPos.x + cx, ptPos.y + cy);
	_rcMainClient = _rcClient;
}

void Box::Show()
{
	_isShow = true;
	ShowWindow(_hwnd, SW_SHOW);
}

void Box::Hide()
{
	_isShow = false;
	ShowWindow(_hwnd, SW_HIDE);
}

	// ������Box & ������Box
Box & SelectDir(Box BoxDiv[][4], EnumOffsetBox of, int & x, int & y, int flag = 0)
{
	switch (of)
	{
	case EnumLeft:	
		if (flag)
			return BoxDiv[y][x--];
		else 
			return BoxDiv[y][x-1];
	case EnumRight:	
		if (flag)
			return BoxDiv[y][x++];
		else
			return BoxDiv[y][x+1];
	case EnumUp:
		if (flag)
			return BoxDiv[y--][x];
		else
			return BoxDiv[y-1][x];
	case EnumDown: 
		if (flag)
			return BoxDiv[y++][x];
		else
			return BoxDiv[y+1][x];
	default:
		MessageBox(NULL, TEXT("SelectDir��������"), NULL, NULL);
		return BoxDiv[x][y];
	}
}

bool Box::OffsetBox(Box BoxDiv[][4], EnumOffsetBox of)
{
	int x = _iBoxID & 0xff;
	int y = _iBoxID >> 8;
	int flag = 0;	// ���ڱ���Ƿ��ƶ���Box

		// ps: ע��������Ϊ����

	for (;;)
	{
			// ���Ҫ���Ƶ�Box����ʾ��
		if (BoxDiv[y][x].GetIsShow())
		{
				// ���Ŀ��Box�������
		if ((of == EnumLeft		&& x == 0)				||	// ������ж�
			(of == EnumRight	&& x == DIVISION - 1)	||	// ���Ҷ��ж�
			(of == EnumUp		&& y == 0)				||	// ���϶��ж�
			(of == EnumDown		&& y == DIVISION - 1))		// ���¶��ж�
			break;

				// ���Ŀ��Box�����Box��ʾ
			if (SelectDir(BoxDiv, of, x, y).GetIsShow())
			{	
					// �����Box��Ŀ��Box���������ͬ
				if (SelectDir(BoxDiv, of, x, y).GetBoxSumNum() == BoxDiv[y][x].GetBoxSumNum())
				{
						// ������BoxΪ����Box�ĺ�, ����Ŀ��Box
					SelectDir(BoxDiv, of, x, y).SetBoxSumNum(SelectDir(BoxDiv, of, x, y).GetBoxSumNum() + BoxDiv[y][x].GetBoxSumNum());
					if (SendMessage(BoxDiv[y][x]._hwnd, BM_GETSTATE, 0, 0))
						SendMessage(BoxDiv[y][x]._hwnd, BM_SETSTATE, 0, 0);	// ���BoxҪ������, ���ﱣ֤������֮ǰ�Ƿǰ���״̬, �Է�ֹ�´���ʾ��ʱ���ǰ��µ�
					SendMessage(SelectDir(BoxDiv, of, x, y)._hwnd, BM_SETSTATE, 1, 0);	// ���ں��˵�Box��ʾ�����µ�״̬
					SelectDir(BoxDiv, of, x, y, 1).Hide();
					flag = 1;
					break;
				}
				else
					break;
			}	// ���Ŀ�����Box����ʾ
			else
			{
				SelectDir(BoxDiv, of, x, y).SetBoxSumNum(BoxDiv[y][x].GetBoxSumNum());
				SelectDir(BoxDiv, of, x, y).Show();
				if (SendMessage(BoxDiv[y][x]._hwnd, BM_GETSTATE, 0, 0))
					SendMessage(BoxDiv[y][x]._hwnd, BM_SETSTATE, 0, 0);	// ���BoxҪ������, ���ﱣ֤������֮ǰ�Ƿǰ���״̬, �Է�ֹ�´���ʾ��ʱ���ǰ��µ�
				SelectDir(BoxDiv, of, x, y, 1).Hide();
				flag = 1;
			}
			x = min(DIVISION - 1, max(0, x));
			y = min(DIVISION - 1, max(0, y));
		}
		else
			break;	
	}
	return flag == 1;
}