#include<mk_command_strategy/mk_command_strategy.h>

int MkCommandStrategy::CMKCommandStrategy::execute(std::string _command)
{
	std::cout << _command << std::endl;
	getmap()[_command]->MkRun();
	return 0;
}
