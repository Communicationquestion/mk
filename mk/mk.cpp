#pragma once
#include "main.h"
#include<create_project/create_project.h>
#include<create_module/create_module.h>
#include<abstraction_command/abstraction_command.h>
#include<mk_command_strategy/mk_command_strategy.h>
#include<commands/cmake_command.h>
#include <gtest/gtest.h>


int main(int argc, char* argv[])
{
	//initqmlapp(argc,argv );
	std::vector<std::string> v_commands{};
	if (argc < 2) {
		printf("error\n");
		return 0;
	}
	for (int i = 1; i < argc; i++) {
		//commands = commands + argv[i];
		v_commands.push_back(argv[i]);
	}
	//v_commands.push_back("passwd");
	//std::cout << "log:" << commands << std::endl;   
	std::string _cmd = v_commands.at(0);
	MkCommandStrategy::CMKCommandStrategy test(_cmd);
	
	test.initmap();
	//test.add("cmake", new CmakeCommand);
	test.execute(v_commands);
	return 0;
}
