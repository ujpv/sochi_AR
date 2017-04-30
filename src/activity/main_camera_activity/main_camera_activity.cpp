#include "ofGraphics.h"

#include "common/common.h"
#include "main_camera_activity.h"

MainCameraActivity::MainCameraActivity(ofVideoGrabber &graber, const ofPoint &translation, int rotation)
    : m_grabber(graber)
    , m_cameraAngle(rotation)
    , m_cameraTranslation(translation)
{
    ofLogNotice(LOG_TAG, "MainCameraActivity::MainCameraActivity(graber: %fx%f, translation = (%f, %f), translation = %i)",
                 graber.getWidth(), graber.getHeight(), translation.x, translation.y, rotation);
    m_cameraImage.allocate(m_grabber.getWidth(), m_grabber.getHeight());
}

void MainCameraActivity::draw()
{
    ofPushMatrix();
    ofRotate(m_cameraAngle);
//    m_cameraImage.draw(m_cameraTranslation);
    m_grabber.draw(m_cameraTranslation);
    ofPopMatrix();
}

void MainCameraActivity::update()
{
    m_grabber.update();
    if (m_grabber.isFrameNew()) {
        m_cameraImage = m_grabber.getPixels();
//        m_grayscaleImage = m_cameraImage;
//        m_fern.update(m_grayscaleImage);
    }
}
