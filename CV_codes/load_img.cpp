#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main(int argc, char const *argv[])
{
	String imageName ("lena_color_256.tif");
	if (argc > 1)
	{
		imageName = argv[1];
	}
	Mat image;
	image = imread (imageName, IMREAD_COLOR);

	if(image.empty())
	{
		cout << "Could not open or find the image"<< std::endl;
		return -1;
	}

	namedWindow("display window", WINDOW_AUTOSIZE);
	imshow("display window", image);
	waitKey(0);
	return 0;
}