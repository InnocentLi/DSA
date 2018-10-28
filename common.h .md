```c

#ifndef _COMMAND_H
#define _COMMAND_H

#define OPEN_DBG 1
#ifdef OPEN_DBG 
#define DBG(s) printf("s\n")
#else
#define DBG(s) 1
#endif

#include<arpa/inet.h>
#include<ctype.h>
#include<dirent.h>
#include<errno.h>
#include<fcntl.h>
#include<netdb.h>
#include<netinet/in.h>
#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<signal.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<time.h>
#include<stdarg.h>

#define MAX_SIZE 1034
#define MASTER_PORT 6666

int get_conf_value(char *pathname, char *key_name, char *value);//获取配置信息；
int socket_create(int port);//创建套接字；
int socket_accept(int sock_listen);//等待连接；
int socket_connect(int port, char *host);//建立连接；端口号，地址；
int recv_data(int sockfd, char *buf, int bufsize);//接收数据；套接字，字符串数组，大小；
int send_response(int sockfd, int req);//发送确认信息（标识码）套接字，标识码；
int recv_response(int sockfd);//接收确认信息（标识码）套接字；
int generate_logname(int code, char *logname, char *logdir);//获取文件信息，标识码，完整文件路径，文件路径；
int check_size(char *filename, int size, char *dir);//判断文件的大小，文件完整路径，大小，文件目录；
int write_Pi_log(char *PiHealthLog, const char *format, ...);//调用脚本；



#endif
```

