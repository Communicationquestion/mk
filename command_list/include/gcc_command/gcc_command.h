#pragma once
#include<abstraction_command/abstraction_command.h>

namespace GccCommands {
	class CGccCommand : public AbsCommand::Abs_Command
	{
	public:
		std::string  get_gcc_command();
		void set_gcc_command(const char* _gcc_command);
		int gcc_o_command();
	private:
		std::string gcc_command;
	};
}