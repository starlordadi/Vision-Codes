#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

int main(int argc, char const *argv[])
{
	Mat src,src_gray,dst;
	int kernel_size = 3;
	int ddepth = -1;
	int scale = 1;
	int delta = 0;
	const char* windowname = "laplacian demo";
	String imagename("lena_color_256.tif");
	src = imread(imagename,IMREAD_COLOR);
	GaussianBlur(src,src,Size(3,3),0,0,BORDER_DEFAULT);
	cvtColor(src,src_gray,COLOR_BGR2GRAY);
	Laplacian(src_gray,dst,ddepth,kernel_size,scale,delta,BORDER_DEFAULT);
	Mat Abs_dst;
	convertScaleAbs(dst,Abs_dst);
	imshow(windowname,Abs_dst);
	waitKey(0);

	return 0;
}