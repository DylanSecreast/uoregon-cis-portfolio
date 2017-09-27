#include <logging.h>
#include <stdio.h>
#include <fstream>

using std::endl;

ofstream Logger::logger("logger.txt");

DataFlowException::DataFlowException(const char *type, const char *error) {
    sprintf(msg, "Throwing Exception: (%s): %s", type, error);
    Logger::LogEvent(msg);
}


void Logger::LogEvent(const char *event) {
    logger << event << endl;
}

void Logger::Finalize() {
    logger.close();
}
