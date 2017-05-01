#ifndef MAIN_CAMERA_ACTIVITY_H
#define MAIN_CAMERA_ACTIVITY_H

#include "ofVideoGrabber.h"
#include "ofxCvColorImage.h"
#include "ofxCvGrayscaleImage.h"

#include "activity_manager/activity_interface.h"
#include "ar_scene/simple_scene.h"

class MainCameraActivity : public IActivity
{
public:
    MainCameraActivity(ofVideoGrabber &graber, const ofPoint &translation, int rotation);
    void draw();
    void update();
    void start() {};
    void finish() {};
    bool isFinished() const {return false;}

private:
    ofVideoGrabber     &m_grabber;
    int                 m_cameraAngle;
    ofPoint             m_cameraTranslation;
    ofxCvColorImage     m_cameraImage;
    ofxCvGrayscaleImage m_grayscaleImage;

    SimpleScene scene;
    SimpleScene scene2;
};

#endif // MAIN_CAMERA_ACTIVITY_H
