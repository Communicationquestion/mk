#include <cstring>
#include<abstraction_command/abstraction_command.h>

int AbsCommand::Abs_Command::run_cmd(const char* cmd)
{
    if(cmd == nullptr) {
        return -1;
    }

    FILE* fp = nullptr;
    char MsgBuff[1024];
    int MsgLen = sizeof(MsgBuff);

#ifdef _WIN32
    // Windows specific code
    fp = _popen(cmd, "r");
#else
    // Unix-like systems
    fp = popen(cmd, "r");
#endif

    if(fp == nullptr) {
        return -2;
    }

    // Read and print output
    while(fgets(MsgBuff, MsgLen, fp) != nullptr) {
        printf("MsgBuff: %s\n", MsgBuff);
    }

#ifdef _WIN32
    if(_pclose(fp) == -1) {
        return -3;
    }
#else
    if(pclose(fp) == -1) {
        return -3;
    }
#endif

    return 0;
}
