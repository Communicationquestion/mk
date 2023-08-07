#pragma once
#include <map>
#include <string>
#include<vector>
#include<common_command/common_command.h>
namespace AbsStratety {
	class CAbsStratry
	{
	public:
		virtual	int execute(std::vector<std::string> v_command) = 0;
		void add(std::string _command, CommonCommand::CCommonCommand* _command_type);
		virtual void initmap() = 0;
		std::map < std::string, CommonCommand::CCommonCommand* > getmap();
		std::vector<std::string> separate(std::string _commands);
		std::map < std::string, CommonCommand::CCommonCommand* > name_command;
	private:
		std::vector<std::string> commands;
	};
}