#ifndef FPS_COUNTER_H
#define FPS_COUNTER_H

#include <string>
#include <Poco/Stopwatch.h>

#include "ofGraphics.h"

class FpsCounter
{
public:
    FpsCounter();
    void setup(const std::string &name, const ofPoint &pos);
    void newFrame();
    void update();
    void draw() const;

private:
    std::string m_name;
    ofPoint           m_pos;
    unsigned          m_counter;
    unsigned          m_fps;
    Poco::Stopwatch   m_stopwatch;
};

#endif // FPS_COUNTER_H
