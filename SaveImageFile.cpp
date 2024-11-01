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

    // Resize the image to 500x500
    Mat resizedImage;
    resize(image, resizedImage, Size(500, 500));

    // Save the resized image to a file
    bool isSuccess = imwrite("C://Users//User//Desktop//myphotosavedImage.jpg", resizedImage);
    if (isSuccess == false)
    {
        cout << "Failed to save the image" << endl;
        cin.get(); // wait for a key press
        return -1;
    }

    cout << "Image is successfully saved to a file" << endl;

    // Display the resized image in a window
    String windowName = "The Saved Image"; // Name of the window
    namedWindow(windowName); // Create a window
    imshow(windowName, resizedImage); // Show the resized image inside the created window.

    waitKey(0); // Wait for any keystroke in the window

    destroyWindow(windowName); // Destroy the created window

    return 0;
}
