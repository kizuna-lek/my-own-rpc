#include <iostream>
#include <string>
#include "user.pb.h"
#include "rpcapplication.h"
#include "rpcprovider.h"


class UserService: public fixBug::UserServiceRpc{
public:
    bool Login(std::string name, std::string pwd){
        std::cout << "doing local service Login" << std::endl;
        std::cout << "name:" << name << " pwd:" << pwd << std::endl;
        return true;
    }

    /*
    重写基类UserServiceRpc的虚函数，由框架直接调用
    1. caller ===> Login(LoginRequest) ===> muduo ===> callee
    2. callee ===> Login(LoginRequest) ===> 最后交由下面重写的函数执行
    */
    void Login(::google::protobuf::RpcController* controller,
            const ::fixBug::LoginRequest* request,
            ::fixBug::LoginResponse* response,
            ::google::protobuf::Closure* done){
        // 框架给业务上报的请求参数LoginRequest, 应用获取相应数据做本地业务
        std::string name = request->name();
        std::string pwd = request->pwd();

        // 执行本地业务 
        bool login_result = Login(name, pwd);

        // 将响应写入(错误码，错误消息，返回值)
        fixBug::ResultCode *code = response->mutable_result();
        code->set_errcode(0);
        code->set_errmsg("");
        response->set_success(login_result);

        // 执行回调, 即响应对象数据的序列化和网络发送（都应由框架实现）
        done->Run();
    }
};


int main(int argc, char **argv) {
    // 调用框架初始化
    RpcApplication::Init(argc, argv);

    // 将UserService对象发布到rpc节点
    RpcProvider provider;
    provider.NotifyService(new UserService());

    // 启动一个rpc服务发布节点, run之后进程进入阻塞状态，等待远程rpc调用
    provider.Run();

    return 0;
}