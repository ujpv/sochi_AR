#include "ofGraphics.h"

#include "common/common.h"
#include "text_activity.h"

#include <sstream>

const std::string TextActivity::DEFAULT_FONT = "fonts/roboto.ttf";

TextActivity::TextActivity(
        int width,
        int height,
        const std::string &text,
        const std::string &fontFileName
        )
{   
    ofLogNotice(LOG_TAG, "TextActivity::TextActivity(width = %i, height = %i, text = '%s', font = '%s')",
                 width, height, text.c_str(), fontFileName.c_str());
    m_font.load(fontFileName, 150);
    m_text = text;

    float stringHeight = m_font.stringHeight(text);
    float stringWidth  = m_font.stringWidth(text);

    m_scale = std::min(width / stringWidth, height / stringHeight) * .8;

    stringWidth  *= m_scale;
    stringHeight *= m_scale;

    m_x = (width  - stringWidth) / 2 / m_scale;
    m_y = (height + stringHeight) / 2 / m_scale;
    ofLogNotice(LOG_TAG, "TextActivity::TextActivity(m_x = %i, m_y = %i, stringWidth = %f, stringHeight = %f, scale = %f)",
                 m_x, m_y, stringWidth, stringHeight, m_scale);
}
void TextActivity::update() {  }
void TextActivity::start() {  }
void TextActivity::finish() {  }

bool TextActivity::isFinished() const { return false; }

void TextActivity::draw()
{
    ofPushMatrix();
        ofScale(m_scale, m_scale);
        ofSetColor(255, 255, 255);
        m_font.drawString(m_text, m_x, m_y);
    ofPopMatrix();
}
