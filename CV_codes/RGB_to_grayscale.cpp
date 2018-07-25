#include <opencv2/opencv.hpp>

using namespace cv;
int main(int argc, char  **argv)
{
	/* code */
	char* imageName = argv[1];

	Mat image;
	image = imread(imageName, IMREAD_COLOR);
	if(argc!=2 || !image.data)
	{
		printf("No image data \n");
		return -1;
	}

	Mat gray_image;
	cvtColor(image, gray_image, COLOR_BGR2GRAY);
	imwrite("Gray_image.jpg", gray_image);

	namedWindow(imageName,WINDOW_AUTOSIZE);
	namedWindow("gray image",WINDOW_AUTOSIZE);

	imshow(imageName,image);
	imshow("gray image",gray_image);

	waitKey(0);
	return 0;
}
