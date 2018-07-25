#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

Mat src,dst;
int top,bottom,left,right;
int bordertype;
const char* windowname = "padding demo";
RNG rng(12345);

int main(int argc, char const *argv[])
{
	String imagename("lena_color_256.tif");
	src = imread(imagename,IMREAD_COLOR);
	namedWindow(windowname,WINDOW_AUTOSIZE);
	top = (int)(0.05*src.rows);
	bottom = (int)(0.05*src.rows);
	left = (int)(0.05*src.cols);
	right = (int)(0.05*src.cols);
	dst = src;
	imshow(windowname,dst);
	for(;;)
	{
		char c = (char)waitKey(500);
		if(c==27)
			break;
		else if (c == 'c')
			bordertype = BORDER_CONSTANT;
		else if (c == 'r')
			bordertype = BORDER_REPLICATE;
		Scalar value(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255));
		copyMakeBorder(src,dst,top,bottom,left,right,bordertype,value);
		imshow(windowname,dst); 
	}
	return 0;
}