#include "activity_manager.h"
ActivityManager *ActivityManager::m_instance = nullptr;

void ActivityManager::draw() {
    for (auto activity: m_activityStack)
        activity->draw();
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

ActivityManager *ActivityManager::make(ofVideoGrabber &cameraGraber) {
    m_instance = new ActivityManager(cameraGraber);
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
