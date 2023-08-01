#pragma once
#include<common_command/common_command.h>
class CmakeCommand :public CommonCommand::CCommonCommand
{
public:
	int MkRun();
	int MkRun(std::string _pars);

private:

};

