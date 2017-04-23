#ifndef NO_CAMERA_ACTIVITY_H
#define NO_CAMERA_ACTIVITY_H

#include "ofFbo.h"

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
    ofFbo FBOimage;
    static const std::string DEFAULT_FONT;
    ofTrueTypeFont m_font;
};

#endif // NO_CAMERA_ACTIVITY_H
