#ifndef MAIN_CAMERA_ACTIVITY_H
#define MAIN_CAMERA_ACTIVITY_H

#include "ofVideoGrabber.h"

#include "activity_manager/activity_interface.h"

class MainCameraActivity : public IActivity
{
public:
    MainCameraActivity(ofVideoGrabber &graber);
    void draw();
    void update();
    void start();
    void finish();
    bool isFinished() const;

private:
    ofVideoGrabber &m_graber;
    int             m_cameraAngle;
    ofPoint         m_cameraTranslation;

    // IActivity interface
};

#endif // MAIN_CAMERA_ACTIVITY_H
