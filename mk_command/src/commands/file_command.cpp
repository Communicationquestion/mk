#include<commands/file_command.h>
#include<create_project/create_project.h>
#include<create_module/create_module.h>
int FileCreate::MkRun()
{
	return 0;
}

int FileCreate::MkRun(std::string _receive_commands)
{
	create_project::CreateProject test;

	test.creta_files(_receive_commands);

	CreateModule::Create_Module modeule_test;

	modeule_test.creta_files(_receive_commands + "\\" + _receive_commands,"project");

	return 0;
}

int FileAdd::MkRun()
{
	return 0;
}

int FileAdd::MkRun(std::string _receive_commands)
{
	std::cout << "add " << _receive_commands << std::endl;

	CreateModule::Create_Module modeule_test;

	modeule_test.creta_files(_receive_commands,"module");

	return 0;
}
