//
// Created by narrow on 2021/10/21.
//

#ifndef PNP_DEMO_LOGGER_H
#define PNP_DEMO_LOGGER_H

#include <iostream>

#define LOG(level) Logger(level)

#define LOG_IF(level, flag) \
    if(!flag) \
        Logger(level)
using namespace std;

typedef enum{
    INFO,
    WARNING,
    ERROR,
} Level;

class Logger{
public:

    explicit Logger(Level level, ostream& stream_ = cout): stream(stream_){
        if(level == INFO){
            stream << "[INFO]: ";
        } else if(level == WARNING){
            stream << "[WARNING]: ";
        } else if(level == ERROR){
            stream << "[ERROR]: ";
        }
    }

    ~Logger(){
        stream << endl;
    }

    template <typename T>
    Logger& operator <<(const T& data){
        stream << data;
        return *this;
    }

private:

    ostream& stream;
};


#endif //PNP_DEMO_LOGGER_H
