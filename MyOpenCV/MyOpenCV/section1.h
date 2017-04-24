#pragma once


void SharpenCore(const Mat& myImage, Mat& Result)
{
	CV_Assert(myImage.depth() == CV_8U);
#if 1
	Mat Kern = (Mat_<char>(3, 3) << 0, -1, 0,
		-1, 5, -1,
		0, -1, 0);
	filter2D(myImage, Result, myImage.depth(), Kern);
#endif

#if 0
	Result.create(myImage.size(), myImage.type());
	const int nChannels = myImage.channels();

	for (int j = 1; j < myImage.rows - 1; ++j)	// not include the first row and the last row
	{
		const uchar* previous = myImage.ptr<uchar>(j - 1);
		const uchar* current = myImage.ptr<uchar>(j);
		const uchar* next = myImage.ptr<uchar>(j + 1);

		uchar* output = Result.ptr<uchar>(j);

		for (int i = nChannels; i < nChannels*(myImage.cols - 1); ++i)	// not include the first column and the last cloumn
		{
			*output++ = saturate_cast<uchar>(5 * current[i] - current[i - nChannels] - current[i + nChannels] - previous[i] - next[i]);
		}
	}

	Result.row(0).setTo(Scalar(0));
	Result.row(Result.rows - 1).setTo(Scalar(0));
	Result.col(0).setTo(Scalar(0));
	Result.col(Result.cols - 1).setTo(Scalar(0));
#endif
}

void ScanWeighted()
{
	double alpha = 0.5;
	double beta;

	Mat src1, src2, dst;
	src1 = imread(".\\source\\pic1.bmp");
	src2 = imread(".\\source\\pic2.bmp");

	if (!src1.data)
		return;
	if (!src2.data)
		return;

	namedWindow("Linear Blend", CV_WINDOW_AUTOSIZE);

	beta = 1.0 - alpha;
	// dst = alpha * src1 + beta * src2 + gamma
	addWeighted(src1, alpha, src2, beta, 1.0, dst);

	imshow("Linear Blend", dst);

}

void Contrast(const Mat& myImage, Mat& Result)
{
	double alpha = 1.3;		// contrast
	int beta = 1;			// brightness

	Result.create(myImage.size(), myImage.type());

#if 1
	myImage.convertTo(Result, -1, alpha, beta);
#endif

#if 0
	for (int y = 0; y < myImage.rows; ++y)
	{
		for (int x = 0; x < myImage.cols; ++x)
		{
			for (int c = 0; c < 3; ++c)
			{
				Result.at<Vec3b>(y, x)[c] = saturate_cast<uchar> (alpha * (myImage.at<Vec3b>(y, x)[c]) + beta);
			}
		}
	}
#endif
}

void Scan()
{
	char* imageName = ".\\source\\pic1.bmp";

	Mat image;
	image = imread(imageName, CV_LOAD_IMAGE_COLOR);

	if (!image.data)
	{
		printf(" No image data \n ");
		return;
	}

	namedWindow(imageName, CV_WINDOW_AUTOSIZE);
	imshow(imageName, image);

	Mat Image2(image);
	int divideWidth = 10;
	uchar table[256];
	for (int i = 0; i < 256; ++i)
	{
		table[i] = divideWidth * (i / divideWidth);
	}

	// end load
	Mat Des;

	Contrast(image, Des);

	namedWindow("New Window", CV_WINDOW_AUTOSIZE);
	imshow("New Window", Des);
}
void MyEllipse(int w, Mat img, double angle)
{
	int thickness = 2;
	int lineType = 8;
	ellipse(img,
		Point(w / 2.0, w / 2.0),
		Size(w / 4.0, w / 16.0),
		angle,
		0,
		360,
		Scalar(255, 0, 0),
		thickness,
		lineType);
}
void MyFilledCircle(int w, Mat img, Point center)
{
	int thickness = -1;
	int lineType = 8;

	circle(img,
		center,
		w / 32.0,
		Scalar(0, 0, 255),
		thickness,
		lineType);
}
void MyPolygon(int w, Mat img)
{
	int lineType = 8;

	// create some points
	Point rook_points[1][20];
	rook_points[0][0] = Point(w / 4.0, 7 * w / 8.0);
	rook_points[0][1] = Point(3 * w / 4.0, 7 * w / 8.0);
	rook_points[0][2] = Point(3 * w / 4.0, 13 * w / 16.0);
	rook_points[0][3] = Point(11 * w / 16.0, 13 * w / 16.0);
	rook_points[0][4] = Point(19 * w / 32.0, 3 * w / 8.0);
	rook_points[0][5] = Point(3 * w / 4.0, 3 * w / 8.0);
	rook_points[0][6] = Point(3 * w / 4.0, w / 8.0);
	rook_points[0][7] = Point(26 * w / 40.0, w / 8.0);
	rook_points[0][8] = Point(26 * w / 40.0, w / 4.0);
	rook_points[0][9] = Point(22 * w / 40.0, w / 4.0);
	rook_points[0][10] = Point(22 * w / 40.0, w / 8.0);
	rook_points[0][11] = Point(18 * w / 40.0, w / 8.0);
	rook_points[0][12] = Point(18 * w / 40.0, w / 4.0);
	rook_points[0][13] = Point(14 * w / 40.0, w / 4.0);
	rook_points[0][14] = Point(14 * w / 40.0, w / 8.0);
	rook_points[0][15] = Point(w / 4.0, w / 8.0);
	rook_points[0][16] = Point(w / 4.0, 3 * w / 8.0);
	rook_points[0][17] = Point(13 * w / 32.0, 3 * w / 8.0);
	rook_points[0][18] = Point(5 * w / 16.0, 13 * w / 16.0);
	rook_points[0][19] = Point(w / 4.0, 13 * w / 16.0);

	const Point * ppt[1] = { rook_points[0] };
	int npt[] = { 20 };

	fillPoly(img,
		ppt,
		npt,
		1,
		Scalar(255, 255, 255),
		lineType);
}
void MyLine(Mat img, Point start, Point end)
{
	int thickness = 2;
	int lineType = 8;
	line(img,
		start,
		end,
		Scalar(0, 0, 0),
		thickness,
		lineType);
}
void ScanScalar()
{
	int	w = 400;
	char atom_window[] = "Drawing 1: Atom";
	char rook_window[] = "Drawing 2: Rook";

	Mat atom_image = Mat::zeros(w, w, CV_8UC3);
	Mat rook_image = Mat::zeros(w, w, CV_8UC3);

	// draw ellipse
	MyEllipse(w, atom_image, 90);
	MyEllipse(w, atom_image, 0);
	MyEllipse(w, atom_image, 45);
	MyEllipse(w, atom_image, -45);

	// draw circle
	MyFilledCircle(w, atom_image, Point(w / 2.0, w / 2.0));

	// draw polygon
	MyPolygon(w, rook_image);
	// draw rectangle
	rectangle(rook_image,
		Point(0, 7 * w / 8.0),
		Point(w, w),
		Scalar(0, 255, 255),
		-1,
		8);

	MyLine(rook_image, Point(0, 15 * w / 16), Point(w, 15 * w / 16));
	MyLine(rook_image, Point(w / 4, 7 * w / 8), Point(w / 4, w));
	MyLine(rook_image, Point(w / 2, 7 * w / 8), Point(w / 2, w));
	MyLine(rook_image, Point(3 * w / 4, 7 * w / 8), Point(3 * w / 4, w));

	// display
	namedWindow(atom_window, CV_WINDOW_AUTOSIZE);
	imshow(atom_window, atom_image);
	namedWindow(rook_window, CV_WINDOW_AUTOSIZE);
	imshow(rook_window, rook_image);

}
int NUMBER = 10;
int DELAY = 20;
double x_1 = 0.0;
double x_2 = 800.0;
double y_1 = 0.0;
double y_2 = 600.0;

