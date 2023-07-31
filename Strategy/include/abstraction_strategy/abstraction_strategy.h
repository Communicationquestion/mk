#pragma once
#include <map>
#include <string>
#include<common_command/common_command.h>
namespace AbsStratety {
	class CAbsStratry
	{
	public:
		virtual	int execute(std::string _command) = 0;
		void add(std::string _command, CommonCommand::CCommonCommand* _command_type);
		std::map < std::string, CommonCommand::CCommonCommand* > getmap();
	private:
		std::map < std::string, CommonCommand::CCommonCommand* > name_command;
	};
}