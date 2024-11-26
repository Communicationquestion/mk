#include "main.h"
#include <abstraction_command/abstraction_command.h>
#include <commands/cmake_command.h>
#include <create_module/create_module.h>
#include <create_project/create_project.h>
#include <mk_command_strategy/mk_command_strategy.h>

int main(int argc, char* argv[]) {
	std::vector<std::string> v_commands{};
	if(argc < 2) {
		printf("error\n");
		return 0;
	}
	for(int i = 1; i < argc; i++) {
		v_commands.push_back(argv[i]);
	}
	MkCommandStrategy::CMKCommandStrategy Strategy(v_commands.at(0));
	Strategy.initmap();
	Strategy.execute(v_commands);
	return 0;
}
