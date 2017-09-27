#include <filters.h>
#include <logging.h>
#include <iostream>
#include <stdlib.h>

using namespace std;


void Shrinker::Execute() {
    Pixel *halfPix = NULL;
    int inWidth = 0, inHeight = 0, maxVal = 255;
    int halfWidth = 0, halfHeight = 0;

    if (img1 == NULL) {
        char msg[1024];
        sprintf(msg, "%s: no input1!", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
    }

    inWidth = img1->GetWidth();
    inHeight = img1->GetHeight();

    halfWidth = (inWidth / 2);
    halfHeight = (inHeight / 2);

    halfPix = (Pixel *) malloc(sizeof(Pixel)*halfWidth*halfHeight);

    int in = 0, out = 0;
    for (int i = 0; i < halfHeight; i++) {
        for (int j = 0; j < halfWidth; j++) {
            in = i*2*inWidth+j*2;
            out = i*halfWidth+j;
            halfPix[out] = img1->GetPixels()[in];
        }
    }

    img.ResetSize(halfWidth, halfHeight);
    img.SetMaxVal(maxVal);
    img.SetPixels(halfPix);

}   // end Shrinker::Execute()


void LRConcat::Execute() {
    Pixel *concatenate = NULL;
    int leftWidth = 0, rightWidth = 0, leftHeight = 0, rightHeight = 0;
    int finalWidth = 0, finalHeight = 0, maxVal = 255;

    if (img1 == NULL) {
        char msg[1024];
        sprintf(msg, "%s: no input1!", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
    }

    if (img2 == NULL) {
        char msg[1024];
        sprintf(msg, "%s: no input2!", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
    }

    leftWidth = img1->GetWidth();
    leftHeight = img1->GetHeight();

    rightWidth = img2->GetWidth();
    rightHeight = img2->GetHeight();

    if (leftHeight != rightHeight) {
        char msg[1024];
        sprintf(msg, "%s: heights must match: %d, %d", SinkName(), leftHeight, rightHeight);
        DataFlowException e(SinkName(), msg);
        throw e;
    }

    finalWidth = leftWidth + rightWidth;
    finalHeight = img1->GetHeight();    // left & right height are the same

    concatenate = (Pixel *) malloc(sizeof(Pixel)*finalWidth*finalHeight);

    int in = 0, out= 0;
    for (int i = 0; i < leftWidth; i++) {
        for (int j = 0; j < finalHeight; j++) {
            in = j*leftWidth+i;
            out = j*finalWidth+i;
            concatenate[out] = img1->GetPixels()[in];
        }
    }
    for (int i = 0; i < rightWidth; i++) {
        for (int j = 0; j < finalHeight; j++) {
            in = j*rightWidth+i;
            out = j*finalWidth+leftWidth+i;
            concatenate[out] = img2->GetPixels()[in];
        }
    }

    img.ResetSize(finalWidth, finalHeight);
    img.SetMaxVal(maxVal);
    img.SetPixels(concatenate);

}   // end LRConcat::Execute()


void TBConcat::Execute() {
    Pixel *concatenate = NULL;
    int topHeight = 0, topWidth = 0, bottomHeight = 0, bottomWidth = 0;
    int finalHeight = 0, finalWidth = 0, maxVal = 255;

    if (img1 == NULL) {
        char msg[1024];
        sprintf(msg, "%s: no input1!", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
    }

    if (img2 == NULL) {
        char msg[1024];
        sprintf(msg, "%s: no input2!", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
    }

    topHeight = img1->GetHeight();
    topWidth = img1->GetWidth();

    bottomHeight = img2->GetHeight();
    bottomWidth = img2->GetWidth();

    if (topWidth != bottomWidth) {
        char msg[1024];
        sprintf(msg, "%s: widths must match: %d, %d", SinkName(), topWidth, bottomWidth);
        DataFlowException e(SinkName(), msg);
        throw e;
    }

    finalHeight = topHeight + bottomHeight;
    finalWidth = img1->GetWidth();       // top & bottom width are the same

    concatenate = (Pixel *) malloc(sizeof(Pixel)*finalWidth*finalHeight);

    int in = 0, out = 0;
    for (int fw = 0; fw < finalWidth; fw++) {
        // Top image
        for (int th = 0; th < topHeight; th++) {
            in = th*topWidth+fw;
            out = th*finalWidth+fw;
            concatenate[out] = img1->GetPixels()[in];
        }
        // Bottom image
        for (int bh = 0; bh < bottomHeight; bh++) {
            in = bh*bottomWidth+fw;
            out = ((bh+topHeight)*finalWidth+fw);
            concatenate[out] = img2->GetPixels()[in];
        }
    }

    img.ResetSize(finalWidth, finalHeight);
    img.SetMaxVal(maxVal);
    img.SetPixels(concatenate);

}   // end TBConcat::Execute()


void Blender::SetFactor(float f) {
    factor = f;
}   // end Blender::SetFactor()

void Blender::Execute() {
    if (img1 == NULL) {
        char msg[1024];
        sprintf(msg, "%s: no input1!", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
    }

    if (img2 == NULL) {
        char msg[1024];
        sprintf(msg, "%s: no input2!", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
    }

    if (factor > 1.0 || factor < 0.0) {
        char msg[1024];
        sprintf(msg, "%s: Invalid factor in Blender: %f", SinkName(), factor);
        DataFlowException e(SinkName(), msg);
        throw e;
    }

    Pixel *blended = NULL;
    int width1 = 0, width2 = 0, height1 = 0, height2 = 0;
    int finalWidth = 0, finalHeight = 0, maxVal = 255, arrLocation = 0;
    float in1Factor = 0, in2Factor = 0;
    unsigned char r, g, b;

    width1 = img1->GetWidth();
    width2 = img2->GetWidth();
    finalWidth = (width1 + width2) / 2;

    height1 = img1->GetHeight();
    height2 = img2->GetHeight();
    finalHeight = (height1 + height2) /2;

    if (width1 != width2 || height1 != height2) {
        char msg[1024];
        sprintf(msg, "%s: image sizes must hatch: %d x %d, %d x %d", SinkName(), width1, height1, width2, height2);
        DataFlowException e(SinkName(), msg);
        throw e;
    }

    in1Factor = factor;
    in2Factor = 1 - factor;

    blended = (Pixel *) malloc(sizeof(Pixel)*finalWidth*finalHeight);

    for (int i = 0; i < finalHeight; i++) {
        for (int j = 0; j < finalWidth; j++) {
            arrLocation = i*finalWidth+j;

            r = (img1->GetPixels()[arrLocation].r*in1Factor) + (img2->GetPixels()[arrLocation].r*(in2Factor));
            g = (img1->GetPixels()[arrLocation].g*in1Factor) + (img2->GetPixels()[arrLocation].g*(in2Factor));
            b = (img1->GetPixels()[arrLocation].b*in1Factor) + (img2->GetPixels()[arrLocation].b*(in2Factor));

            blended[arrLocation] = img1->GetPixels()[arrLocation];
            blended[arrLocation].r = r;
            blended[arrLocation].g = g;
            blended[arrLocation].b = b;
        }
    }

    img.ResetSize(finalWidth, finalHeight);
    img.SetMaxVal(maxVal);
    img.SetPixels(blended);

}   // end Blender::Execute()


Crop::Crop() {
    Istart = Istop = Jstart = Jstop = -1;
}   // end Crop::Crop()

void Crop::SetRegion(int Istart_, int Istop_, int Jstart_, int Jstop_) {
    Istart = Istart_;
    Istop  = Istop_;
    Jstart = Jstart_;
    Jstop  = Jstop_;
}   // end Crop::SetRegion()

void Crop::Execute() {
    if (img1 == NULL) {
        char msg[1024];
        sprintf(msg, "%s: no input1!", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
    }

    if (Istart < 0 || Istop < 0 || Jstart < 0 || Jstop < 0) {
        char msg[1024];
        sprintf(msg, "%s: uninitialized region", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }

    if (Istart >= img1->GetWidth() || Istop >= img1->GetWidth()) {
        char msg[1024];
        sprintf(msg, "%s: region outside image width", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }

    if (Jstart >= img1->GetHeight() || Jstop >= img1->GetHeight()) {
        char msg[1024];
        sprintf(msg, "%s: region outside image height", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }

    if (Istop < Istart || Jstop < Jstart) {
        char msg[1024];
        sprintf(msg, "%s: invalid region", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }

    Pixel *cropped = NULL;
    int maxVal = 255;
    int height = Jstop-Jstart+1;
    int width  = Istop-Istart+1;
    int inputWidth = img1->GetWidth();

    cropped = (Pixel *) malloc(sizeof(Pixel)*width*height);

    int in = 0, out = 0;
    for (int i = Istart ; i <= Istop ; i++) {
        for (int j = Jstart ; j <= Jstop ; j++) {
            in = j*inputWidth+i;
            out = (j-Jstart)*width+(i-Istart);
            cropped[out]   = img1->GetPixels()[in];
            cropped[out+1] = img1->GetPixels()[in+1];
            cropped[out+2] = img1->GetPixels()[in+2];
        }
    }

    img.ResetSize(width, height);
    img.SetMaxVal(maxVal);
    img.SetPixels(cropped);

}   // end Crop::Execute()


void Transpose::Execute() {
    if (img1 == NULL) {
        char msg[1024];
        sprintf(msg, "%s: no input1!", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
    }

    Pixel *transposed = NULL;
    int oldWidth = 0, oldHeight = 0, newWidth = 0, newHeight = 0;
    int maxVal = 255;

    oldWidth = img1->GetWidth();
    oldHeight = img1->GetHeight();

    newWidth = oldHeight;
    newHeight = oldWidth;

    transposed = (Pixel *) malloc(sizeof(Pixel)*newWidth*newHeight);

    int in = 0, out = 0;
    for (int i = 0; i < oldHeight; i++) {
        for (int j = 0; j < oldWidth; j++) {
            in = i*oldWidth+j;
            out = j*newWidth+i;
            transposed[out] = img1->GetPixels()[in];
        }
    }

    img.ResetSize(newWidth, newHeight);
    img.SetMaxVal(maxVal);
    img.SetPixels(transposed);

}   // end Transpose::Execute()


void Invert::Execute() {
    if (img1 == NULL) {
        char msg[1024];
        sprintf(msg, "%s: no input1!", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
    }

    Pixel *inverted = NULL;
    int width = 0, height = 0, arrLocation = 0;
    int maxVal = 255;
    unsigned char r, g, b;

    width = img1->GetWidth();
    height = img1->GetHeight();

    inverted = (Pixel *) malloc(sizeof(Pixel)*width*height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            arrLocation = i*width+j;

            r = img1->GetPixels()[arrLocation].r;
            g = img1->GetPixels()[arrLocation].g;
            b = img1->GetPixels()[arrLocation].b;

            inverted[arrLocation] = img1->GetPixels()[arrLocation];
            inverted[arrLocation].r = maxVal - r;
            inverted[arrLocation].g = maxVal - g;
            inverted[arrLocation].b = maxVal - b;
        }
    }

    img.ResetSize(width, height);
    img.SetMaxVal(maxVal);
    img.SetPixels(inverted);

}   // end Invert::Execute()


void Checkerboard::Execute() {
    if (img1 == NULL) {
        char msg[1024];
        sprintf(msg, "%s: no input1!", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
    }

    if (img2 == NULL) {
        char msg[1024];
        sprintf(msg, "%s: no input2!", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
    }

    if (img1->GetWidth() != img2->GetWidth() || img1->GetHeight() != img2->GetHeight()) {
        char msg[1024];
        sprintf(msg, "%s: unequal dimensions!", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
    }

    Pixel *checker = NULL;
    int width = 0, height = 0, arrLocation = 0, maxVal = 255;

    width = img1->GetWidth();       // img1 & img2 have same width
    height = img1->GetHeight();     // img1 & img2 have same height

    checker = (Pixel *) malloc(sizeof(Pixel)*width*height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            arrLocation = i*width+j;
            if ((i/10 + j/10) %2 == 0) {
                checker[arrLocation] = img1->GetPixels()[arrLocation];
            }
            else {
                checker[arrLocation] = img2->GetPixels()[arrLocation];
            }
        }
    }

    img.ResetSize(width, height);
    img.SetMaxVal(maxVal);
    img.SetPixels(checker);

}   // end Checkerboard::Execute()


void Color::Execute() {
    if ( r < 0 || r > 255) {
        char msg[1024];
        sprintf(msg, "%s: invalid red value (0-255): %u", SourceName(), r);
        DataFlowException e(SourceName(), msg);
        throw e;
    }

    if ( g < 0 || g > 255) {
        char msg[1024];
        sprintf(msg, "%s: invalid green value (0-255): %u", SourceName(), g);
        DataFlowException e(SourceName(), msg);
        throw e;
    }

    if ( b < 0 || b > 255) {
        char msg[1024];
        sprintf(msg, "%s: invalid blue value (0-255): %u", SourceName(), b);
        DataFlowException e(SourceName(), msg);
        throw e;
    }

    Pixel *colored = NULL;
    int arrLocation = 0, maxVal = 255;

    colored = (Pixel *) malloc(sizeof(Pixel)*width*height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            arrLocation = i*width+j;
            colored[arrLocation].r = r;
            colored[arrLocation].g = g;
            colored[arrLocation].b = b;
        }
    }

    img.ResetSize(width, height);
    img.SetMaxVal(maxVal);
    img.SetPixels(colored);

}   // end Color::Color()


void CheckSum::OutputCheckSum(const char *filename) {
    if (img1 == NULL) {
        char msg[1024];
        sprintf(msg, "%s: no input1!", SinkName());
        DataFlowException e(SinkName(), msg);
        throw e;
    }

    FILE *fp = fopen(filename, "w");
    int width = 0, height = 0, arrLocation = 0;

    width = img1->GetWidth();
    height = img1->GetHeight();

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            arrLocation = i*width+j;
            r += img1->GetPixels()[arrLocation].r;
            g += img1->GetPixels()[arrLocation].g;
            b += img1->GetPixels()[arrLocation].b;
        }
    }

    fprintf(fp, "CHECKSUM: %u, %u, %u\n", r, g, b);
    fclose(fp);
}
