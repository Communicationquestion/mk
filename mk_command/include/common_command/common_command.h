#pragma once
#include<abstraction_mk/abstraction_mk.h>
namespace CommonCommand {
	class CCommonCommand : public AbstractionMk::CAbstractionMk
	{
	public:
		virtual int MkRun() = 0;
		int explain_command(std::string);
	private:

	};
}