Scalar randomColor(RNG& rng)
{
	int icolor = (unsigned)rng;
	return Scalar(icolor & 255, (icolor >> 8), (icolor >> 16) & 255);

}
int drawing_random_lines(Mat image, char* window_name, RNG rng)
{
	int lineType = 8;
	Point pt1, pt2;

	for (int i = 0; i < NUMBER; i++)
	{
		pt1.x = rng.uniform(x_1, x_2);
		pt1.y = rng.uniform(y_1, y_2);
		pt2.x = rng.uniform(x_1, x_2);
		pt2.y = rng.uniform(y_1, y_2);

		line(image, pt1, pt2, randomColor(rng), rng.uniform(1, 10), 8);
		imshow(window_name, image);
		//if (waitKey(DELAY) >= 0)
		//return -1;
	}
	return 0;
}
void random_paint()
{
	int window_height = 600;
	int window_width = 800;

	char RandomWindow[] = "Random paint";

	RNG rng(0xFFFFFFFF);

	Mat image = Mat::zeros(window_height, window_width, CV_8UC3);
	drawing_random_lines(image, RandomWindow, rng);
}
void fourier()
{
	const char* filename = ".\\source\\imageTextR.png";

	Mat I = imread(filename, CV_LOAD_IMAGE_GRAYSCALE);
	if (I.empty())
		return;

	Mat padded;
	int m = getOptimalDFTSize(I.rows);
	int n = getOptimalDFTSize(I.cols);
	copyMakeBorder(I, padded, 0, m - I.rows, 0, n - I.cols, BORDER_CONSTANT, Scalar::all(0));

	Mat planes[] = { Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F) };
	Mat complexI;
	merge(planes, 2, complexI);

	dft(complexI, complexI);

	split(complexI, planes);
	magnitude(planes[0], planes[1], planes[0]);
	Mat magI = planes[0];

	magI += Scalar::all(1);
	log(magI, magI);

	magI = magI(Rect(0, 0, magI.cols & -2, magI.rows & -2));

	int cx = magI.cols / 2;
	int cy = magI.rows / 2;

	Mat q0(magI, Rect(0, 0, cx, cy));
	Mat q1(magI, Rect(cx, 0, cx, cy));
	Mat q2(magI, Rect(0, cy, cx, cy));
	Mat q3(magI, Rect(cx, cy, cx, cy));

	Mat tmp;
	q0.copyTo(tmp);
	q3.copyTo(q0);
	tmp.copyTo(q3);

	q1.copyTo(tmp);
	q2.copyTo(q1);
	tmp.copyTo(q2);

	normalize(magI, magI, 0, 1, CV_MINMAX);

	imshow("Imput Image", I);
	imshow("spectrum magnitude", magI);

	waitKey();

	return;
}
