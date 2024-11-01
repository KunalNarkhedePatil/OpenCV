#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    // Read the image file
    Mat image = imread("C://Users//User//Desktop//myphoto.jpg");

    // Check for failure
    if (image.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get(); // wait for any key press
        return -1;
    }

    // Resize the image to 600x600
    Mat resizedImage;
    resize(image, resizedImage, Size(500, 500));

    String windowName = "My Photo"; // Name of the window

    namedWindow(windowName); // Create a window

    imshow(windowName, resizedImage); // Show our resized image inside the created window.

    waitKey(0); // Wait for any keystroke in the window

    destroyWindow(windowName); // Destroy the created window

    return 0;
}
