#ifndef SIMPLE_SCENE_H
#define SIMPLE_SCENE_H

#include "ofxFern.h"

#include "ar_scene_interface.h"

class SimpleScene : public IArScene
{
public:
    SimpleScene();
    void setup(const std::string &fileName, int width, int height);
    void update(ofxCvGrayscaleImage &image);
    void draw();
private:
    ofxFern fern;
    ofxCvGrayscaleImage m_image;
};

#endif // SIMPLE_SCENE_H
