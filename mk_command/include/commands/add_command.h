#pragma once
#include <common_command/common_command.h>
#include <add_command/add_command.h>
class AddCommand : public CommonCommand::CCommonCommand
{
public:
	int MkRun();
	int MkRun(std::string _receive_commands);

private:
	addmodule::Add_Module modeule_test;
};
