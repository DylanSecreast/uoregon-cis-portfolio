#ifndef SINK_H
#define SINK_H

#include <image.h>

class Sink {
protected:
    const Image *img1, *img2;
public:
    Sink();
    void SetInput(const Image *i1)      { img1 = i1; }
    void SetInput2(const Image *i2)     { img2 = i2; }
    virtual const char *SinkName() = 0;
};

class CheckSum : public Sink {
protected:
    unsigned char r, g, b;
public:
    void OutputCheckSum(const char *filename_);
    const char *SinkName()  { return "CheckSum"; }
};

#endif // SINK_H
