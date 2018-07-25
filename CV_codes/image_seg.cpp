#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char const *argv[])
{
	int s1,s2,s3,s4,s5,i,j;
	String img_name("lena_color_256.tif");
	Mat img;
	img = imread(img_name,IMREAD_COLOR);
	const char* windowname = "window";
	namedWindow(windowname,WINDOW_AUTOSIZE);
	Mat img1,img2,img3,img4,img5;
	Mat imgs1(int(img.rows/15.0),img.cols,CV_8UC3,Scalar(255,255,255));
	Mat imgs2(int((2*img.rows)/15.0),img.cols,CV_8UC3,Scalar(255,255,255));
	Mat imgs3(int(img.rows/5.0),img.cols,CV_8UC3,Scalar(255,255,255));
	Mat imgs4(int((4*img.rows)/15.0),img.cols,CV_8UC3,Scalar(255,255,255));
	Mat imgs5(int(img.rows/3.0),img.cols,CV_8UC3,Scalar(255,255,255));
	s1 = int(img.rows/15);
	s2 = int((2 * img.rows)/15);
	s3 = int(img.rows/5);
	s4 = int((4 * img.rows)/15);
	s5 = int(img.rows/3);

	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			if(i<s1)
			{
				imgs1.at<Vec3b>(i,j)[0]=img.at<Vec3b>(i,j)[0];
				imgs1.at<Vec3b>(i,j)[1]=img.at<Vec3b>(i,j)[1];
				imgs1.at<Vec3b>(i,j)[2]=img.at<Vec3b>(i,j)[2];
			}
			if(i>=s1 && i<(s1+s2))
			{
				imgs2.at<Vec3b>((i-s1),j)=img.at<Vec3b>(i,j);
			}
			if(i>=(s1+s2) && i<(s1+s2+s3))
			{
				imgs3.at<Vec3b>((i-(s1+s2)),j)=img.at<Vec3b>(i,j);
			}
			if(i>=(s1+s2+s3) && i<(s1+s2+s3+s4))
			{
				imgs4.at<Vec3b>((i-(s1+s2+s3)),j)=img.at<Vec3b>(i,j);
			}
			if(i>=(s1+s2+s3+s4) && i<(s1+s2+s3+s4+s5))
			{
				imgs5.at<Vec3b>((i-(s1+s2+s3+s4)),j)=img.at<Vec3b>(i,j);
			}
		}
	}
	imshow(windowname,imgs1);
	waitKey(0);
	imshow(windowname,imgs2);
	waitKey(0);
	imshow(windowname,imgs3);
	waitKey(0);
	imshow(windowname,imgs4);
	waitKey(0);
	imshow(windowname,imgs5);
	waitKey(0);
	return 0;
}