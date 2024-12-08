#include <commands/add_command.h>
int AddCommand::MkRun()
{
	std::cout << "mk new zero arge" << "\n";
	return 0;
}

int AddCommand::MkRun(std::string _receive_commands)
{
	modeule_test.init(_receive_commands);
	modeule_test.creta_files(_receive_commands,"module");
	return 0;
}
