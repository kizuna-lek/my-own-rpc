#include "test.pb.h"
#include <iostream>
#include <string>

using namespace fixBug;

int main() {
    LoginRequest req;
    req.set_name("kizuna-lek");
    req.set_pwd("123456");

    std::string sendStr;
    if (req.SerializeToString(&sendStr)) {
        std::cout << sendStr.c_str() << std::endl;
    }

    LoginRequest reqB;
    if (req.ParseFromString(sendStr)) {
        std::cout << req.name() << std::endl;
        std::cout << req.pwd() << std::endl;
    }

    return 0;
}