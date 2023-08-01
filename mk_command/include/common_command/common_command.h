#pragma once
#include<abstraction_mk/abstraction_mk.h>
namespace CommonCommand {
	class CCommonCommand : public AbstractionMk::CAbstractionMk
	{
	public:
		virtual int MkRun() = 0;
		virtual int MkRun(std::string _receive_commands) = 0;
	private:

	};
}