#ifndef IACTIVITY_H
#define IACTIVITY_H
class IActivity {
public:
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void start() = 0;
    virtual void finish() = 0;
    virtual bool isFinished() const = 0;
    virtual ~IActivity() {}
};
#endif // IACTIVITY_H
