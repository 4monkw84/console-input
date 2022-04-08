#include "EnemyExample.h"

//same as function in Main.cpp - sets console cursor position
void EnemyExample::setCursorPosition(short a, short b)
{
	{
		COORD pos = { a,b };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
}

//Print at coords (x, y)
void EnemyExample::print(double x, double y)
{
	if (_timer + _speed < clock())
	{
		_timer = clock();
		setCursorPosition(x, y);
		_i++;
		std::cout << _i;
	}
}

//Create an enemy with speed (update rate)
EnemyExample::EnemyExample(double speed)
	: _speed { speed }
{
}

