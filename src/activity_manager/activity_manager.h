#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include "ofVideoGrabber.h"
#include "ofTrueTypeFont.h"

#include <memory>

#include "common/common.h"
#include "activity_manager/activity_interface.h"

class ActivityManager
{
public:
    void draw();
    void update();
    void setCameraTraslation(const ofPoint &translation, int angle);
    static ActivityManager *make(ofVideoGrabber &cameraGraber, int width, int height);
    static ActivityManager *instance();

    void showActivity(std::shared_ptr<IActivity> pActivity);

    void showTextActivity(const std::string &text);
    void showMainCameraActivity();

private:
    ActivityManager(ofVideoGrabber &cameraGraber, int width, int height)
        : m_cameraGraber(cameraGraber)
        , m_width(width)
        , m_height(height)
        , m_camera_orientation(0)
    {
        ofLogNotice(LOG_TAG, "ActivityManager &m_grabber = %lu", (size_t)(&m_cameraGraber));
    }

    static ActivityManager *m_instance;

    ofVideoGrabber &m_cameraGraber;
    unsigned        m_width;
    unsigned        m_height;
    int             m_camera_orientation;
    ofPoint         m_camera_translation;

    std::vector<std::shared_ptr<IActivity> > m_activityStack;
};

#endif // SYSTEM_MANAGER_H
