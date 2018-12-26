//
// Created by root on 18-12-19.
//

#ifndef MINI_MONITOR_PROCESSMONITOR_H
#define MINI_MONITOR_PROCESSMONITOR_H
#include "fileMonitor.h"
#include <boost/smart_ptr/shared_ptr.hpp>
#include "itc.h"
#include <stdio.h>
#include <sstream>
#include "global.h"
namespace  hanplayer{
    using namespace std;
    class ProcessMonitor {
    public:
        ProcessMonitor(int pid);
        //工作线程将关注的pid发送到itclist中
        void work();
    private:
        int pid;
        boost::shared_ptr<FileMonitor> pFMonitor;
    };
}
#endif //MINI_MONITOR_PROCESSMONITOR_H


