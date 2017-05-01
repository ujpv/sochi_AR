#include <sstream>
#include "fps_counter.h"

FpsCounter::FpsCounter()
    : m_counter(0)
    , m_fps(0)
{}

void FpsCounter::setup(const string &name, const ofPoint &pos)
{
    m_name = name;
    m_pos  = pos;
    m_stopwatch.start();
}

void FpsCounter::newFrame()
{
    ++m_counter;
}

void FpsCounter::update()
{
    if (m_stopwatch.elapsedSeconds() > 1) {
        m_stopwatch.restart();
        m_fps = m_counter;
        m_counter = 0;
    }
}

void FpsCounter::draw() const
{
    ofPushStyle();
    ofSetColor(255, 255, 255);
    std::stringstream ss;
    ss << m_name << m_fps;
    ofDrawBitmapString(ss.str(), m_pos);
    ofPopStyle();
}
