//
// Created by root on 18-12-19.
//
#include "fileMonitor.h"

namespace hanplayer{
    FileMonitor::FileMonitor(const char *path):position(0) {
        this->path = path;
    }
    FileMonitor::~FileMonitor() {
    }
    //flag 标识此调用是同步还是异步(当前先使用同步)
    int FileMonitor::getOneLine(std::string &info, bool flag) {
        std::string content;
        int fd = open(path.c_str(),O_RDWR);
        lseek(fd,position,SEEK_SET);
        printf("path is %s,fd is %d\n",path.c_str(),fd);
        while(true){
            char tmp[2] = {0};
            int res = read(fd,tmp,1);
            if(res == -1){
                printf("errno:%d\n",errno);
                //return -1;
                exit(1);
            }
            if(tmp[0] == '\n'){
                content.append(tmp);
                info = content;
                printf("line :%s\n",content.c_str());
                content.clear();
                position++;
                int result = close(fd);
                printf("close fd %d,result is %d\n",fd,result);
                return 0;
            }else if(res == 0){
                int cl = close(fd);
                int monitor = inotify_init();
                int wd = inotify_add_watch(monitor,path.c_str(),IN_MODIFY);
                char buffer[100];
                int num = read(monitor,buffer,100);//当事件没来时可以在此处阻塞
                int ret = inotify_rm_watch(monitor,wd);
                fd = open(path.c_str(),O_RDWR);
                lseek(fd,position,SEEK_SET);
                if(fd < 0){
                    printf("file descriptor is error!\n");
                    return -1;
                }
                continue;
            }else {
                content.append(tmp);
                position++;
            }
        }
    }

}
