#include <opencv2/imgcodecs.hpp>
#include "src/objectextractor.h"
#include "testextractor.h"


test::test_extractor::test_extractor()
{
}

test::test_extractor::~test_extractor()
{
}


void
test::test_extractor::run() const
{
        cv::Mat I0 = cv::imread("res/fgbg/calib_fg.jpg", cv::IMREAD_COLOR);
        cv::Mat I1 = cv::imread("res/fgbg/calib_bg.jpg", cv::IMREAD_COLOR);

        cv::Mat3f fg(I0.size());
        cv::Mat3f bg(I1.size());
        I0.convertTo(fg, CV_32FC3, 1/255.0f);
        I1.convertTo(bg, CV_32FC3, 1/255.0f);

        e8::fgbg_object_extractor extractor(bg, 1, 0.1f, 0.1f);
        cv::Mat1b const& mask = extractor.compute_mask(fg);

        cv::imwrite("mask.png", mask);
}