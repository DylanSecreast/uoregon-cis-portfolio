#ifndef NAMES_H
#define NAMES_H

#include <string>

class Names{
    private:
        const static int DEFAULTMAX = 5;
        int maxNames;
        int numNames;
        std::string * nameList;

    public:
        Names();
        Names(int num);
        ~Names();
        bool addName(std::string name);
        std::string listNames();
        int howMany();
};
#endif // NAMES_H
