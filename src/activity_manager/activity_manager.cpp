#include "activity_manager.h"
#include "common/common.h"
#include "activity/text_activity/text_activity.h"
#include "activity/main_camera_activity/main_camera_activity.h"

#include "ofGraphics.h"
ActivityManager *ActivityManager::m_instance = nullptr;

void ActivityManager::draw() {
    for (auto activity: m_activityStack)
        activity->draw();
    ofSetColor(255,0,0);
}

void ActivityManager::update() {
    for (auto it = m_activityStack.begin(); it != m_activityStack.end(); ++it) {
        if ((*it)->isFinished()) {
            for (auto it2 = it + 1; it2 != m_activityStack.end(); ++it2)
                (*it2)->finish();
            m_activityStack.erase(it, m_activityStack.end());
        } else {
            (*it)->update();
        }
    }
}

void ActivityManager::setCameraTraslation(const ofPoint &translation ,int angle)
{
    ofLogNotice(LOG_TAG, "MActivityManager::setCameraTraslation(translation = (%f, %f), angle = %i)",
                translation.x, translation.y, angle);
    m_camera_translation = translation;
    m_camera_orientation = angle;
}

ActivityManager *ActivityManager::make(ofVideoGrabber &cameraGraber, int width, int height) {
    m_instance = new ActivityManager(cameraGraber, width, height);
    return m_instance;
}

ActivityManager *ActivityManager::instance() {
    return m_instance;
}

void ActivityManager::showActivity(std::shared_ptr<IActivity> pActivity) {
    pActivity->start();
    m_activityStack.push_back(pActivity);
}

void ActivityManager::showTextActivity(const string &text) {
    showActivity(
                static_pointer_cast<IActivity>(
                    std::make_shared<TextActivity>(m_width, m_height, text)
                    )
                );
}

void ActivityManager::showMainCameraActivity()
{
    showActivity(
                static_pointer_cast<IActivity>(
                    std::make_shared<MainCameraActivity>(m_cameraGraber, m_camera_translation, m_camera_orientation)
                    )
                );
}


