#include <filter.h>
#include <logging.h>

void Filter::Update() {
    char msg[128];

    if (img1 != NULL) {
        sprintf(msg, "%s: about to update input1", FilterName());
        Logger::LogEvent(msg);
        img1->Update();
        sprintf(msg, "%s: done updating input1", FilterName());
        Logger::LogEvent(msg);
    }

    if (img2 != NULL) {
        sprintf(msg, "%s: about to update input2", FilterName());
        Logger::LogEvent(msg);
        img2->Update();
        sprintf(msg, "%s: done updating input2", FilterName());
        Logger::LogEvent(msg);
    }

    sprintf(msg, "%s: about to execute", FilterName());
    Logger::LogEvent(msg);
    Execute();
    sprintf(msg, "%s: done executing", FilterName());
    Logger::LogEvent(msg);

}   // Filter::Update

const char *Filter::SourceName() {
    return FilterName();
}

const char *Filter::SinkName() {
    return FilterName();
}
