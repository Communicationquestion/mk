#pragma once
#include<common_command/common_command.h>

int CommonCommand::CCommonCommand::explain_command(std::string _recive_string)
{
	std::cout << _recive_string << std::endl;
	return 0;
}
