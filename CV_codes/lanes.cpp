#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;
Mat image_gray;
int lowThreshold = 50; 
int ratio = 3;
int kernel_size = 3; 
String imagename("lanes.png");
Mat image = imread(imagename,IMREAD_COLOR);
Mat imgs1(int(image.rows/15.0),image.cols,CV_8UC3,Scalar(255,255,255));
Mat imgs2(int((2*image.rows)/15.0),image.cols,CV_8UC3,Scalar(255,255,255));
Mat imgs3(int(image.rows/5.0),image.cols,CV_8UC3,Scalar(255,255,255));
Mat imgs4(int((4*image.rows)/15.0),image.cols,CV_8UC3,Scalar(255,255,255));
Mat imgs5(int(image.rows/3.0),image.cols,CV_8UC3,Scalar(255,255,255));
const char* windowname = "lanes";

static Mat CannyThreshold(Mat);
static void image_segment(Mat);
int main(int argc, char const *argv[])
{
	Mat detected_edges,dst,line_img;
	//String imagename("lanes.png");
    const char* windowname = "lanes";
	// image = imread(imagename,IMREAD_COLOR);
	cvtColor(image,image_gray,COLOR_BGR2GRAY);
	namedWindow(windowname,WINDOW_AUTOSIZE);
	//namedWindow("lines", WINDOW_AUTOSIZE);
	//imshow(windowname,src_gray);
	image_segment(image_gray);

	CannyThreshold(imgs5).copyTo(detected_edges);

	imshow(windowname,detected_edges);
	waitKey(0);
	vector<Vec2f> lines; 
	HoughLines(detected_edges, lines, 1, CV_PI/180, 100, 0, 0 ); // runs the actual detection
    //![hough_lines]
    //![draw_lines]
    // Draw the lines
    for( size_t i = 0; i < lines.size(); i++ )
    {
        float rho = lines[i][0], theta = lines[i][1];
        Point pt1, pt2;
        double a = cos(theta), b = sin(theta);
        double x0 = a*rho, y0 = b*rho;
        pt1.x = cvRound(x0 + 1000*(-b));
        pt1.y = cvRound(y0 + 1000*(a));
        pt2.x = cvRound(x0 - 1000*(-b));
        pt2.y = cvRound(y0 - 1000*(a));
        line( detected_edges, pt1, pt2, Scalar(255,255,255), 3, CV_AA);
        //line( line_img, pt1, pt2, Scalar(255,255,255), 3, CV_AA);

    }
    imshow(windowname,detected_edges);
    //imshow("lines",line_img);
    waitKey(0);
    
	return 0;
}

static Mat CannyThreshold(Mat src_gray)
{
    Mat detected_edges,dst;
    //![reduce_noise]
    /// Reduce noise with a kernel 3x3
    blur( src_gray, detected_edges, Size(5,5) );
    //![reduce_noise]

    //![canny]
    /// Canny detector
    Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );
    //![canny]

    /// Using Canny's output as a mask, we display our result
    //![fill]
    dst = Scalar::all(0);
    //![fill]

    //![copyto]
    image.copyTo( dst, detected_edges);
    //![copyto]

    //![display]
    // imshow( windowname, dst );
    // waitKey(0);
    return detected_edges;
    //![display]
}

static void image_segment(Mat image)
{
    int s1,s2,s3,s4,s5,i,j;
    //String img_name("lena_color_256.tif");
    //Mat img;
    //img = imread(img_name,IMREAD_COLOR);
    //const char* windowname = "window";
    //namedWindow(windowname,WINDOW_AUTOSIZE);
    //Mat img1,img2,img3,img4,img5;
    // Mat imgs1(int(image.rows/15.0),image.cols,CV_8UC3,Scalar(255,255,255));
    // Mat imgs2(int((2*image.rows)/15.0),image.cols,CV_8UC3,Scalar(255,255,255));
    // Mat imgs3(int(image.rows/5.0),image.cols,CV_8UC3,Scalar(255,255,255));
    // Mat imgs4(int((4*image.rows)/15.0),image.cols,CV_8UC3,Scalar(255,255,255));
    // Mat imgs5(int(image.rows/3.0),image.cols,CV_8UC3,Scalar(255,255,255));
    s1 = int(image.rows/15);
    s2 = int((2 * image.rows)/15);
    s3 = int(image.rows/5);
    s4 = int((4 * image.rows)/15);
    s5 = int(image.rows/3);

    for(i=0;i<image.rows;i++)
    {
        for(j=0;j<image.cols;j++)
        {
            if(i<s1)
            {
                imgs1.at<Vec3b>(i,j)[0]=image.at<Vec3b>(i,j)[0];
                imgs1.at<Vec3b>(i,j)[1]=image.at<Vec3b>(i,j)[1];
                imgs1.at<Vec3b>(i,j)[2]=image.at<Vec3b>(i,j)[2];
            }
            if(i>=s1 && i<(s1+s2))
            {
                imgs2.at<Vec3b>((i-s1),j)=image.at<Vec3b>(i,j);
            }
            if(i>=(s1+s2) && i<(s1+s2+s3))
            {
                imgs3.at<Vec3b>((i-(s1+s2)),j)=image.at<Vec3b>(i,j);
            }
            if(i>=(s1+s2+s3) && i<(s1+s2+s3+s4))
            {
                imgs4.at<Vec3b>((i-(s1+s2+s3)),j)=image.at<Vec3b>(i,j);
            }
            if(i>=(s1+s2+s3+s4) && i<(s1+s2+s3+s4+s5))
            {
                imgs5.at<Vec3b>((i-(s1+s2+s3+s4)),j)=image.at<Vec3b>(i,j);
            }
        }
    }
}