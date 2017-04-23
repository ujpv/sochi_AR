#include "ofApp.h"
#include "ofxAndroidVideoGrabber.h"

#include "activity_manager/activity_manager.h"

//--------------------------------------------------------------
const std::string ofApp::LOG_NAME = "Sochi_AR";

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofSetOrientation(OF_ORIENTATION_90_LEFT); //?

    ActivityManager *activityManager = ActivityManager::make(m_grabber);

    ofBackground(0, 0, 0);

    std::vector<ofVideoDevice> cameras = m_grabber.listDevices();

    std::stringstream ss(LOG_NAME);
    ss << ": Found " << cameras.size() << ". cameras list: ";
    for (ofVideoDevice &c: cameras)
        ss << c.deviceName << "; ";

    ofLog(OF_LOG_VERBOSE, ss.str());

    int w = ofGetWidth();
    int h = ofGetHeight();

//    m_grabber.setPixelFormat(OF_PIXELS_RGB);
    m_grabber.setup(h, w);
    m_cameraImage.allocate(h, w);
    m_grayscaleImage.allocate(h, w);

    ofxAndroidVideoGrabber* androidGrabber = (ofxAndroidVideoGrabber *)m_grabber.getGrabber().get();
    int cameraID = androidGrabber->getBackCamera();
    if (cameraID == -1)
        if (cameras.size())
            cameraID = cameras.back().id;
    if (cameraID == -1) {
        activityManager->showTextActivity("No camera");
        return;
    }

    activityManager->showTextActivity("Test!!!!!\nTESTTTTTT!!!!!");


    androidGrabber->setDeviceID(cameraID);
    androidGrabber->setAutoFocus(true);
    m_cameraOrientation = androidGrabber->getCameraOrientation(cameraID);

//    m_fern.setup("model.bmp", ofGetHeight(), ofGetWidth());
}

//--------------------------------------------------------------
void ofApp::update() {
//    m_grabber.update();
//    if (m_grabber.isFrameNew()) {
//        m_cameraImage.setFromPixels(m_grabber.getPixels());
//        m_grayscaleImage = m_cameraImage;
//        m_fern.update(m_grayscaleImage);
//    }
    ActivityManager::instance()->update();
}

//--------------------------------------------------------------
void ofApp::draw() {
//    ofPushMatrix();
//    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
//    ofRotate(m_cameraOrientation);
//    ofSetRectMode(OF_RECTMODE_CENTER);
//    m_cameraImage.draw(0, 0, m_cameraImage.getWidth(), m_cameraImage.getHeight());
//    m_fern.draw(0, 0, ofGetHeight(), ofGetWidth());
//    ofSetColor(255);
//    if (m_fern.trackedMarker.tracked)
//        m_fern.trackedMarker.draw();
//    ofPopMatrix();
    ActivityManager::instance()->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::touchDown(int x, int y, int id) {

}

//--------------------------------------------------------------
void ofApp::touchMoved(int x, int y, int id) {

}

//--------------------------------------------------------------
void ofApp::touchUp(int x, int y, int id) {

}

//--------------------------------------------------------------
void ofApp::touchDoubleTap(int x, int y, int id) {

}

//--------------------------------------------------------------
void ofApp::touchCancelled(int x, int y, int id) {

}

//--------------------------------------------------------------
void ofApp::swipe(ofxAndroidSwipeDir swipeDir, int id) {

}

//--------------------------------------------------------------
void ofApp::pause() {

}

//--------------------------------------------------------------
void ofApp::stop() {

}

//--------------------------------------------------------------
void ofApp::resume() {

}

//--------------------------------------------------------------
void ofApp::reloadTextures() {

}

//--------------------------------------------------------------
bool ofApp::backPressed() {
    return false;
}

//--------------------------------------------------------------
void ofApp::okPressed() {

}

//--------------------------------------------------------------
void ofApp::cancelPressed() {

}

