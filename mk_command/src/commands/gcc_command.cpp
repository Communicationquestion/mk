#include<commands/gcc_command.h>
int GccCommandRun::MkRun()
{
	return 0;
}
int GccCommandRun::MkRun(std::string _receive_commands)
{
	std::cout << "this is Gcc command" << std::endl;
	std::string cpp_name = _receive_commands;

	std::string file_name = _receive_commands.erase(_receive_commands.length() - 4);

	std::string file_name2 = file_name.substr(2, file_name.length());

	std::string cmd = "g++ " + cpp_name + " -o " + file_name2;

	std::cout << cmd << std::endl;
	Gcc.run_cmd(cmd.c_str());
	Gcc.run_cmd(file_name2.c_str());
	return 0;
}
