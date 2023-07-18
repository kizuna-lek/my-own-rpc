#pragma once
#include "rpcconfig.h"

// myrpc框架的基础类（单例模式），负责框架的初始化操作
class RpcApplication {
public:
    static void Init(int argc, char **argv);
    static RpcApplication& GetInstance();
    static RpcConfig& GetConfig();
private:
    static RpcConfig m_config;

    RpcApplication(){};
    RpcApplication(const RpcApplication&) = delete;
    RpcApplication(RpcApplication&&) = delete;
};