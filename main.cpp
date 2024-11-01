#include <opencv2/opencv.hpp>

int main() {
    // Load the image using the provided path
    cv::Mat image = cv::imread("C://Users//User//Desktop//myphoto.jpg");

    // Check if the image is loaded successfully
    if (image.empty()) {
        std::cout << "Could not open or find the image!" << std::endl;
        return -1;
    }

    // Resize the image to a specific size
    cv::Mat resizedImage;
    cv::resize(image, resizedImage, cv::Size(300, 300)); // Resize to 300x300

    // Convert the image to grayscale
    cv::Mat grayImage;
    cv::cvtColor(resizedImage, grayImage, cv::COLOR_BGR2GRAY);

    // Apply GaussianBlur to reduce noise
    cv::Mat blurredImage;
    cv::GaussianBlur(grayImage, blurredImage, cv::Size(3, 3), 1.2); // Slight blur

    // Apply Canny Edge Detector
    cv::Mat edges;
    cv::Canny(blurredImage, edges, 50, 150);  // Lower thresholds to detect more edges

    // Find contours
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(edges, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

    // Draw contours on a copy of the original resized image
    cv::Mat imageWithContours = resizedImage.clone();
    cv::drawContours(imageWithContours, contours, -1, cv::Scalar(0, 255, 0), 2); // Draw all contours with green color

    // Display the original resized image
    cv::imshow("Original Image", resizedImage);

    // Display the edges detected
    cv::imshow("Edges Detected", edges);

    // Display the image with contours drawn
    cv::imshow("Contours Detected", imageWithContours);

    // Wait for a keystroke in the window
    cv::waitKey(0);

    return 0;
}
