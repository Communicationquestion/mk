#pragma once
#include <common_command/common_command.h>
class PwdManage : public CommonCommand::CCommonCommand {

public:
	int MkRun();
	int MkRun(std::string _receive_commands);

private:

};