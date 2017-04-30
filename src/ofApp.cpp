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

    std::vector<ofVideoDevice> cameras = m_grabber.listDevices();

    std::stringstream ss;
    ss << ": Found " << cameras.size() << ". cameras list: ";
    for (ofVideoDevice &c: cameras)
        ss << c.deviceName << "; ";

    ofLogVerbose(LOG_TAG, ss.str());

    ActivityManager *activityManager = ActivityManager::make(m_grabber, w, h);

    ofxAndroidVideoGrabber* androidGrabber = (ofxAndroidVideoGrabber *)m_grabber.getGrabber().get();
    int cameraID = androidGrabber->getBackCamera();
    if (cameraID == -1)
        if (cameras.size())
            cameraID = cameras.back().id;
    if (cameraID == -1) {
        activityManager->showTextActivity("No camera");
        return;
    }

    androidGrabber->setDeviceID(cameraID);
    androidGrabber->setAutoFocus(true);
    int cameraOrientation = androidGrabber->getCameraOrientation(cameraID);
    ofLogVerbose(LOG_TAG, "Camera orientation: %i", cameraOrientation);

    m_grabber.setPixelFormat(OF_PIXELS_MONO);
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

    activityManager->showMainCameraActivity();
    //    m_fern.setup("model.bmp", ofGetHeight(), ofGetWidth());
}

//--------------------------------------------------------------
void ofApp::update() {
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

