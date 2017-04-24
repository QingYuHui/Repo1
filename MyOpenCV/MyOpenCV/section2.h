#pragma once

void LoadAndDisplay()
{
	char* imageName = ".\\source\\pic1.jpg";

	Mat image;
	image = imread(imageName, CV_LOAD_IMAGE_COLOR);

	if (!image.data)
	{
		printf(" No image data \n ");
		return;
	}

	Mat gray_image;
	cvtColor(image, gray_image, CV_BGR2GRAY);


	bool bRetVal = imwrite(".\\source\\Gray_Image.jpg", gray_image);

	namedWindow(imageName, CV_WINDOW_AUTOSIZE);
	namedWindow("Gray image", CV_WINDOW_AUTOSIZE);

	imshow(imageName, image);
	imshow("Gray image", gray_image);
}

Mat& ScanImageAndReduceC(Mat& I, const uchar* const table)
{
	CV_Assert(I.depth() != sizeof(uchar));
#if 1
	// Look up table
	Mat LookUpTable(1, 256, CV_8U);
	uchar * p = LookUpTable.data;
	for (int i = 0; i < 256; ++i)
		p[i] = table[i];

	LUT(I, LookUpTable, I);

#endif

#if 0
	// The iterator method
	const int channels = I.channels();

	if (1 == channels)
	{
		MatIterator_<uchar> it, end;
		for (it = I.begin<uchar>(), end = I.end<uchar>(); it != end; ++it)
			*it = table[*it];
	}
	else if (3 == channels)
	{
		MatIterator_<Vec3b> it, end;
		for (it = I.begin<Vec3b>(), end = I.end<Vec3b>(); it != end; ++it)
		{
			(*it)[0] = table[(*it)[0]];
			(*it)[1] = table[(*it)[1]];
			(*it)[2] = table[(*it)[2]];
		}
	}

#endif

#if 0
	// Efficient method
	int channels = I.channels();

	int nRows = I.rows * channels;
	int nCols = I.cols;

	if (I.isContinuous())
	{
		nCols *= nRows;
		nRows = 1;
	}

	int i, j;
	uchar* p;
	for (i = 0; i < nRows; ++i)
	{
		p = I.ptr<uchar>(i);
		for (j = 0; j < nCols; ++j)
		{
			p[j] = table[p[j]];
		}
	}
#endif
	return I;
}

void cvReadPic()
{
	char* imageName = ".\\source\\pic1.bmp";
	IplImage* img = cvLoadImage(imageName);
	cvNamedWindow(imageName, CV_WINDOW_AUTOSIZE);
	cvShowImage(imageName, img);

	cvWaitKey(0);

	cvReleaseImage(&img);
	cvDestroyWindow(imageName);
}

int	g_slider_positiion = 0;
CvCapture* g_capture = nullptr;

void OnTrackbarSlide(int pos)
{
	cvSetCaptureProperty(g_capture, CV_CAP_PROP_POS_FRAMES, pos);
}

void cvReadFrame()
{
	char* fileName = ".\\source\\Matching.mp4";
	g_capture = cvCreateFileCapture(fileName);
	cvNamedWindow(fileName, CV_WINDOW_AUTOSIZE);

	int frames = (int)cvGetCaptureProperty(g_capture, CV_CAP_PROP_FRAME_COUNT);

	if (frames != 0)
	{
		cvCreateTrackbar("Position", fileName, &g_slider_positiion, frames, OnTrackbarSlide);
	}

	IplImage* frame;

	while (1)
	{
		frame = cvQueryFrame(g_capture);
		if (!frame)
			break;
		cvShowImage(fileName, frame);

		char c = cvWaitKey(30);
		if (c == 27)
			break;

		int CurrentPos = cvGetCaptureProperty(g_capture, CV_CAP_PROP_POS_FRAMES);
		setTrackbarPos("Position", fileName, CurrentPos);

	}

	cvReleaseCapture(&g_capture);
	cvDestroyWindow(fileName);
}

void example2_4(IplImage* image)
{
	const char* windowIn = "Example - in";
	const char* windowOut = "Example - out";
	cvNamedWindow(windowIn);
	cvNamedWindow(windowOut);

	cvShowImage(windowIn, image);

	IplImage* out = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U, 3);

	cvSmooth(image, out, CV_GAUSSIAN, 7, 7);

	cvShowImage(windowOut, out);

	cvReleaseImage(&out);

	cvWaitKey(0);

	cvDestroyWindow(windowIn);
	cvDestroyWindow(windowOut);
}

IplImage* doPyrDown(IplImage* in)
{
	assert(in->width % 2 == 0 && in->height % 2 == 0);

	IplImage* out = cvCreateImage(cvSize(in->width / 2, in->height / 2), in->depth, in->nChannels);
	cvPyrDown(in, out);
	return(out);
}

IplImage* doCanny(IplImage* in, double lowThresh, double highThresh, double aperture)
{
	// canny only handles gray scale images
	if (in->nChannels != 1)
		return 0;

	IplImage* out = cvCreateImage(cvSize(in->width, in->height), IPL_DEPTH_8U, 1);

	cvCanny(in, out, lowThresh, highThresh, aperture);

	return out;
}

void base()
{
	char* imageName = ".\\source\\pic1.bmp";
	IplImage* img = cvLoadImage(imageName, CV_LOAD_IMAGE_GRAYSCALE);

	IplImage* out = doPyrDown(img);

	IplImage* out2 = doCanny(out, 10, 100, 3);

	cvNamedWindow("Example In");
	cvShowImage("Example In", out2);

	cvReleaseImage(&img);
	cvReleaseImage(&out);
	cvDestroyWindow(imageName);
}
int video()
{
	char* fileName = ".\\source\\Matching.mp4";
	char* outputName = ".\\source\\Out.avi";

	CvCapture* capture = 0;
	capture = cvCreateFileCapture(fileName);
	if (!capture)
		return -1;
	IplImage *bgr_frame = cvQueryFrame(capture);

	double fps = cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);
	CvSize size = cvSize((int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH), (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT));

	CvVideoWriter *writer = cvCreateVideoWriter(outputName, CV_FOURCC('M', 'J', 'P', 'G'), fps, size);

	IplImage* logpolar_frame = cvCreateImage(size, IPL_DEPTH_8U, 3);

	while ((bgr_frame = cvQueryFrame(capture)) != nullptr)
	{
		cvLogPolar(bgr_frame, logpolar_frame, cvPoint2D32f(bgr_frame->width / 2, bgr_frame->height / 2), 40, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS);
		cvWriteFrame(writer, logpolar_frame);
	}

	cvReleaseVideoWriter(&writer);
	cvReleaseImage(&logpolar_frame);
	cvReleaseCapture(&capture);

	waitKey(0);

	return 0;
}