#include<gcc_command/gcc_command.h>


std::string GccCommands::CGccCommand::get_gcc_command()
{
	std::string str = "pass";

	return str;

}

void GccCommands::CGccCommand::set_gcc_command(const char* _gcc_command)
{
	run_cmd(_gcc_command);
}

int GccCommands::CGccCommand::gcc_o_command()
{

	return 0;
}
