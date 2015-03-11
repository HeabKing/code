#include "����̰����2.0.h"
#include <stdlib.h>
Snake::Snake(int wid, int len, int x, int y)
{
	for (int i = 0; i < len; i++)
	{
		List::Item t = {x, y + i * wid, x + wid, y + (i + 1) * wid};
		snake.AddTail(t);
	}
	SetRect(&rcFood, 20 * 5, 20 * 5, 20 * 5 + wid, 20 * 5 + wid);
}

void Snake::Draw(HDC hdc)
{
	List::link x = snake.GetHead();
	Rectangle(hdc, x->item.left, x->item.top, x->item.right, x->item.bottom);
	HBRUSH t = CreateSolidBrush(RGB(20, 20, 20));
	SelectObject(hdc, t);
	for (x = snake.GetHead()->next; x != snake.GetSentinel(); x = x->next)
		Rectangle(hdc, x->item.left, x->item.top, x->item.right, x->item.bottom);
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));
	DeleteObject(t);
}
 
bool Snake::Move(HWND hwnd, Snake::MoveDir dir)
{
	List::Item itemTemp = snake.GetHead()->item;

	int ofx = 0, ofy = 0;
	int wid = itemTemp.right - itemTemp.left; 
	switch (dir)
	{
	case Snake::UP:
		ofy = -wid;
		break;
	case Snake::DOWN:
		ofy = wid;
		break;
	case Snake::LEFT:
		ofx = -wid;
		break;
	case Snake::RIGHT:
		ofx = wid;
		break;
	}
	OffsetRect(&(itemTemp), ofx, ofy);
	if (snake.ItemIsEqual(itemTemp, snake.GetHead()->next->item))	// �����ͷ�ܵ����߲�����
		return true;	// ֻ�������˲ŷ���false

	List::link t;
	snake.RemoveTail(t);
	t->item = itemTemp;
	snake.AddHead(t);
	return !IsDead(hwnd);
}

void Snake::RandomFood(HWND hwnd)
{
	const int SNAKEWIDTH = snake.GetHead()->item.right - snake.GetHead()->item.left;
	RECT rcClient;
	GetClientRect(hwnd, &rcClient);

	// �������λ��
	srand(rand());
	rcFood.left		= rand() % (rcClient.right - SNAKEWIDTH/*��ֹʳ���ұ߲���Խ��*/)  / SNAKEWIDTH * SNAKEWIDTH;  // ��֤ʳ���������ͬһˮƽ����
	rcFood.top		= rand() % (rcClient.bottom - SNAKEWIDTH) / SNAKEWIDTH * SNAKEWIDTH;
	rcFood.right	= rcFood.left + SNAKEWIDTH;
	rcFood.bottom	= rcFood.top  + SNAKEWIDTH;
	if (snake.Search(rcFood))
		RandomFood(hwnd);
}

void Snake::ShowFood(HWND hwnd)
{
	HDC hdc = GetDC(hwnd);
	HBRUSH hbr = CreateSolidBrush(RGB(255, 0, 0));
	SelectObject(hdc, hbr);
	Rectangle(hdc, rcFood.left, rcFood.top, rcFood.right, rcFood.bottom);
	ReleaseDC(hwnd, hdc);
	DeleteObject(hbr);
}

BOOL Snake::IsEat()
{
	return snake.ItemIsEqual(snake.GetHead()->item, rcFood);
}

BOOL Snake::IsDead(HWND hwnd)
{
	if (snake.Search(snake.GetHead()->item, snake.GetHead()->next)) // �߳Ե����Լ�  ��!
		return true;

	List::link li = snake.GetHead();
	const int SNAKEWIDTH = li->item.right - li->item.left;
	POINT ptTemp = {li->item.left + SNAKEWIDTH / 2, li->item.top + SNAKEWIDTH / 2};	// ��ȡ��ͷ�е�
	RECT rcClient;
	GetClientRect(hwnd, &rcClient);
	if (!PtInRect(&rcClient, ptTemp))	// ��ײǽ��
		return true;
	return false;
}

void Snake::Resert(int wid, int len, int x, int y)
{
	snake.~List();
	for (int i = 0; i < len; i++)
	{
		List::Item t = {x, y + i * wid, x + wid, y + (i + 1) * wid};
		snake.AddTail(t);
	}
}