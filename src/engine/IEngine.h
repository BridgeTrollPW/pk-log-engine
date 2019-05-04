#ifndef IENGINE_H
#define IENGINE_H

class IEngine
{
public:
    virtual int getEngineFunction() = 0;
    virtual void prepare() = 0;
    virtual void run() = 0;
};

#endif
