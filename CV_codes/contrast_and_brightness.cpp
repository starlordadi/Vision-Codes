#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char const *argv[])
{
	double alpha = 1.0;
	int beta = 0;
	string imagename("lena_color_256.tif");
	if (argc > 1)
		imagename = argv[1];
	Mat image = imread(imagename);
	Mat new_image = Mat::zeros(image.size(),image.type());
	cout << "basic linear transformation" << endl;
	cout << "---------------------------" << endl;
	cout << "enter the alpha value [1-3]" ; cin >> alpha;
	cout << "enter the beta value [0-100]"; cin >> beta;

	for (int x = 0; x < image.rows; x++)
	{
		for (int y =0 ; y< image.cols; y++)
		{
			for (int c=0; c<3; c++)
			{
				new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>(alpha*(image.at<Vec3b>(y,x)[c])+beta);

			}
		}
	}
	namedWindow("original image",WINDOW_AUTOSIZE);
	namedWindow("new image",WINDOW_AUTOSIZE);

	imshow("original image",image);
	imshow("new image", new_image);
	waitKey(0);
	return 0;
}