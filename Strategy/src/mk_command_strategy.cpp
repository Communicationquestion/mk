#include<mk_command_strategy/mk_command_strategy.h>
#include<commands/cmake_command.h>
#include<commands/file_command.h>
int MkCommandStrategy::CMKCommandStrategy::execute(std::vector<std::string> v_command)
{

	if (1 == v_command.size()) {
		getmap()[v_command.at(0)]->MkRun();
		return 0;
	}
	else if (1 < v_command.size()) {
		getmap()[v_command.at(0)]->MkRun(v_command.at(1));
		return 0;
	}
	else
	{
		std::cout << "vector is null" << std::endl;
		return 0;
	}
}
void MkCommandStrategy::CMKCommandStrategy::initmap()
{
	//add("cmake", new CmakeCommand);
	add("new", new FileCreate);
	add("add", new FileAdd);
}