#include "ofGraphics.h"
#include "simple_scene.h"

SimpleScene::SimpleScene()
{}

void SimpleScene::setup(const string &fileName, int width, int height)
{
    fern.setup(fileName, width, height);
}

void SimpleScene::draw()
{
    if (fern.trackedMarker.tracked) {
        ofPushStyle();
        ofSetColor(0, 255, 0);
        ofDrawCircle(50,50,50);
        ofSetColor(255, 255, 255);
        for (int i = 0; i < 4; ++i)
            ofDrawCircle(fern.trackedMarker.points[i], 20);
        ofPopStyle();
    } else
        m_image.draw(0, 0);
}

void SimpleScene::update(ofxCvGrayscaleImage &image)
{
    fern.update(image);
    m_image = image;
}
