#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include "ofVideoGrabber.h"
#include "ofTrueTypeFont.h"

#include <memory>

#include "activity/text_activity.h"
#include "activity_interface.h"

class ActivityManager
{
public:
    void draw();
    void update();
    void setCameraTraslate(const ofPoint &translate, int angle);
    static ActivityManager *make(ofVideoGrabber &cameraGraber, int width, int height);
    static ActivityManager *instance();
    void showActivity(std::shared_ptr<IActivity> pActivity);
    void showTextActivity(const std::string &text);

private:
    ActivityManager(ofVideoGrabber &cameraGraber, int width, int height)
        : m_cameraGraber(cameraGraber)
        , m_width(width)
        , m_height(height)
        , m_camera_orientation(0)
    {}

    static ActivityManager *m_instance;

    ofVideoGrabber  m_cameraGraber;
    unsigned        m_width;
    unsigned        m_height;
    int             m_camera_orientation;

    std::vector<std::shared_ptr<IActivity> > m_activityStack;
};

#endif // SYSTEM_MANAGER_H
