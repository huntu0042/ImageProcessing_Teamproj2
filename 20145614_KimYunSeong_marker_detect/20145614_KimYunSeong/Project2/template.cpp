

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

	while (game_run == 1)
	{
		check_motion();
		output_keystream();
	}

	return 0;

}