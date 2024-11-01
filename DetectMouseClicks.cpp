#include "opencv2/highgui/highgui.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
    if (flags == (EVENT_FLAG_CTRLKEY + EVENT_FLAG_LBUTTON))
    {
        cout << "Left mouse button is clicked while pressing CTRL key - position (" << x << ", " << y << ")" << endl;
    }
    else if (flags == (EVENT_FLAG_RBUTTON + EVENT_FLAG_SHIFTKEY))
    {
        cout << "Right mouse button is clicked while pressing SHIFT key - position (" << x << ", " << y << ")" << endl;
    }
    else if (event == EVENT_MOUSEMOVE && flags == EVENT_FLAG_ALTKEY)
    {
        cout << "Mouse is moved over the window while pressing ALT key - position (" << x << ", " << y << ")" << endl;
    }
}

int main(int argc, char** argv)
{
    // Read image from file 
    Mat img = imread("C://Users//User//Desktop//myphoto.jpg"); // Make sure the path is correct

    // If fail to read the image
    if (img.empty())
    {
        cout << "Error loading the image" << endl;
        return -1;
    }

    // Resize the image to 400x400 pixels
    Mat resizedImg;
    resize(img, resizedImg, Size(400, 400));

    // Create a window
    namedWindow("My Window", 1);

    // Set the callback function for any mouse event
    setMouseCallback("My Window", CallBackFunc, NULL);

    // Show the resized image
    imshow("My Window", resizedImg);

    // Wait until user presses some key
    waitKey(0);

    return 0;
}
