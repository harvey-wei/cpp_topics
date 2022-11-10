#include <string>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
    string path = "lena.png";
    cv::Mat img = imread(path);

    imshow("Image", img);
    waitKey(0);

    return 0;
}
