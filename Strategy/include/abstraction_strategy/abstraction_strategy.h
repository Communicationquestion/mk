#pragma once
#include <map>
#include <string>
#include<vector>
#include<common_command/common_command.h>
namespace AbsStratety {
	class CAbsStratry
	{
	public:
		virtual	int execute(std::string _command) = 0;
		void add(std::string _command, CommonCommand::CCommonCommand* _command_type);
		std::map < std::string, CommonCommand::CCommonCommand* > getmap();
		std::vector<std::string> separate(std::string _commands);
		std::map < std::string, CommonCommand::CCommonCommand* > name_command;
	private:
		std::vector<std::string> commands;
	};
}