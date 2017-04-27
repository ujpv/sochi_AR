#include "ofGraphics.h"

#include "main_camera_activity.h"

MainCameraActivity::MainCameraActivity(ofVideoGrabber &graber, const ofPoint &translation, int rotation)
    : m_grabber(graber)
    , m_cameraAngle(rotation)
    , m_cameraTranslation(translation)
{

}

void MainCameraActivity::draw()
{
    ofPushMatrix();
    ofRotate(m_cameraAngle);
    ofTranslate(m_cameraTranslation);
    // TODO draw
    ofPopMatrix();
}

void MainCameraActivity::update()
{
    m_grabber.update();
    if (m_grabber.isFrameNew()) {
        m_cameraImage.setFromPixels(m_grabber.getPixels());
        m_grayscaleImage = m_cameraImage;
        m_fern.update(m_grayscaleImage);
    }
}
