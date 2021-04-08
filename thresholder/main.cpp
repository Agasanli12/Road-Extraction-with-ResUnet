#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const std::string path = "/home/aqil/Desktop/Proj/AI/U-Net-Satellite/maps_new/train/computer/";
const std::string out_path = "/home/aqil/Desktop/Proj/AI/U-Net-Satellite/maps_new/train/computer_thresholded/";

const int img_count = 1096;

void threshold(cv::Mat &image, uint8_t threshold)
{
    int height = image.size[0];
    int width = image.size[1];
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            if (image.at<cv::uint8_t>(i, j) > threshold)
            {
                image.at<cv::uint8_t>(i, j) = 255;
            }
            else
            {
                image.at<cv::uint8_t>(i, j) = 0;
            }
        }
}

int main(int argc, char **argv)
{
    uint8_t T;

    if (argc > 1)
        T = (uint8_t)std::atoi(argv[1]);
    else
        T = 250;

    for (int i = 0; i < img_count; i++)
    {
        auto image = cv::imread(path + std::to_string(i + 1) + ".jpg", cv::IMREAD_GRAYSCALE);
        threshold(image, T);

        cv::imwrite(out_path + std::to_string(i + 1) + ".png", image);

        std::cout << "Written image: " << i + 1 << "\r";
    }

    // cv::imshow("window", image);
    // cv::waitKey(0);
}
