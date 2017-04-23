#include "ofTrueTypeFont.h"
#include "ofGraphics.h"

#include "text_activity.h"

const std::string TextActivity::DEFAULT_FONT = "fonts\\Roboto-Black.ttf";

TextActivity::TextActivity(
        int width,
        int height,
        const std::string &text,
        const std::string &fontFileName
        )
{
    FBOimage.allocate(width, height, GL_RGBA);

    ofTrueTypeFont font;
    int fontSize = 10;
    font.load(fontFileName, fontSize);

    float stringHeight = font.stringHeight(text);
    float stringWidth  = font.stringWidth(text);
    float displayAspectRatio = (float)width / height;
    float textAspectRatio = (float)stringWidth / stringHeight;
    float fontSizeScale = displayAspectRatio < textAspectRatio ? width / stringWidth : height / stringHeight;
    font.load(fontFileName, fontSize * fontSizeScale * .8);
    FBOimage.begin();
        ofClear(0, 0, 0, 0.5);
        ofSetColor(255, 255, 0);
        font.drawString(text, width * .1, height * .1 + stringHeight * 0.5);
    FBOimage.end();
}
void TextActivity::update() {  }
void TextActivity::start() {  }
void TextActivity::finish() {  }

bool TextActivity::isFinished() const { return false; }

void TextActivity::draw()
{
    FBOimage.draw(0, 0);
    ofSetColor(0, 255, 0);
    ofDrawCircle(50, 50, 10);
}
