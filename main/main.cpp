// main.cpp: 定义应用程序的入口点。
//

#include "main.h"
#include<create_project/create_project.h>
#include<create_module/create_module.h>
#include<abstraction_command/abstraction_command.h>
int main()
{
	create_project::CreateProject test;

	test.creta_files();

	CreateModule::Create_Module modeule_test;

	modeule_test.creta_files();

	AbsCommand::Abs_Command cmd_test;

	cmd_test.run_cmd("cmake -help");

	return 0;
}
