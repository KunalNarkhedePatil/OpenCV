#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
    // Open the video file for reading
    VideoCapture cap("C://Users//User//Desktop//Earth.mp4");

    // If not success, exit program
    if (cap.isOpened() == false)
    {
        cout << "Cannot open the video file" << endl;
        cin.get(); // wait for any key press
        return -1;
    }

    // Uncomment the following line if you want to start the video in the middle
    // cap.set(CAP_PROP_POS_MSEC, 300); 

    // Get the frames per second of the video
    double fps = cap.get(CAP_PROP_FPS);
    cout << "Frames per second : " << fps << endl;

    String window_name = "Earth Video";

    namedWindow(window_name, WINDOW_NORMAL); // Create a window

    while (true)
    {
        Mat frame;
        bool bSuccess = cap.read(frame); // Read a new frame from video 

        // Breaking the while loop at the end of the video
        if (bSuccess == false)
        {
            cout << "Found the end of the video" << endl;
            break;
        }

        // Resize the frame to 500x500
        Mat resizedFrame;
        resize(frame, resizedFrame, Size(500, 500));

        // Show the resized frame in the created window
        imshow(window_name, resizedFrame);

        // Wait for 10 ms until any key is pressed.  
        // If the 'Esc' key is pressed, break the while loop.
        if (waitKey(10) == 27)
        {
            cout << "Esc key is pressed by user. Stopping the video" << endl;
            break;
        }
    }

    return 0;
}
