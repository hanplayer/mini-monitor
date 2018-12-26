//
// Created by root on 18-12-19.
//
#include "processMonitor.h"

namespace hanplayer{
    ProcessMonitor::ProcessMonitor(int pid) {
        this->pid = pid;
        char cmd[100] = { 0 };
        sprintf(cmd, "strace -p %d -o %d.info", pid, pid); //创建一个pid.info的文件
        popen(cmd, "r");
        char filepath[20] = { 0 };
        sprintf(filepath, "./%d.info", pid);
        pFMonitor.reset(new FileMonitor(filepath));
    }

    void ProcessMonitor::work() {
        std::string buffer;
        while (true) {
            std::string info;
            buffer.clear();
            pFMonitor->getOneLine(info, true);//使用同步的方法
            std::stringstream ss;
            std::string tmp;
            ss<<pid;
            ss>>tmp;
            buffer.append(tmp);
            buffer.append("|");
            buffer.append(info);
            ItcList *p = getItc();
            p->push(buffer);
            printf("info is :%s\n",buffer.c_str());
        }
    }
}

