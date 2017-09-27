#include <PNMreader.h>
#include <image.h>
#include <stdlib.h>
#include <string>

using std::string;

PNMreader::PNMreader(char *filename) {
    buffFileName = (char *) malloc(sizeof(filename+1));
    buffFileName = filename;
}

PNMreader::~PNMreader() {

}

const char *PNMreader::SourceName() {
    return "PNMreader";
}

void PNMreader::Execute() {
    FILE *fp = fopen(buffFileName, "rb");
    int width, height, maxVal = 0;
    char magicNum[128];

    fscanf(fp, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxVal);

    Pixel *pix = (Pixel *) malloc(sizeof(Pixel)*height*width);
    fread(pix, sizeof(Pixel), width*height, fp);

    img.ResetSize(width, height);
    img.SetMaxVal(maxVal);
    img.SetPixels(pix);

    fclose(fp);
}
