#include<mk_command_strategy/mk_command_strategy.h>

int MkCommandStrategy::CMKCommandStrategy::execute(std::string _command)
{
	getmap()[_command]->MkRun();
	return 0;
}
