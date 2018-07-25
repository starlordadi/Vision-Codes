#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char const *argv[])
{
	double alpha = 0.5; double beta; double input;
	Mat src1, src2, dst;

	cout << "Simple linear blender" << endl;
	cout << "---------------------" << endl;
	cout << "* Enter alpha [0-1]: ";
	cin >> input;
	//cout << "value of alpha entered" << endl;
	if (input>0 && input<1)
	{
		alpha = input;
		//cout << "alpha recieved" << endl;
	}
	src1 = imread("lena_color_256.tif",IMREAD_COLOR);
	src2 = imread("peppers_color.tif",IMREAD_COLOR);
	//cout << "echo" << endl;  
	if (src1.empty())
	{
		cout << "error loading src1" << endl; return -1;
	}
	if (src2.empty())
	{
		cout << "error loading src2" << endl; return -1;
	}
	beta = (1-alpha);
	//cout << "beta recieved" << endl;
	imshow("src1", src1);
	waitKey(1000);
	imshow("src2", src2);
	waitKey(1000);
	addWeighted(src1,alpha,src2,beta,0.0,dst);//need sources with the same number of channels and same size
	namedWindow("linear blend",WINDOW_AUTOSIZE);
	imshow("linear blend", dst);
	waitKey(0);
	return 0;
}