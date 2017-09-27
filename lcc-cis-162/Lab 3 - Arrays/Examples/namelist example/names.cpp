#include "names.h"


Names::Names()
{
        Names(DEFAULTMAX);
}

Names::Names(int num)
{
    maxNames = num;
    numNames = 0;
    nameList = new std::string[maxNames];
}

Names::~Names()
{
    delete [] nameList;
}

bool Names::addName(std::string name)
{
    if ( numNames < maxNames )
    {
        nameList[numNames++] = name;
        return true;
    }
    return false;
}

std::string Names::listNames()
{
    std::string tempList = "";
    for ( int i = 0; i < numNames; i++ )
        tempList += nameList[i] + " ";
    return tempList;
}

int Names::howMany()
{
    return numNames;
}
