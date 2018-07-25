#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

Mat src, dst, tmp;

const char* window_name = "Pyramids demo";

int main(int argc, char const *argv[])
{
	printf("\n Zoom In-Out demo \n");
	printf("-----------------------");
	printf("* [u] -> Zoom in \n");
	printf("* [d] -> Zoom out\n");
	printf("* [ESC] -> Close Program \n");
	src = imread ("lena_color_256.tif");
	if(src.empty())
	{
		printf("No data!  Exiting program");
		return -1;
	}
	tmp = src;
	dst = tmp;

	imshow(window_name, dst);
	for(;;)
	{
		char c = (char)waitKey(0);

		if (c==27)
			break;
		if (c == 'u')
		{
			pyrUp(tmp,dst,Size(tmp.cols*2,tmp.rows*2));
			printf("**Zoom in: Image x 2\n");
		}
		else if(c=='d')
		{
			pyrDown(tmp,dst,Size(tmp.cols/2,tmp.rows/2));
			printf("Zoom out\n");
		}

		imshow(window_name, dst);

		tmp = dst;
	}
	return 0;
}