#pragma once
#include <common_command/common_command.h>
#include <new_command/new_command.h>
#include <add_command/add_command.h>

class NewCommand : public CommonCommand::CCommonCommand
{
public:
	int MkRun();
	int MkRun(std::string _receive_commands);

private:
    new_project::NewProject Project;
    addmodule::Add_Module modeule_Project;
};
