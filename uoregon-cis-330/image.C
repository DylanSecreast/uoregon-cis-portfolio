#include <image.h>
#include <source.h>
#include <stdlib.h>

// Default constructor
Image::Image() {
    pixels = NULL;
    source = NULL;
    height = 0;
    width = 0;
    maxVal = 0;
    magicNum = 0;
}

// Parameterized constructor
Image::Image(Pixel *pix, int w, int h, int max, char magic) {
    pixels = pix;
    width = w;
    height = h;
    maxVal = max;
    magicNum = magic;
}

// Copy constructor
Image::Image(const Image &i) {
    height = i.height;
    width = i.width;
}

// Destructor
Image::~Image() {
    if (pixels != NULL) {
        delete [] pixels;
    }
}

void Image::Update() const {
    if (source != NULL) {
        source->Update();
    }
}
