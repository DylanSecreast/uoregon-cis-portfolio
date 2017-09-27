#ifndef SOURCE_H
#define SOURCE_H

#include <image.h>

class Source {
protected:
    Image img;
    virtual void Execute() = 0;

public:
    Source();
    Image *GetOutput();
    virtual void Update();
    virtual const char *SourceName() = 0;
};

class Color : public Source {
protected:
    int width, height;
    unsigned char r, g, b;
public:
    Color(int width_, int height_, unsigned char r_, unsigned char g_, unsigned char b_);
    virtual void Execute();
    virtual const char *SourceName()    { return "Color"; }
};

#endif // SOURCE_H
