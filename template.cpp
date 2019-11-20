

#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int* find_gameboard();
int* check_motion();
int* output_keystream();

int main()
{	
	int game_run = 1;

	find_gameboard();
	// 시작하면 게임 보드를 탐지한 이후에 진행

	while (game_run == 1)
	{
		check_motion();
		output_keystream();
	}

	return 0;

}