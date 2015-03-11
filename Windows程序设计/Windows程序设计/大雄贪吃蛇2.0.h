#include "dxList.h"		// ���ADT����
#include "dxDigit.h"	// ���ADT������ʾ

class Snake
{
private: 
	List snake;
	RECT rcFood;
public:
	Snake(int wid = 20, int len = 3, int x = 20 * 3, int y = 20 * 5);
	void Draw(HDC hdc);
	enum MoveDir { UP, DOWN, LEFT, RIGHT };
	bool Move(HWND, MoveDir);
	void RandomFood(HWND);
	void ShowFood(HWND);
	BOOL IsEat();
	BOOL IsDead(HWND);
	void Add() { snake.AddTail(snake.GetTail()->item); }
	void Resert(int wid = 20, int len = 3, int x = 20 * 3, int y = 20 * 5); 
};