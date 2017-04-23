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
    static ActivityManager *make(ofVideoGrabber &cameraGraber);
    static ActivityManager *instance();
    void showActivity(std::shared_ptr<IActivity> pActivity);
    void showTextActivity(const std::string &text);

private:
    ActivityManager(ofVideoGrabber &cameraGraber)
        : m_cameraGraber(cameraGraber)
    {}

    static ActivityManager *m_instance;

    ofVideoGrabber  m_cameraGraber;
    unsigned        m_width;
    unsigned        m_height;

    std::vector<std::shared_ptr<IActivity> > m_activityStack;
};

#endif // SYSTEM_MANAGER_H
