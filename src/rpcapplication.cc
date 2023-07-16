#include "rpcapplication.h"
#include <iostream>
#include <getopt.h>
#include <string>

void ShowArgsHelp() {
    std::cout << "format: command -i <configfile>" << std::endl;
}


void RpcApplication::Init(int argc, char **argv) {
    if (argc < 2) {
        ShowArgsHelp();
        exit(EXIT_FAILURE);
    }

    int c = 0;
    std::string config_file;
    while((c == getopt(argc, argv, "i:")) != -1) {
        switch(c) {
            case 'i':
                config_file = optarg;
                break;
            case '?':
                std::cout << "invalid args" << std::endl;
                ShowArgsHelp();
                break;
            case ':':
                std::cout << "need <configfile" << std::endl;
                ShowArgsHelp();
                exit(EXIT_FAILURE);
                break;
        }
    }

    // 开始加载配置文件 rpcserver_ip=  rpcserver_port=  zookeeper_ip =  zookeeper_port=

}

RpcApplication& RpcApplication::GetInstance() {
    static RpcApplication app;
    return app;
}