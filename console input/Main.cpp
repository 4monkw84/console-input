#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <time.h>

#include "EnemyExample.h"

//creating two enemies, one with a speed of 500ms, one with a speed of 2 seconds
EnemyExample one(500);
EnemyExample two(2000);
char playerInput = ' ';

//setting console cursor position
void setCursorPosition(short a, short b)
{
	{
		COORD pos = { a,b };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
}

//Update player based on input
void updatePlayer(char input)
{
	setCursorPosition(0, 0);
	std::cout << playerInput;
}


void gameLoop()
{
	//while the game is running
	while (true)
	{
		//check for any input, skipping getting input if none detected
		if (_kbhit())
		{
			playerInput = _getch();
			updatePlayer(playerInput);
		}
		//calling all other functions that should run outside of player input - example of updating two enemies
		one.print(10, 0);
		two.print(20, 0);
	}
}

int main()
{
	//getting console cursor info for hiding blinking cursor
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = false; // set the cursor visibility
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	//begin loop
	gameLoop();

	return 0;
}