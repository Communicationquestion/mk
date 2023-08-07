#pragma once
#include<common_command/common_command.h>
class FileCreate :public CommonCommand::CCommonCommand
{
public:
	int MkRun();
	int MkRun(std::string _receive_commands);

private:

};
class FileAdd : public CommonCommand::CCommonCommand
{
public:
	int MkRun();
	int MkRun(std::string _receive_commands);

private:

};



