#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

int threshold_type = 3;
int threshold_value = 0;
int const max_type = 4;
int const max_BINARY_value = 255;
int const max_value = 255;

Mat src, src_gray, dst;
const char* window_name = "threshold demo";
// const char* trackbar_type = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
// const char* trackbar_value = "Value";


void threshold_demo(int,void*);

int main(int argc, char const *argv[])
{
	String imageName("lena_color_256.tif");
	src = imread(imageName,IMREAD_COLOR);
	cvtColor(src,src_gray,COLOR_BGR2GRAY);
	namedWindow(window_name,WINDOW_AUTOSIZE);

	// createTrackbar(trackbar_type,window_name,&threshold_type,max_type,threshold_demo);

	// createTrackbar(trackbar_value,window_name,&threshold_value,max_value,threshold_demo);

	threshold_demo(0,0);

	// for(;;)
	// {
	// 	char c = (char)waitKey(20);
	// 	if(c == 27)
	// 		break;
	// }
	return 0;
}

void threshold_demo( int, void*)
{
	int i = 0;
	for (i=0; i<255; i++)
	{
		threshold_value = i;
		threshold(src_gray,dst,threshold_value, max_BINARY_value,threshold_type);
		imshow (window_name,dst);
		waitKey(50);
	}
	// threshold(src_gray,dst,threshold_value, max_BINARY_value,threshold_type);
	// imshow (window_name,dst);
	// waitKey(0);
}
