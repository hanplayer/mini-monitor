//
// Created by root on 18-12-19.
//

#ifndef MINI_MONITOR_FILEMONITOR_H
#define MINI_MONITOR_FILEMONITOR_H
#include <string>
#include <stdio.h>
#include <string>
#include <sys/epoll.h>
#include <sys/inotify.h>
#include <iostream>
#include <unistd.h>
#include <list>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <sstream>
namespace hanplayer{
    class FileMonitor {
    public:
        FileMonitor(const char *path);
        ~FileMonitor();
        int getOneLine(std::string &info, bool flag);//这个函数在没有得到一行内容时会阻塞
    private:
        int position;//记录当前文件读取位置
        std::string path;//文件的绝对路径
    };

}
#endif //MINI_MONITOR_FILEMONITOR_H
