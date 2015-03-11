#ifndef DAXIONG2048_H_
#define DAXIONG2048_H_
#include <windows.h>
const  int	DIVISION =	4;
enum EnumOffsetBox{EnumLeft, EnumRight, EnumUp, EnumDown};
class Box
{
private:
	int		_iBoxSumNum;	// Box�������
	TCHAR	_szBoxSumNum[5];// Box����������ַ�����ʽ
	int		_iBoxID;		// Box��ID
	HWND	_hwnd;			// Box���
	bool	_isShow;		// Box�Ƿ���ʾ����
	RECT	_rcBoxPos;		// Box��λ�ô�С��
	RECT	_rcMainClient;	// ������RECT
	HWND	_hwndMain;		// �����ھ��
public:
	void CreateBox(HWND hwnd, const int iBoxID, const int BoxSumNum = -1);	// Ĭ��-1(�ڲ�����2 / 4���);
	Box();

	void MoveBox(const RECT & rcClient);	// ��Box�ƶ�����Ӧ��λ��
	void Show();
	void Hide();
	bool OffsetBox(Box [][4], EnumOffsetBox);
	RECT GetRcBoxPos() const {return _rcBoxPos;}
	HWND GetBoxHwnd() const {return _hwnd;}
	int	 GetBoxSumNum() const {return _iBoxSumNum;}
	bool GetIsShow() const {return _isShow;};
	void SetBoxSumNum(const int n) {_iBoxSumNum = n; wsprintf(_szBoxSumNum, TEXT("%d"), _iBoxSumNum); SetWindowText(_hwnd, _szBoxSumNum);}
};

#endif