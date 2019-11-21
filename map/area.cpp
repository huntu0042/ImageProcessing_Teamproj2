#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <cstdlib>
#include <stack>

using namespace cv;
using namespace std;


typedef struct {
	int x;
	int y;
}point;

stack<point> s;
void labeling(Mat image, int x, int y)
{
	int width = image.size().width;
	int height = image.size().height;
	point p;
	if (x + 1 != width) {
		p.x = x + 1;
		p.y = y;
		uchar b = image.at<Vec3b>(p.y, p.x)[0];
		if (b == 255)
			s.push(p);
	}
	if (x != 0) {
		p.x = x - 1;
		p.y = y;
		uchar b = image.at<Vec3b>(p.y, p.x)[0];
		if (b == 255)
			s.push(p);
	}
	if (y != 0) {
		p.x = x;
		p.y = y - 1;
		uchar b = image.at<Vec3b>(p.y, p.x)[0];
		if (b == 255)
			s.push(p);
	}
	if (y + 1 != height) {
		p.x = x;
		p.y = y + 1;
		uchar b = image.at<Vec3b>(p.y, p.x)[0];
		if (b == 255)
			s.push(p);
	}


}
void func(Mat image, int num) {
	int height = image.size().height;
	int width = image.size().width;

	Mat image2(image.size().height, image.size().width, CV_8UC3, Scalar(0, 0, 0));
	Mat block1(image.size().height, image.size().width, CV_8UC3, Scalar(0, 0, 0));
	Mat block2(image.size().height, image.size().width, CV_8UC3, Scalar(0, 0, 0));
	Mat block3(image.size().height, image.size().width, CV_8UC3, Scalar(0, 0, 0));
	Mat block4(image.size().height, image.size().width, CV_8UC3, Scalar(0, 0, 0));
	Mat block5(image.size().height, image.size().width, CV_8UC3, Scalar(0, 0, 0));
	Mat block6(image.size().height, image.size().width, CV_8UC3, Scalar(0, 0, 0));
	Mat block7(image.size().height, image.size().width, CV_8UC3, Scalar(0, 0, 0));
	Mat block8(image.size().height, image.size().width, CV_8UC3, Scalar(0, 0, 0));
	Mat block9(image.size().height, image.size().width, CV_8UC3, Scalar(0, 0, 0));
	int x_count = 0, y_count = 0;

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {

			uchar b = image.at<Vec3b>(y, x)[0];
			uchar g = image.at<Vec3b>(y, x)[1];
			uchar r = image.at<Vec3b>(y, x)[2];
			
			if (b > 155 && r < 150 && g < 150)
			{
				image2.at<Vec3b>(y, x)[0] = 255;
			}
			
		}
	}
	//Labeling
	point temp_p;
	int index = 0;
	for (int y = 2; y < height-2; y++) {
		for (int x = 2; x < width-2; x++) {

			int num = 0;
			uchar b = image2.at<Vec3b>(y, x)[0];
			uchar b_xp = image2.at<Vec3b>(y, x+1)[0];
			uchar b_xm = image2.at<Vec3b>(y, x-1)[0];
			uchar b_yp = image2.at<Vec3b>(y+1, x)[0];
			uchar b_ym = image2.at<Vec3b>(y-1, x)[0];
			uchar b_d1 = image2.at<Vec3b>(y + 1, x + 1)[0];
			uchar b_d2 = image2.at<Vec3b>(y + 1, x - 1)[0];
			uchar b_d3 = image2.at<Vec3b>(y - 1, x - 1)[0];
			uchar b_d4 = image2.at<Vec3b>(y - 1, x + 1)[0];
			
			if (b == 255 && ((b_ym == 0 && b_yp == 0) || (b_xp == 0 && b_xm == 0)))
			{
				image2.at<Vec3b>(y, x)[0] = 0;
				b = 0;
			}

			if (b == 255)
			{
				temp_p.x = x;
				temp_p.y = y;
				s.push(temp_p);
				int count = 0;
				index++;
				while (!s.empty()){
					temp_p = s.top();
					s.pop();
					count++;
					switch (index)
					{
					case 1:
						block1.at<Vec3b>(temp_p.y, temp_p.x)[0] = 255;
						break;
					case 2:
						block2.at<Vec3b>(temp_p.y, temp_p.x)[0] = 255;
						break;
					case 3:
						block3.at<Vec3b>(temp_p.y, temp_p.x)[0] = 255;
						break;
					case 4:
						block4.at<Vec3b>(temp_p.y, temp_p.x)[0] = 255;
						break;
					case 5:
						block5.at<Vec3b>(temp_p.y, temp_p.x)[0] = 255;
						break;
					case 6:
						block6.at<Vec3b>(temp_p.y, temp_p.x)[0] = 255;
						break;
					case 7:
						block7.at<Vec3b>(temp_p.y, temp_p.x)[0] = 255;
						break;
					case 8:
						block8.at<Vec3b>(temp_p.y, temp_p.x)[0] = 255;
						break;
					case 9:
						block9.at<Vec3b>(temp_p.y, temp_p.x)[0] = 255;
						break;
					}
					image2.at<Vec3b>(temp_p.y, temp_p.x)[0] = 0;
					labeling(image2, temp_p.x, temp_p.y);
				}
				printf("\nindex %d, %d", index, count);
			}
		}
	}
	imwrite("C:\\input\\block01.jpg", block1);
	imwrite("C:\\input\\block02.jpg", block2);
	imwrite("C:\\input\\block03.jpg", block3);
	imwrite("C:\\input\\block04.jpg", block4);
	imwrite("C:\\input\\block05.jpg", block5);
	imwrite("C:\\input\\block06.jpg", block6);
	imwrite("C:\\input\\block07.jpg", block7);
	imwrite("C:\\input\\block08.jpg", block8);
	imwrite("C:\\input\\block09.jpg", block9);
	waitKey(0);

}
int main(int argc, char** argv)
{
	Mat image1 = imread("C:\\input\\test04.jpg", IMREAD_COLOR);
	func(image1, 1);
	return 0;
}