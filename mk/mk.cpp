

#include "main.h"
#include<create_project/create_project.h>
#include<create_module/create_module.h>
#include<abstraction_command/abstraction_command.h>
#include<mk_command_strategy/mk_command_strategy.h>
#include<commands/cmake_command.h>
int main(int argc, char* argv[])
{
	//create_project::CreateProject test;

	//test.creta_files();

	//CreateModule::Create_Module modeule_test;

	//modeule_test.creta_files();

	//AbsCommand::Abs_Command cmd_test;

	//cmd_test.run_cmd("cmake -help");
	//std::string commands{};
	std::vector<std::string> v_commands{};
	if (argc < 2) {
		printf("error\n");
		return 0;
	}
	for (int i = 1; i < argc; i++) {
		//commands = commands + argv[i];
		v_commands.push_back(argv[i]);
	}
	//std::cout << "log:" << commands << std::endl;
	MkCommandStrategy::CMKCommandStrategy test;
	test.initmap();
	//test.add("cmake", new CmakeCommand);
	test.execute(v_commands);
	return 0;
}
