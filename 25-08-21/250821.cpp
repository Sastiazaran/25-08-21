#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{

	string path1 = samples::findFile("pato.jpg");
	string path2 = samples::findFile("tigre.png");

	Mat image1 = imread(path1, IMREAD_GRAYSCALE);
	Mat image2 = imread(path2, IMREAD_GRAYSCALE);

	float srows;
	float scols;
	int color = 80;

	//juntar imagenes

	if(image1.rows <= image2.rows)
	{
		srows = image1.rows;
	}
	else {
		srows = image2.rows;
	}

	if (image1.cols <= image2.cols)
	{
		scols = image1.cols;
	}
	else {
		scols = image2.cols;
	}

	Mat newImage(srows, scols, CV_8U);

	for (int i = 0; i < scols; i++)
	{
		for (int j = 0; j < srows; j++)
		{
			newImage.at<uchar>(j, i) = ((image1.at <uchar>(j, i) + image2.at<uchar>(j, i)) / 2);
		}
	}

	imshow("1", image1);
	imshow("2", image2);
	//imshow("3", newImage);

	//aclarar imagen

	for (int i = 0; i < image1.rows; i++)
	{
		for (int j = 0; j < image1.cols; j++)
		{
			if ((image1.at<uchar>(i, j) + color) > 255) {
				image1.at<uchar>(i, j) = 255;
			}
			else {
				image1.at<uchar>(i, j) = (uchar)((image1.at<uchar>(i, j)) + color);
			}
		}
	}

	//imshow("aclaramiento", image1);

	//recorrido

	Mat newImage1(srows, scols, CV_8U);

	float w1 = 0;
	float w2 = 1;

	for (int i = 0; i < srows; i++) 
	{
		w1 = w1 + (1 / srows);
		w2 = w2 - (1 / srows);

		for (int j = 0; j < scols; j++) 
		{
			
			newImage1.at<uchar>(i, j) = (w1 * image1.at<uchar>(i,j) + w2 * image2.at<uchar>(i,j));

		}
	}

	Mat newImage2(srows, scols, CV_8U);

	float w11 = 0;
	float w22 = 1;

	for (int i = 0; i < scols; i++)
	{
		w11 = w11 + (1 / srows);
		w22 = w22 - (1 / srows);

		for (int j = 0; j < srows; j++)
		{

			newImage2.at<uchar>(j, i) = (w11 * image1.at<uchar>(j,i) + w22 * image2.at<uchar>(j,i));

		}
	}

	imshow("5", newImage1);
	imshow("6", newImage2);

	waitKey(0);

}

