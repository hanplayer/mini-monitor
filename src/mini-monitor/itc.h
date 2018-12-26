//
// Created by root on 18-12-19.
//

#ifndef MINI_MONITOR_ITC_H
#define MINI_MONITOR_ITC_H
#include <list>
#include <string>
class ItcList {
public:
    ItcList();
    int push(const std::string &info);
    int pop(std::string &info);
private:
    std::list<std::string> content;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
};

#endif //MINI_MONITOR_ITC_H
