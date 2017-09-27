#include <PNMwriter.h>
#include <iostream>

void PNMwriter::Write(char *filename) {
    FILE *fp = fopen(filename, "wb");
    int width, height, maxVal = 0;

    width = img1->GetWidth();
    height = img1->GetHeight();
    maxVal = img1->GetMaxVal();

    fprintf(fp, "%s\n%d %d\n%d\n", "P6", width, height, maxVal);
    fwrite(img1->GetPixels(), sizeof(Pixel),width*height, fp);

    fclose(fp);
}

const char *PNMwriter::SinkName() {
    return "PNMwriter";
}
