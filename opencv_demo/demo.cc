#include <string>
#include <opencv2/opencv.hpp>

int main()
{
    std::string path = "lena.png";
    cv::Mat img = cv::imread(path);

    imshow("Image", img);
    cv::waitKey(0);

    return 0;
}
