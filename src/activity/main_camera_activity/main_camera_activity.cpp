#include "ofGraphics.h"

#include "common/common.h"
#include "main_camera_activity.h"

MainCameraActivity::MainCameraActivity(ofVideoGrabber &graber, const ofPoint &translation, int rotation)
    : m_grabber(graber)
    , m_cameraAngle(rotation)
    , m_cameraTranslation(translation)
{
    float width  = m_grabber.getWidth();
    float height = m_grabber.getHeight();

    ofLogNotice(LOG_TAG, "MainCameraActivity::MainCameraActivity(graber: %fx%f, translation = (%f, %f), translation = %i)",
                 width, height, translation.x, translation.y, rotation);

    m_cameraImage.allocate(width, height);
    m_grayscaleImage.allocate(width, height);

    ofLogNotice(LOG_TAG, "MainCameraActivity &m_grabber = %lu", (size_t)(&m_grabber));
}

void MainCameraActivity::draw()
{
    ofPushMatrix();
    ofRotate(m_cameraAngle);
    m_cameraImage.draw(m_cameraTranslation);
    m_grabber.draw(m_cameraTranslation);
    ofPopMatrix();
    m_grabber.videoSettings();
}

void MainCameraActivity::update()
{
    m_grabber.update();
    if (m_grabber.isFrameNew()) {
        m_cameraImage = m_grabber.getPixels();
    }
}
