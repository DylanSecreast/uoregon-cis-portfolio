#include <source.h>
#include <logging.h>
#include <iostream>

Source::Source() {
    img.SetSource(this);
}

Image *Source::GetOutput() {
    return &img;
}

void Source::Update() {
    char msg[128];
    sprintf(msg, "%s: about to execute", SourceName());
    Logger::LogEvent(msg);
    Execute();
    sprintf(msg, "%s: done executing", SourceName());
    Logger::LogEvent(msg);
}

Color::Color(int width_, int height_, unsigned char r_, unsigned char g_, unsigned char b_) {
    width = width_;
    height = height_;
    r = r_;
    g = g_;
    b = b_;
}
