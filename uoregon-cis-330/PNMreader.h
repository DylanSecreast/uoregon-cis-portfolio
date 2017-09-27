#ifndef PNMREADER_H
#define PNMREADER_H

#include <source.h>

class PNMreader : public Source {
protected:
    char *buffFileName;
public:
    PNMreader(char *filename);
    ~PNMreader();

    virtual void Execute();
    const char *SourceName();
};

#endif // PNMREADER_H
