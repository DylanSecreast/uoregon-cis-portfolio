#ifndef IMAGE_H
#define IMAGE_H

typedef struct {
    unsigned char r, g, b;
} Pixel;

class Source;

// Base class
class Image {
private:
    Pixel *pixels;
    Source *source;
    int width, height, maxVal;
    char magicNum;

public:
    // Begin Constructors //
    Image();
    Image(Pixel *pix,int w, int h, int max, char magic);
    Image(const Image &i);
    virtual ~Image();
    // End Constructors //

    // Mutators
    void Update() const;
    void SetSource(Source *s)       { source = s; }
    void ResetSize(int w, int h)    { width = w; height = h; }
    void SetPixels(Pixel *p)        { pixels = p; }
    void SetMaxVal(int max)         { maxVal = max; }

    // Accessors
    Pixel *GetPixels() const      { return pixels; }
    int GetWidth() const          { return width;  }
    int GetHeight() const         { return height; }
    int GetMaxVal() const         { return maxVal; }

};  // end class Image

#endif // IMAGE_H
