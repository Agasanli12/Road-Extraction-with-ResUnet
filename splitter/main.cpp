#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const std::string path = "/home/aqil/Desktop/Proj/AI/U-Net-Satellite/maps/train/";
const std::string new_path = "/homw/aqil/Desktop/Proj/AI/U-Net-Satellite/maps_new/train/";

const int img_count = 1096;

cv::Mat get_left_part(cv::Mat original);
cv::Mat get_right_part(cv::Mat original);

int main(int argc, char **argv)
{
    auto images = std::vector<cv::Mat>();

    for (int i = 0; i < img_count; i++)
    {
        auto image = cv::imread(path + std::to_string(i + 1) + ".jpg", cv::COLOR_RGB2BGR);
        cv::imwrite(new_path + "satellite/" + std::to_string(i + 1) + ".jpg", get_left_part(image));
        cv::imwrite(new_path + "computer/" + std::to_string(i + 1) + ".jpg", get_right_part(image));
        std::cout << "Written image: " << i + 1 << "\r";
    }
}

cv::Mat get_left_part(cv::Mat original)
{
    int half_size = original.size[1] / 2;

    cv::Mat splitted(cv::Size(original.size[0], half_size), CV_8UC3);
    cv::Mat splitted_right(cv::Size(original.size[0], half_size), CV_8UC3);

    for (int i = 0; i < original.size[0]; i++)
        for (int j = 0; j < half_size; j++)
            splitted.at<cv::Vec3b>(i, j) = original.at<cv::Vec3b>(i, j);

    return splitted;
}

cv::Mat get_right_part(cv::Mat original)
{
    int half_size = original.size[1] / 2;

    cv::Mat splitted(cv::Size(original.size[0], half_size), CV_8UC3);

    for (int i = 0; i < original.size[0]; i++)
        for (int j = half_size; j < original.size[1]; j++)
            splitted.at<cv::Vec3b>(i, j - half_size) = original.at<cv::Vec3b>(i, j);

    return splitted;
}