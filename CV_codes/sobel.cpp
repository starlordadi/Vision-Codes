#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

int main(int argc, char const *argv[])
{
	Mat src, src_gray;
	Mat grad;
	int scale = 1;
	int delta = 0;
	int ddepth = CV_16S;
	const char* windowname = "sobel demo";
	String imagename("lena_color_256.tif");
	src = imread(imagename,IMREAD_COLOR);
	GaussianBlur(src,src,Size(3,3),0,0,BORDER_DEFAULT);
	cvtColor(src,src_gray,COLOR_BGR2GRAY);
	Mat grad_x, grad_y;
	Mat Abs_grad_x, Abs_grad_y;
	// Sobel(src_gray,grad_x,ddepth,1,0,3,scale,delta,BORDER_DEFAULT);
	// Sobel(src_gray,grad_y,ddepth,0,1,3,scale,delta,BORDER_DEFAULT);
	Scharr(src_gray,grad_x,1,0,scale,delta,BORDER_DEFAULT);
	Scharr(src_gray,grad_y,0,1,scale,delta,BORDER_DEFAULT);
	convertScaleAbs(grad_x,Abs_grad_x);
	convertScaleAbs(grad_y,Abs_grad_y);

	addWeighted(Abs_grad_x,0.5,Abs_grad_y,0.5,0,grad);
	imshow(windowname,grad);
	waitKey(0);

	return 0;
}