#ifndef FILTERS_H
#define FILTERS_H

#include <source.h>
#include <sink.h>
#include <filter.h>
#include <stdlib.h>


class Shrinker : public Filter {
public:
    virtual void Execute();
    virtual const char *FilterName()    { return "Shrinker"; }
};

class LRConcat : public Filter {
public:
    virtual void Execute();
    virtual const char *FilterName()    { return "LRConcat"; }
};

class TBConcat : public Filter {
public:
    virtual void Execute();
    virtual const char *FilterName()    { return "TBConcat"; }
};

class Blender : public Filter {
protected:
    float factor;
public:
    virtual void Execute();
    virtual const char *FilterName()    { return "Blender"; }
    void SetFactor(float f);
};

class Crop : public Filter {
protected:
    int Istart, Istop, Jstart, Jstop;
public:
    Crop();
    void SetRegion(int Istart_, int Istop_, int Jstart_, int Jstop_);
    virtual void Execute();
    virtual const char *FilterName()    { return "Crop"; }
};

class Transpose : public Filter {
public:
    virtual void Execute();
    virtual const char *FilterName()    { return "Transpose"; }
};

class Invert : public Filter {
public:
    virtual void Execute();
    virtual const char *FilterName()    { return "Invert"; }
};

class Checkerboard : public Filter {
public:
    virtual void Execute();
    virtual const char *FilterName()    { return "Checkerboard"; }
};


#endif // FILTERS_H
