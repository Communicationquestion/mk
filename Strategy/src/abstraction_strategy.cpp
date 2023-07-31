#include<abstraction_strategy/abstraction_strategy.h>

void AbsStratety::CAbsStratry::add(std::string _command, CommonCommand::CCommonCommand* _command_type)
{
	name_command.insert(std::make_pair(_command, _command_type));
}

std::map<std::string, CommonCommand::CCommonCommand*> AbsStratety::CAbsStratry::getmap()
{
	return name_command;
}
