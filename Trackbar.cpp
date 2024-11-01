#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

Mat src;

void MyCallbackForBrightness(int iValueForBrightness, void* userData)
{
    Mat dst;
    int iValueForContrast = *(static_cast<int*>(userData));

    // Calculating brightness and contrast value
    int iBrightness = iValueForBrightness - 50;
    double dContrast = iValueForContrast / 50.0;

    // Calculated contrast and brightness value
    cout << "MyCallbackForBrightness : Contrast=" << dContrast << ", Brightness=" << iBrightness << endl;

    // Adjust the brightness and contrast
    src.convertTo(dst, -1, dContrast, iBrightness);

    // Resize the image to 500x500 pixels
    Mat resizedDst;
    resize(dst, resizedDst, Size(500, 500));

    // Show the brightness and contrast adjusted image
    imshow("My Window", resizedDst);
}

void MyCallbackForContrast(int iValueForContrast, void* userData)
{
    Mat dst;
    int iValueForBrightness = *(static_cast<int*>(userData));

    // Calculating brightness and contrast value
    int iBrightness = iValueForBrightness - 50;
    double dContrast = iValueForContrast / 50.0;

    // Calculated contrast and brightness value
    cout << "MyCallbackForContrast : Contrast=" << dContrast << ", Brightness=" << iBrightness << endl;

    // Adjust the brightness and contrast
    src.convertTo(dst, -1, dContrast, iBrightness);

    // Resize the image to 500x500 pixels
    Mat resizedDst;
    resize(dst, resizedDst, Size(500, 500));

    // Show the brightness and contrast adjusted image
    imshow("My Window", resizedDst);
}

int main(int argc, char** argv)
{
    // Read original image 
    src = imread("C://Users//User//Desktop//myphoto.jpg");

    // If fail to read the image
    if (src.data == nullptr) // Check if the image was loaded successfully
    {
        cout << "Error loading the image" << endl;
        return -1;
    }

    // Create a window
    namedWindow("My Window", 1);

    int iValueForBrightness = 50;
    int iValueForContrast = 50;

    // Create track bar to change brightness
    createTrackbar("Brightness", "My Window", &iValueForBrightness, 100, MyCallbackForBrightness, &iValueForContrast);

    // Create track bar to change contrast
    createTrackbar("Contrast", "My Window", &iValueForContrast, 100, MyCallbackForContrast, &iValueForBrightness);

    // Initial display of the original image resized to 500x500 pixels
    Mat initialResized;
    resize(src, initialResized, Size(500, 500));
    imshow("My Window", initialResized);

    // Wait until user presses some key
    waitKey(0);

    return 0;
}
