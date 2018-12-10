//
// Created by lshi on 3/16/18.
//
#include "opencv2/cudacodec.hpp"
#include "opencv2/cudaimgproc.hpp"
#include "opencv2/opencv.hpp"
#include <thread>

using namespace std;
using namespace cv;
using namespace cv::cuda;


int main(int argc, const char *argv[]) {

    string video_path = "../test.mp4";
    clock_t s;
    clock_t e;

    Mat outimg_from_gpu, outimg_from_cpu;
    GpuMat capture_frame_gpu, resize_frame_gpu(200, 300, CV_8UC4);


    cv::Ptr<cudacodec::VideoReader> video_stream = cudacodec::createVideoReader(video_path);
    video_stream->nextFrame(capture_frame_gpu);

    VideoCapture video = VideoCapture(video_path);
    video >> outimg_from_cpu;

    s = clock();
    for (int i = 0; i < 50; ++i) {
        video_stream->nextFrame(capture_frame_gpu);
        capture_frame_gpu.download(outimg_from_gpu);
    }
    e = clock();
    cout << "gpu time: " << double(e - s) / 1000 << std::endl;

    s = clock();
    for (int i = 0; i < 50; ++i) {
        video >> outimg_from_cpu;
    }
    e = clock();
    cout << "cpu_time:" << double(e - s) / 1000 << std::endl;


    bool ret;
    char c;
    while (1) {
        ret = video_stream->nextFrame(capture_frame_gpu);
        capture_frame_gpu.download(outimg_from_gpu);
        cv::imshow("gpu", outimg_from_gpu);
        c = (char) cv::waitKey(25);
        if (c == 'q' || !ret) {
            break;
        }
    }

    video_stream.release();
    video.release();
    cv::destroyAllWindows();

    return 0;
}