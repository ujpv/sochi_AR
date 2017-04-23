#ifndef NO_CAMERA_ACTIVITY_H
#define NO_CAMERA_ACTIVITY_H

#include "ofFbo.h"
#include "ofTrueTypeFont.h"

#include "activity_manager/activity_interface.h"

class TextActivity : public IActivity
{
public:
    TextActivity(
            int height,
            int width,
            const std::string &text,
            const std::string &fontFileName = DEFAULT_FONT
            );
    void draw() override;
    void update() override;
    void start() override;
    void finish() override;
    bool isFinished() const override;

    virtual ~TextActivity() {}

private:
    static const std::string DEFAULT_FONT;

    int m_x, m_y;
    double m_scale;
    ofTrueTypeFont m_font;
    std::string m_text;
};

#endif // NO_CAMERA_ACTIVITY_H
