#pragma once

#include "ofMain.h"
#include "ofxAndroid.h"
#include "ofxFern.h"

class ofApp : public ofxAndroidApp {

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void windowResized(int w, int h);

    void touchDown(int x, int y, int id);
    void touchMoved(int x, int y, int id);
    void touchUp(int x, int y, int id);
    void touchDoubleTap(int x, int y, int id);
    void touchCancelled(int x, int y, int id);
    void swipe(ofxAndroidSwipeDir swipeDir, int id);

    void pause();
    void stop();
    void resume();
    void reloadTextures();

    bool backPressed();
    void okPressed();
    void cancelPressed();

private:
    ofVideoGrabber m_grabber;
    ofxCvColorImage m_cameraImage;

    ofxFern m_fern;

    ofxCvGrayscaleImage m_grayscaleImage;

    int m_cameraOrientation;

//    static const std::string LOG_NAME;
};
