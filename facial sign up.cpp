
g++ face_login.cpp -o face_login `pkg-config --cflags --libs opencv4`
./face_login

#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>
#include <iostream>
#include <fstream>

using namespace cv;
using namespace cv::face;
using namespace std;

// Preloaded face detector and recognizer model paths
const string FACE_CASCADE_PATH = "haarcascade_frontalface_default.xml";

// Function: Capture face images and store them in the training set
void captureAndStoreFaces(VideoCapture& cap, Ptr<LBPHFaceRecognizer>& faceRecognizer, int userId) {
    CascadeClassifier faceCascade;
    if (!faceCascade.load(FACE_CASCADE_PATH)) {
        cerr << "Error loading face cascade!" << endl;
        return;
    }

    Mat frame, gray;
    vector<Mat> images;
    vector<int> labels;
    int faceCount = 0;

    while (faceCount < 10) {  // collect 10 photos of face images
        cap >> frame;
        if (frame.empty()) break;

        cvtColor(frame, gray, COLOR_BGR2GRAY);
        vector<Rect> faces;
        faceCascade.detectMultiScale(gray, faces, 1.1, 3, 0, Size(100, 100));

        for (auto& face : faces) {
            Mat faceROI = gray(face);
            resize(faceROI, faceROI, Size(150, 150));

            imshow("Face Capture", faceROI);
            waitKey(500);  // display face images for 0.5 seconds

            images.push_back(faceROI);
            labels.push_back(userId);
            faceCount++;

            if (faceCount >= 10) break;
        }
    }

    faceRecognizer->train(images, labels);  // train the recognition machine
    faceRecognizer->save("face_model.yml");  // download the model
    cout << "Face data captured and stored successfully!" << endl;
}

// function: finish the facial recognition
bool recognizeFace(VideoCapture& cap, Ptr<LBPHFaceRecognizer>& faceRecognizer) {
    CascadeClassifier faceCascade;
    if (!faceCascade.load(FACE_CASCADE_PATH)) {
        cerr << "Error loading face cascade!" << endl;
        return false;
    }

    Mat frame, gray;
    while (true) {
        cap >> frame;
        if (frame.empty()) break;

        cvtColor(frame, gray, COLOR_BGR2GRAY);
        vector<Rect> faces;
        faceCascade.detectMultiScale(gray, faces, 1.1, 3, 0, Size(100, 100));

        for (auto& face : faces) {
            Mat faceROI = gray(face);
            resize(faceROI, faceROI, Size(150, 150));

            int label;
            double confidence;
            faceRecognizer->predict(faceROI, label, confidence);

            if (confidence < 50) {  // Threshold judgment, the smaller the threshold, the higher the credibility
                putText(frame, "Login Successful!", Point(50, 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 0), 2);
                imshow("Recognition", frame);
                waitKey(3000);  // stop 3 seconds after logining successfully
                return true;
            } else {
                putText(frame, "Unrecognized Face", Point(50, 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 2);
            }
        }
        imshow("Recognition", frame);
        if (waitKey(30) >= 0) break;
    }
    return false;
}

int main() {
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cerr << "Error opening camera!" << endl;
        return -1;
    }

    Ptr<LBPHFaceRecognizer> faceRecognizer = LBPHFaceRecognizer::create();

    // load it if the model already exists
    if (ifstream("face_model.yml")) {
        faceRecognizer->read("face_model.yml");
    }

    cout << "1. Capture and Register Faces" << endl;
    cout << "2. Login with Face Recognition" << endl;
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "Enter User ID: ";
        int userId;
        cin >> userId;
        captureAndStoreFaces(cap, faceRecognizer, userId);
    } else if (choice == 2) {
        if (recognizeFace(cap, faceRecognizer)) {
            cout << "Login Successful!" << endl;
        } else {
            cout << "Login Failed!" << endl;
        }
    }

    cap.release();
    destroyAllWindows();
    return 0;
}