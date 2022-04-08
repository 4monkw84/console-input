#pragma once
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <time.h>

class EnemyExample
{
	//timer to handle update rate
	clock_t _timer = clock();
	//example of enemy - example is integer just to show updates over time at fixed rate
	int _i = 0;
	//speed of enemy updates (translates to enemy movement speed when in maze)
	double _speed = 0;

	//same as function in Main.cpp - sets console cursor position
	void setCursorPosition(short a, short b);

public:
	void print(double x, double y);
	EnemyExample(double speed);

};