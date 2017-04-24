// Video Image PSNR and SSIM
#include <iostream> // for standard I/O
#include <string>   // for strings
#include <iomanip>  // for controlling float print precision
#include <sstream>  // string to number conversion

#include <opencv2/imgproc/imgproc.hpp>  // Gaussian Blur
#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O

using namespace std;
using namespace cv;

int main()
{
	; float vals[] = { 0.866025,-0.500000,0.500000,0.866025,0.866025,-0.500000,0.500000,0.866025 };

	CvMat romat;

	cvInitMatHeader(&romat, 4, 4, CV_32FC1, vals);

	CvMat* mat = cvCreateMat(5, 5, CV_32FC1);

	float element_1_2 = CV_MAT_ELEM(romat, float, 1, 2);
	// *((float*)CV_MAT_ELEM_PTR(*mat, 1, 2)) = 7.7;

	return 0;
}