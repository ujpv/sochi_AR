#include "ofApp.h"
#include "ofxAndroidVideoGrabber.h"

#include "common/common.h"
#include "activity_manager/activity_manager.h"

//--------------------------------------------------------------

void ofApp::setup() {
    ofSetLogLevel(OF_LOG_VERBOSE);

    int w = ofGetWidth();
    int h = ofGetHeight();

    switch (ofGetOrientation()) {
    case OF_ORIENTATION_90_LEFT:
        ofLogVerbose(LOG_TAG, "Screen orientation: OF_ORIENTATION_90_LEFT: %ix%i", w, h);
        break;
    case OF_ORIENTATION_90_RIGHT:
        ofLogVerbose(LOG_TAG, "Screen orientation: OF_ORIENTATION_90_RIGHT: %ix%i", w, h);
        break;
    case OF_ORIENTATION_180:
        ofLogVerbose(LOG_TAG, "Screen orientation: OF_ORIENTATION_180: %ix%i", w, h);
        break;
    case OF_ORIENTATION_DEFAULT:
        ofLogVerbose(LOG_TAG, "Screen orientation: OF_ORIENTATION_DEFAULT: %ix%i", w, h);
        break;
    case OF_ORIENTATION_UNKNOWN:
        ofLogVerbose(LOG_TAG, "Screen orientation: OF_ORIENTATION_UNKNOWN: %ix%i", w, h);
        break;
    default:
        ofLogVerbose(LOG_TAG, "Illegal screen orientation.");
    }

    ofBackground(0, 0, 0);

    m_grabber.setVerbose(true);

    std::vector<ofVideoDevice> cameras = m_grabber.listDevices();

    std::stringstream ss;
    ss << ": Found " << cameras.size() << ". cameras list: ";
    for (ofVideoDevice &c: cameras)
        ss << c.deviceName << "; ";

    ofLogVerbose(LOG_TAG, ss.str());

    ActivityManager *activityManager = ActivityManager::make(m_grabber, w, h);

    int cameraID = ((ofxAndroidVideoGrabber *)m_grabber.getGrabber().get())->getBackCamera();
    if (cameraID == -1)
        if (cameras.size())
            cameraID = cameras.back().id;
    if (cameraID == -1) {
        activityManager->showTextActivity("No camera");
        return;
    }

    int cameraOrientation = ((ofxAndroidVideoGrabber *)m_grabber.getGrabber().get())->getCameraOrientation(cameraID);
    ofLogVerbose(LOG_TAG, "Camera orientation: %i", cameraOrientation);

    switch (cameraOrientation) {
    case 0:
        activityManager->setCameraTraslation(ofPoint(0, 0), cameraOrientation);
        m_grabber.setup(w, h);
        break;
    case 90:
        activityManager->setCameraTraslation(ofPoint(0, -w), cameraOrientation);
        m_grabber.setup(h, w);
        break;
    case 180:
        //TODO
        activityManager->setCameraTraslation(ofPoint(w, h), cameraOrientation);
        m_grabber.setup(w, h);
        break;
    case 270:
        //TODO
        activityManager->setCameraTraslation(ofPoint(0, h), cameraOrientation);
        m_grabber.setup(h, w);
        break;
    default:
        activityManager->showTextActivity("Illegal camera orientation");
        return;
    }


    ((ofxAndroidVideoGrabber *)m_grabber.getGrabber().get())->setDeviceID(cameraID);
    ((ofxAndroidVideoGrabber *)m_grabber.getGrabber().get())->setAutoFocus(true);

    activityManager->showMainCameraActivity();

    m_cameraFps.setup("Camera FPS: ", ofPoint(10, 20));
    m_screenFps.setup("Screen FPS: ", ofPoint(10, 40));
}

//--------------------------------------------------------------
void ofApp::update() {
    ActivityManager::instance()->update();

    m_cameraFps.update();
    m_screenFps.update();
    if (m_grabber.isFrameNew())
        m_cameraFps.newFrame();
}

//--------------------------------------------------------------
void ofApp::draw() {
    ActivityManager::instance()->draw();

    m_screenFps.newFrame();
    m_cameraFps.draw();
    m_screenFps.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

