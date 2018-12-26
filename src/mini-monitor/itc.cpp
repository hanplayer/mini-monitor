//
// Created by root on 18-12-19.
//
#include "itc.h"
ItcList::ItcList() :mutex(PTHREAD_MUTEX_INITIALIZER), cond(PTHREAD_COND_INITIALIZER) {}
int ItcList::push(const std::string &info) {
    pthread_mutex_lock(&mutex);
    content.push_back(info);
    pthread_cond_signal(&cond);
    //pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&mutex);
    return 0;
}

int ItcList::pop(std::string & info) {
    pthread_mutex_lock(&mutex);
    while (0 == content.size()) {
        pthread_cond_wait(&cond,&mutex);
    }
    info = content.front();
    content.pop_front();
    pthread_mutex_unlock(&mutex);
    return 0;
}

