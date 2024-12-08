#include <commands/new_command.h>

int NewCommand::MkRun()
{
	return 0;
}

int NewCommand::MkRun(std::string _receive_commands)
{
    Project.init(_receive_commands);
	Project.creta_files(_receive_commands);
	fs::path project_module = fs::path(_receive_commands) / fs::path(_receive_commands);
	modeule_Project.init(_receive_commands);
	modeule_Project.creta_files(project_module.string() ,"project");
	return 0;
}
