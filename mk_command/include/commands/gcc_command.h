#pragma once
#include<common_command/common_command.h>
#include<gcc_command/gcc_command.h>
class GccCommandRun :public CommonCommand::CCommonCommand
{
public:
	int MkRun();
	int MkRun(std::string _receive_commands);
private:
	GccCommands::CGccCommand Gcc;
};

