#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // باز کردن وب‌کم (دستگاه شماره 0)
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Webcam not found!" << std::endl;
        return -1;
    }

    // دریافت مشخصات فریم
    int frame_width = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH));
    int frame_height = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT));
    double fps = 10.0;

    // تنظیم کدک و ایجاد خروجی ویدیو
    cv::VideoWriter video("./vids/output.mkv", 
                          cv::VideoWriter::fourcc('M','J','P','G'), 
                          fps, 
                          cv::Size(frame_width, frame_height));

    if (!video.isOpened()) {
        std::cerr << "Could not open video file for writing!" << std::endl;
        return -1;
    }

    std::cout << "Recording... Press ESC to stop.\n";

    while (true) {
        cv::Mat frame;
        cap >> frame;
        if (frame.empty())
            break;

        // نمایش تصویر
        cv::imshow("Webcam", frame);

        // ذخیره تصویر در فایل ویدیو
        video.write(frame);

        // خروج با کلید ESC
        if (cv::waitKey(1) == 27) // ESC
            break;
    }

    cap.release();
    video.release();
    cv::destroyAllWindows();

    std::cout << "Recording saved to output.avi\n";
    return 0;
}
