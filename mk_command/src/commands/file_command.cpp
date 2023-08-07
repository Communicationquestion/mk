#include<commands/file_command.h>

int FileCreate::MkRun()
{
	return 0;
}

int FileCreate::MkRun(std::string _receive_commands)
{
	std::cout << "create " << _receive_commands << std::endl;
	return 0;
}

int FileAdd::MkRun()
{
	return 0;
}

int FileAdd::MkRun(std::string _receive_commands)
{
	std::cout << "add " << _receive_commands << std::endl;
	return 0;
}
