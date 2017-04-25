#include "ofGraphics.h"

#include "main_camera_activity.h"

MainCameraActivity::MainCameraActivity(ofVideoGrabber &graber)
    : m_graber(graber)
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
