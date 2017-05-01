#ifndef AR_SCENE_INTERFACE_H
#define AR_SCENE_INTERFACE_H

#include "ofxCvGrayscaleImage.h"
#include "ofGraphics.h"

class IArScene {
public:
    virtual void update(ofxCvGrayscaleImage &image) = 0;
    virtual void draw() = 0;
};

#endif // AR_SCENE_INTERFACE_H
