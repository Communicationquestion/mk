#include<mk_command_strategy/mk_command_strategy.h>
#include<commands/cmake_command.h>
#include<commands/file_command.h>
#include<commands/gcc_command.h>
#include<commands/translate_command.h>
#include<commands/passwd_set.h>
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
	if (cmdtype == "new") {

		add("new", new FileCreate);
	}
	else if (cmdtype == "add")
	{
		add("add", new FileAdd);
	}
	else if (cmdtype == "grun")
	{
		add("grun", new GccCommandRun);
	}
	else if(cmdtype == "zhen"){
		add("zhen", new TranslateCommand("zhen"));
	}
	else if(cmdtype == "enzh")
	{
		add("enzh", new TranslateCommand("enzh"));
	}
	else if (cmdtype == "passwd") {
		add("passwd", new MKRUN::PasswdSet);
	}
	//add("trsconfig", new TranslateCommand("zhen"));
	//add("te",new tran);

}