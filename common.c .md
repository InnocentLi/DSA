```c
#include "common.h"

int get_conf_value(char *pathname, char *key_name, char *value) {
    FILE *fp = NULL;
    //char line[];
    
    fp = fopen(pathname, "r");
    if (fp == NULL) {
        exit(-1);
    }
    
    //while ((read = getline(line, ))) 
}



int socket_create(int port) {
    int socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    /*socket(int domain, int type, int protocol) 
      domain 参数指定哪个协议用在当前套接字上；
             AF_INET   IPv4网络协议，TCP和UDP都可以用的协议
             AF_INET6  IPv6网络协议，TCP和UDP都可以用的协议
             AF_UNIX   本地通讯协议。具有高性能和低成本的IPC（进程间通讯）
      type    用于选择套接字使用的类型
             SOCK_STREAM  提供一个顺序化的、可靠的、全双工的、基于连接的字节流。支持数据传送流量控制。
                          TCP协议基于这种流式套接字
             SOCK_DGRAM    提供数据报文的支持。（无连接，不可靠、固定最大长度）UDP协议基于这种数据报文套接字
             SOCK_SEQPACKET提供一个顺序化的、可靠的、全双工的、面向连接的、固定最大长度的数据通信；
                          数据端通过接收每一个数据段来读取整个数据包
             SOCK_RAW      提供读取原始的网络协议。这种特殊的套接字可用于手工构建任意类型的协议 。一般使用这
                          个套接字来实现 ICMP 请求（例如 ping)
             SOCK_RDM      供一个可靠的数据层，但不保证到达顺序。一般的操作系统都未实现此功能。
    成功时返回 TRUE， 或者在失败时返回 FALSE。
    */
    struct sockaddr_in sock_addr = {0};//处理网络通信的地址；
    /*sockaddr 在头文件#include <sys/socketh>中定义，sockaddr的缺陷是：sa_data把目标地址和端口信息混在一起了;
     struct sockaddr {
     sa_family_t sin_family;//地址族
　　  char sa_data[14]; //14字节，包含套接字中的目标地址和端口信息               
　　 }; 
    【在本段程序中，sockaddr并不是结构体类型名，它是结构体sockaddr_in变量的名字】*/
    /*sockaddr_in在头文件#include<netinet/in.h>或#include <arpa/inet.h>中定义，该结构体解决了sockaddr的缺陷，
     把port和addr 分开储存在两个变量中;
     */
    if (socket_fd < 0) {//socket_fd < 0表示创建套接字失败；
        perror("socket_create ");
        return -1;
    }
    
    sock_addr.sin_family = AF_INET;//sin_family是地址家族
    sock_addr.sin_port = htons(port);//端口号转换成网络通用字节序；
    sock_addr.sin_addr.s_addr = INADDR_ANY;//网络地址,存储IP地址；
    
    if (bind(socket_fd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) < 0) {
        perror("bind");
        return -1;
    }
    /*服务器端要用 bind() 函数将套接字与特定的IP地址和端口绑定起来，只有这样，流经该IP地址和端口的数据才能交
      给套接字处理；而客户端要用 connect() 函数建立连接。*/

    if (listen(socket_fd, 10) < 0) {
        perror("listen");
        return -1;
    }
    /*int listen(int sockfd, int backlog);
     (1) listen() 函数的主要作用就是将套接字( sockfd )变成被动的连接监听套接字（被动等待客户端的连接），至
      于参数 backlog 的作用是设置内核中连接队列的长度
     (2) 这里需要注意的是，listen()函数不会阻塞，它主要做的事情为，将该套接字和套接字对应的连接队列长度告诉 
     Linux 内核，然后，listen()函数就结束。
    */
    return socket_fd;
}

int socket_connect(int port, char *host) {
    /*bool socket_connect ( resource $socket , string $address [, int $port = 0 ] )
     参数：
     address   如果参数 socket 是 AF_INET ， 那么参数 address 则可以是一个点分四组表示法（例如 127.0.0.1 ）
               IPv4 地址； 如果支持 IPv6 并且 socket 是 AF_INET6，那么 address也可以是有效的 IPv6 地址（例如 
               ::1）；如果套接字类型为 AF_UNIX ，那么 address 也可以是一个Unix 套接字。
     port       参数 port 仅仅用于 AF_INET 和 AF_INET6 套接字连接的时候，并且是在此情况下是需要强制说明连接对
               应的远程服务器上的端口号。
    成功时返回 TRUE， 或者在失败时返回 FALSE。
    */
    int socket_fd;
    socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socket_fd < 0) {
        perror("socket_create ");
        return -1;
    }

    struct sockaddr_in dest_addr = {0};
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(port);
    dest_addr.sin_addr.s_addr = inet_addr(host);
    
    if (connect(socket_fd, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0) {
        perror("connect"); 
        return -1;
    }
    
    return socket_fd;
}

int send_response(int socket_fd, int retcode) {//发送标识码；
    send(socket_fd, &retcode, 1, 0);
    /*int send( SOCKET s, const char FAR *buf, int len, int flags );
    不论是客户还是服务器应用程序都用send函数来向TCP连接的另一端发送数据。
    客户程序一般用send函数向服务器发送请求，而服务器则通常用send函数来向客户程序发送应答。
    （1）第一个参数指定发送端套接字描述符;
    （2）第二个参数指明一个存放应用程序要发送数据的缓冲区；
    （3）第三个参数指明实际要发送的数据的字节数；
    （4）第四个参数一般置0。
    */
    return 0;
}


int recv_response(int socket_fd) {
    int code = 0;
    recv(socket_fd, &code, 1, 0);
    /*nt recv( SOCKET s, char FAR *buf, int len, int flags );
     * 不论是客户还是服务器应用程序都用recv函数从TCP连接的另一端接收数据。
    （1）第一个参数指定接收端套接字描述符；
    （2）第二个参数指明一个缓冲区，该缓冲区用来存放recv函数接收到的数据；
    （3）第三个参数指明buf的长度；
    （4）第四个参数一般置0。
    */
    return code;
}



int generate_name(int code, char *logname, char *log_dir) {
    //获取文件信息（标识码），完整文件路径，文件目录；
    strcpy(logname, log_dir);//把文件目录拷贝到logname上；
    switch (code) {
        case 100:
            strcat(logname, "/cpu.log");//将"/cpu.log"拼接到logname上，这样logname就显示完整文件路径；
            break;
        case 101:
            strcat(logname, "/mem.log");
            break;
        case 102:
            strcat(logname, "/disk.log");
            break;
        case 103:
            strcat(logname, "/sysinfo.log");
            break;
        case 104:
            strcat(logname, "/users.log");
            break;
        case 105:
            strcat(logname, "/proclog.log");
            break;
    }
    return 0;
}
```

