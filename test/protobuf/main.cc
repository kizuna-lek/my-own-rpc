#include "test.pb.h"
#include <iostream>
#include <string>

using namespace fixBug;

int main() {
    // LoginResponse resp;
    // BaseResponse *bp = resp.mutable_base();
    // bp->set_errcode(0);
    // bp->set_errmsg("failed")

    GetFriendListsResponse resp;
    BaseResponse *bp = resp.mutable_base();
    bp->set_errcode(0);

    User *user1 = resp.add_friendlist();
    user1->set_name("kizuna-lek");
    user1->set_age(20);
    user1->set_male(User::MAN);

    User *user2 = resp.add_friendlist();
    user2->set_name("y");
    user2->set_age(22);
    user2->set_male(User::WOMAN);

    std::cout << resp.friendlist_size() << std::endl;

}

int main1() {
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