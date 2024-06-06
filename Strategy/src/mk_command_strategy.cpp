#include<mk_command_strategy/mk_command_strategy.h>
#include<commands/cmake_command.h>
#include<commands/file_command.h>
#include<commands/gcc_command.h>
#include<commands/translate_command.h>
int MkCommandStrategy::CMKCommandStrategy::execute(std::vector<std::string> v_command)
{

	if (1 == v_command.size()) {
		getmap()[v_command.at(0)]->MkRun();
		return 0;
	}
	else if (1 < v_command.size()) {
		std::string cmd{};
		int i = 1;
		for ( ; i < v_command.size()-1;  i++)
		{
			cmd = cmd + v_command.at(i)+" ";
		}
		cmd = cmd + v_command.at(i);
		//std::cout << "cmd  " << cmd << std::endl;
		getmap()[v_command.at(0)]->MkRun(cmd);
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
	add("grun", new GccCommandRun);
	add("zhen", new TranslateCommand("zhen"));
	add("enzh", new TranslateCommand("enzh"));
	//add("te",new tran);

}