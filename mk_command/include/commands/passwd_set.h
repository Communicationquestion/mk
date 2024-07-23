#pragma once
#include <common_command/common_command.h>

#include<passwd_set/passwdset.h>
namespace MKRUN {

    class PasswdSet : public CommonCommand::CCommonCommand {
    public:
        PasswdSet() :passwd_set(a, b) {};
        int MkRun();
        int MkRun(std::string _receive_commands);

    private:
        int a = 0;
        char s = 's';
        char* b[1] = { &s};
        NewPasswdSet::PasswdSet passwd_set;
    };
}

